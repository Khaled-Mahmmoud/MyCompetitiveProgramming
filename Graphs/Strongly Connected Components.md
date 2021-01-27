```cpp
class SCC
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
    void solve()
    {
        cin >> n >> e;
        adj.resize(n+1);
        s = vis = compID = compH = idx = low = vector<int>(sz(adj));
        t = cmp = 0;
        for(int i=0; i<e; i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
        }
        for(int i=1; i<=n; i++)
            if(idx[i]==0)
                tarjan(i);
    }
};
// Time Complexity O(N+E) 
// Space Requirement O(N)
```
