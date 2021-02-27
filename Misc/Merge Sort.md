```CPP
cnt // the minimum number of swaps to sort array when only adjacent swapping allowed
// https://codeforces.com/gym/102892/submission/104455590
cnt // the number of inversions of ar. If i < j and ar[i] > ar[j] then the pair(i, j) is called inversion of ar.
// https://www.spoj.com/problems/INVCNT/
// O(n log n)
int cnt; 
void mergesort(int a[],int l,int mid,int r)
{
    int i=l,j=mid+1;
    int n = r-l+1;
    int temp[n],k=0;
    while(i<=mid&&j<=r)
    {
        if(a[i]<a[j])
            temp[k++] = a[i++];
        else
        {
            temp[k++] = a[j++];
            cnt += mid - i + 1;
        }
    }
    while(i<=mid)
        temp[k++] = a[i++];
    while(j<=r)
        temp[k++] = a[j++];
    for(int i=l; i<=r; i++)
        a[i] = temp[i-l];
}
void merge(int a[],int l,int r)
{
    if(l<r)
    {
        int mid = (l+r)/2;
        merge(a,l,mid);
        merge(a,mid+1,r);
        mergesort(a,l,mid,r);
    }
}
```
