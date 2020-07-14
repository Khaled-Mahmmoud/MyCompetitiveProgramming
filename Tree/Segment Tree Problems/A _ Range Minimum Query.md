# Range Minimum Query

Given an array A of size N, there are two types of queries on this array.

1) qlr In this query you need to print the minimum in the sub-array A[L : R].
2) uxy In this query you need to update A[x] = y.

**Input** 

First line of the test case contains two integers, N and Q, size of array A and number of queries.

Second line contains N space separated integers, elements of A.

Next Q lines contain one of the two queries.

**Output**

For each type 1 query, print the minimum element in the sub-array .

**Contraints**

1 <= N , Q , y , A[i] <= 10^5

1 <= L , R , x <= N

**SAMPLE INPUT**

5 5

1 5 2 4 3

q 1 5

q 1 3

q 3 5

u 3 6

q 1 5

**SAMPLE OUTPUT**

1

1

2

1



```cpp
#include <bits/stdc++.h>
#define N 100009  // 10^5
using namespace std;
int a[N];
int tree[2 * N - 1];   // please note that number of nodes = 2*n-1
                       // there was wrong answer of tree[N] because input n may equal 10^5
void build(int node,int s,int e)
{
    if(s==e)
    {
        tree[node] = a[s];
        return;
    }
    else
    {
        int mid = (s+e)/2;
        build(2*node,s,mid);
        build(2*node+1,mid+1,e);
        tree[node] = min(tree[2*node],tree[2*node+1]);
    }
}
void updata(int node,int s,int e,int idx,int val)
{
    if(s==e)
    {
        //a[idx] = val;
        tree[node] = val;
        return;
    }

    int mid = (s+e)/2;

    if(idx<=mid)
        updata(2*node,s,mid,idx,val);
    else
        updata(2*node+1,mid+1,e,idx,val);

    tree[node] = min(tree[2*node],tree[2*node+1]);

}
int query(int node,int s,int e,int l,int r)
{
    if(s>=l&&e<=r)
        return tree[node];
    if(s>r||e<l)
        return INT_MAX;

    int mid = (s+e)/2;
    return min(query(2*node,s,mid,l,r),query(2*node+1,mid+1,e,l,r));
}
int main()
{
    int n,q;cin>>n>>q;
    for(int i=0;i<n;i++)
        cin>>a[i];
    build(1,0,n-1);
    while(q--)
    {
        char c;
        cin>>c;
        if(c=='u')
        {
            int idx,val;
            cin>>idx>>val;
            idx--;
            updata(1,0,n-1,idx,val);

        }
        else 
        {
            int l,r;
            cin>>l>>r;
            l--,r--;
            cout<<query(1,0,n-1,l,r)<<'\n';
        }

    }
    return 0;
}
```
