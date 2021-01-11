```cpp
/*
<Sqrt Decomposition>
Sqrt Decomposition is a method (or a data structure) that allows you to perform some common operations
(finding sum of the elements of the sub-array, finding the minimal/maximal element, etc.)
in O(√n) operations, which is much faster than O(n) for the trivial algorithm
*/
const int N = 100005;
int n,q,v[N],root,bucket[N];
int main()
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
    return 0;
}
// O(q * sqrt(n))
/*
<Mo's algorithm>
A similar idea, based on sqrt decomposition, can be used to answer range queries (Q) offline in O((N+Q) * sqrt(N)).
*/
int n, t,a[200010],Z,freq[1000010];
ll res[200010];
struct qu
{
    int l, r,idx;
 
    qu() {}
    bool operator<(const qu &rhs) const
    {
        if(l/Z != rhs.l/Z)
        {
            return l < rhs.l;
        }
        return r < rhs.r;
    }
};
qu q[200010];
ll ans = 0;
void add(int idx)
{
    ans -= 1ll*freq[a[idx]]*freq[a[idx]]*a[idx];
    freq[a[idx]]++;
    ans += 1ll*freq[a[idx]]*freq[a[idx]]*a[idx];
}
void remove(int idx)
{
    ans -= 1ll*freq[a[idx]]*freq[a[idx]]*a[idx];
    freq[a[idx]]--;
    ans += 1ll*freq[a[idx]]*freq[a[idx]]*a[idx];
}
int main()
{
    cin>>n>>t;
    Z = sqrt(n)+1;
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
    }
    for (int i = 0; i < t; ++i)
    {
        cin>>q[i].l>>q[i].r;
        q[i].l--;
        q[i].r--;
        q[i].idx = i;
    }
    sort(q,q+t);
    int l = 0, r = -1;
    for (int i = 0; i < t; ++i)
    {
        while(r < q[i].r)
        {
            r++;
            add(r);
        }
        while(r > q[i].r)
        {
            remove(r);
            r--;
        }
        while(l < q[i].l)
        {
            remove(l);
            l++;
        }
        while(l > q[i].l)
        {
            --l;
            add(l);
        }
        res[q[i].idx] = ans;
    }
    for (int i = 0; i < t; ++i)
    {
        cout<<res[i]<<'\n';
    }
    return 0;
}
```
