```cpp
/*
n cities form a ring. cities i and i + 1 (1 ≤ i < n) are connected by a road, as well as the cities n and 1. 
build m new roads. Each road connect two cities and be a curve which lies inside or outside the ring.
New roads will have no common points with the ring (except the endpoints of the road).
4 ≤ n ≤ 100, 1 ≤ m ≤ 100
*/
class SAT
{
    int n, e, t,cmp;
    vector<vector<int>>adj;
    vector<int> s,vis,compID,compH,idx,low;
public:
    void tarjan(int u)
    {
        idx[u] = low[u] = ++t;
        s.push_back(u);
        vis[u] = true;
        for(auto v:adj[u])
        {
            if (idx[v] == 0)
                tarjan(v);
            if (vis[v])
                low[u] = min(low[u], low[v]);
        }
        if (idx[u] == low[u])
        {
            compH[cmp] = u;
            while (true)
            {
                int v = s.back();
                s.pop_back();
                vis[v] = false;
                compID[v] = cmp;
                if (v == u)
                    break;
            }
            ++cmp;
        }
    }
    int Not(int u)
    {
        if (u >= e)
            return u - e;
        return u + e;
    }
    void add(int a, int b)
    {
        adj[Not(a)].push_back(b);
        adj[Not(b)].push_back(a);
    }
    void solve()
    {
        cin >> n >> e;
        adj.resize(2*e);
        s = vis = compID = compH = idx = low = vector<int>(sz(adj));
        t = cmp = 0;
        vector<pair<int,int>>v;
        for (int i = 0; i < e; ++i)
        {
            int from, to;
            cin >> from >> to;
            --from;--to;
            if (from > to)
                swap(from, to);
            v.push_back(make_pair(from, to));
        }
        for (int i = 0; i < e; ++i)
            for (int j = 0; j < e; ++j)
            {
                if (i == j)
                    continue;
                if (v[i].first<v[j].first && v[i].second>v[j].first && v[i].second < v[j].second)
                {
                    add(i, j);
                    add(Not(i), Not(j));
                }
            }
        for (int i = 0; i < sz(adj); ++i)
            if (idx[i] == 0)
                tarjan(i);
        for (int i = 0; i < e; ++i)
            if (compID[i] == compID[Not(i)])
            {
                cout<<"Impossible";
                return;
            }
        vector<int> assign(sz(adj), -1);
        for (int i = 0; i < cmp; ++i)
            if (assign[i] == -1)
            {
                assign[i] = true;
                assign[compID[Not(compH[i])]] = false;
            }
        for (int i = 0; i < e; ++i)
            if (assign[compID[i]])
                cout<<'o';
            else
                cout<<'i';
    }
};
```
