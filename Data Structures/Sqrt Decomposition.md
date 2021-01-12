```cpp
const int N = 100005;
int n,q,v[N],root,bucket[N];
void Sqrt()
{
    cin>>n;
    root=sqrt(n);
    for(int i=0; i<n; ++i)
        cin>>v[i];
    for(int i=0; i<n; ++i)
    {
        if(i%root==0)
            bucket[i/root]=v[i];
        else
            bucket[i/root]=min(bucket[i/root], v[i]);
    }
    cin>>q;
    for(int l,r,i=0; i<q; ++i)
    {
        cin>>l>>r;
        int ans=1e9;
        for(int j=l; j<=r; ++j)
        {
            if(j%root==0 && j+root-1<=r)
            {
                ans=min(ans, bucket[j/root]);
                j+=root-1;
            }
            else
                ans=min(ans, v[j]);
        }
        cout<<ans<<'\n';
    }
} // O(q * sqrt(n))
```
