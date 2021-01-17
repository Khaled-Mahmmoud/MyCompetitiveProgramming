```cpp
// Disjoint-set data structure to tracks a set of elements partitioned
// into a number of disjoint subsets
const int N = 1000;
int p[N];
vector<int>siz;
int find(int u)
{
    if (p[u] == u)
        return u;
    return p[u] = find(p[u]);
}
// return the size of the set having the given element "u"
int get_set_size(int u)
{
    return siz[find(u)];
}
int main()
{
    int n,m;
    cin>>n>>m;
    int cnt = n; // the number of disjoint sets
    siz.resize(n);
    for (int i=0;i<n;i++)
        p[i] = i;
    while(m--)
    {
        int a,b;
        cin>>a>>b;

        a = find(a);
        b = find(b);

        if(a != b)
        {
            cnt--;
            siz[b] += siz[a];
            p[a] = b;
        }
    }
    return 0;
}
```
