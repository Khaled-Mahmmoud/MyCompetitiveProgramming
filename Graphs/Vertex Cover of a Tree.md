```cpp
// A vertex cover is a set of marked vertices that covers every edge in a tree
// this means that every node or its parent is marked.
// A minimum vertex cover is a vertex cover that marks the fewest nodes.
class COVER
{
    vector<vector<int>>adj;
    int n,e,res = 0;
public:
    bool dfs(int u, int p)
    {
        bool black = false;
        for(auto v:adj[u])
            if(v!= p)
            {
                bool cur = dfs(v, u);
                if(cur)
                    black = true;
            }
        if(black)
            ++res;
        return !black;
    }
    void solve()
    {
        cin>>n>>e;
        adj.resize(n);
        while(e--)
        {
            int u,v;
            cin>>u>>v;
            u--,v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(0,-1);
        cout<<res;
    }
};
```
