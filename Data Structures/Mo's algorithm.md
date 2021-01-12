```cpp
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
void Mo()
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
}
```
