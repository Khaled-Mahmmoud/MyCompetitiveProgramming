```cpp
// Check whether a given graph is Bipartite or not
const int N = 100100;
int vis[N];           
vector<int> adj[N];   
bool dfs(int u = 1) 
{
    for(int v : adj[u]) 
    {
        if (vis[v] == vis[u]) 
            return false;
        if (vis[v] == -1) 
        {
            vis[v] = 1 - vis[u];
            if (!dfs(v)) 
                return false;
        }
    }
    return true;
}
bool isBipartiteGraph() 
{
    memset(vis, -1, sizeof(vis));
    vis[1] = 0;
    return dfs();
}
void solve()
{
    int n,m;
    cin>>n>>m;
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(isBipartiteGraph())
        cout<<"YES";
    else
        cout<<"NO";
}
```
