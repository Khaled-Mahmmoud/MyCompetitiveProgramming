
```cpp
// https://www.youtube.com/watch?v=crzrXcaQWGY
sort(v.begin(),v.end());   // O(nlogn)

// a reverse order is possible as follows:
sort(v.rbegin(),v.rend());
sort(v.begin(),v.end(),greater<int>())


// An ordinary array a can be sorted as follows:
sort(a,a+n);  

// a reverse order is possible as follows:
sort(a,a+n,greater<int>());

// but if there 
ll a[n];
// we can sort it by:
sort(a,a+n,greater<ll>());


//sorting the string s:
sort(str.begin(), str.end());

// a reverse order is possible as follows:
sort(str.rbegin(),str.rend());          OR 
sort(str.begin(),str.end(),greater<char>())

/*
Pairs (pair) are sorted primarily according to their first elements (first).
However, if the first elements of two pairs are equal, they are sorted according to their second elements (second)
*/
vector<pair<int,int>> v;
v.push_back({1,5});
v.push_back({2,3});
v.push_back({1,2});
sort(v.begin(), v.end());
// After this, the order of the pairs is (1,2), (1,5) and (2,3).

// comparison function to the sort 
bool pred(string a, string b)
{
    return a < b;
}
sort(v.begin(), v.end(), pred);
// How to sort a pair increasing based on first element then decreasing based on second element?
bool pred(pair<int, int> a, pair<int, int> b)
{
    if (a.first != b.first)
    {
        return a.first < b.first;
    }
    return a.second > b.second;
}
vector<pair<int,int>>v;
sort(v.begin(), v.end(), pred);
// How to declare a set based on specified sorting ?
struct cmp
 {
     // notice you should to use (struct cmp, const, &)
     bool operator() (const pair<int, int> &a, const pair<int, int> &b) const  
     {
	 // code
     }
};
set<pair<int,int>,cmp>st;

// How to sort an array of structures ?
struct q
{
    int l, r;
    q() {}
    // notice you should to put < instead of (), also notice that rhs instead of b
    bool operator<(const qu &rhs) const
    {
        if(l==rhs.l)
        {
            return r > rhs.r;
        }
        return l < rhs.l;
    }
};
q a[200010];

// To sort a range[l,r] of string where 1<=l<=r<=str.size()
sort(&str[l-1], &str[r]);
sort(str.begin() + l - 1, str.begin() + r);

// Radix Sort
int n, v[100000], t[100000];
void sort()
{
    int f[10] = {};
    int p10 = 1;
    for (int it = 0; it < 10; ++it)
    {
        for (int i = 0; i < n; ++i)
            ++f[v[i] / p10 % 10];
        for (int i = 1; i < 10; ++i)
            f[i] += f[i - 1];
        for (int i = n - 1; i >= 0; --i)
            t[--f[v[i] / p10 % 10]] = v[i];
        for (int i = 0; i < n; ++i)
            v[i] = t[i];
        for (int i = 0; i < 10; ++i)
            f[i] = 0;
        p10 *= 10;
    }
}

// Minimum number of swaps required to sort an array	
int min_swaps(int arr[], int n)	
{	
    pair<int, int> arrPos[n];	
    for (int i = 0; i < n; i++)	
    {	
        arrPos[i].first = arr[i];	
        arrPos[i].second = i;	
    }	
    sort(arrPos, arrPos + n);	
    vector<bool> vis(n, false);	
    int ans = 0;	
    for (int i = 0; i < n; i++)	
    {	
        if (vis[i] || arrPos[i].second == i)	
            continue;	
        int cycle_size = 0;	
        int j = i;	
        while (!vis[j])	
        {	
            vis[j] = 1;	
            j = arrPos[j].second;	
            cycle_size++;	
        }	
        if (cycle_size > 0)	
            ans += (cycle_size - 1);	
    }	
    return ans;	
}	
// Minimum swaps to make two arrays identical	
int min_swap_2array(int a[], int b[], int n)	
{	
    map<int, int> mp;	
    for (int i = 0; i < n; i++)	
        mp[b[i]] = i;	
    for (int i = 0; i < n; i++)	
        b[i] = mp[a[i]];	
    return min_swaps(b, n);	
}
// the minimum number of swaps to sort array when only adjacent swapping allowed
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
