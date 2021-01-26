```cpp
// Undirected Graph
vector<vector<int>>adj;
vector<bool>vis;
vector<int>parent;
int cnt;
void dfs(int u,int p)
{
    if(vis[u])
    {
        cnt++;
        return;
    }
    vis[u] = true;
    for(auto v:adj[u])
        if(v!=p)
            dfs(v,u);
}
void solve()
{
    int n,m;
    cin>>n>>m;
    adj.resize(n+1);
    vis.resize(n+1);
    parent.resize(n+1);
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1; i<=n; i++)
        if(!vis[i])
            dfs(i,-1);
    if(cnt)
        cout<<"YES";
    else
        cout<<"NO";
}

// Directed Graph
vector<vector<int>>adj;
vector<int>vis;
vector<int>parent;
int cnt;
void dfs(int u)
{
    if(vis[u]==2)
        return;
    if(vis[u] == 1)
    {
		cnt++;
		return;
	}
	vis[u] = 1;
	for(auto v:adj[u])
		dfs(v);
	vis[u] = 2;
}
void solve()
{
    int n,m;
    cin>>n>>m;
    adj.resize(n+1);
    vis.resize(n+1);
    parent.resize(n+1);
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    for(int i=1; i<=n; i++)
        if(!vis[i])
            dfs(i);
    if(cnt)
        cout<<"YES";
    else
        cout<<"NO";
}
```
