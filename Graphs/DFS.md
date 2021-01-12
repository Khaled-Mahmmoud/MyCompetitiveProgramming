```cpp
// Depth-First Search (DFS)
vector<vector<int>>adj;
vector<bool>vis;
void dfs(int u)
{
    vis[u] = true;
    for (int v : adj[u])
        if (!vis[v])
            dfs(v);
}
void solve()
{
    int n,m;
    cin>>n>>m;
    adj.resize(n+1);
    vis.resize(n+1);
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1; i<=n; i++)
        if(!vis[i])
            dfs(i);
}// O(V + E)
```
