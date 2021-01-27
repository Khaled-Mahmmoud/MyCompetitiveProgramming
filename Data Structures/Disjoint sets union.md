```cpp
// Disjoint-set data structure to tracks a set of elements partitioned into a number of disjoint subsets
class DSU
{
    int cnt;
    vector<int> siz;
    vector<int> par;
public:
    DSU(int n)
    {
        cnt = n;// the number of disjoint sets
        siz.resize(n, 1);
        par.resize(n);
        for(int i=0;i<n;i++)
            par[i] = i;
    }
    int find_set(int u)
    {
        return u == par[u] ? u : par[u] = find_set(par[u]);
    }
    bool are_same_set(int u, int v)
    {
        return find_set(u) == find_set(v);
    }
    bool union_set(int u, int v)
    {
        u = find_set(u);
        v = find_set(v);
        if (u == v)
            return false;
        cnt--;
        siz[v] += siz[u];
        par[u] = v;
        return true;
    }
    // return the size of the set having the given element "u"
    int get_set_size(int u)
    {
        return siz[find_set(u)];
    }
    int get_set_cnt()
    {
        return cnt;
    }
};
```
