### How to determine the level of each node in the given tree?
```cpp
vector<vector<int>>adj;
vector<bool>vis;
void bfs(int u,int level)
{
    queue<pair<int,int>>q;
    q.push({u,level});
    while(!q.empty())
    {
        u = q.front().first;
        level = q.front().second;
        vis[u] = true;
        cout<<u<<' '<<level<<endl;
        q.pop();
        for(int v:adj[u])
          if(!vis[v])
            q.push({v,level+1});
    }
}
int main()
{
    int n;
    cin>>n;
    adj.resize(n+1);
    vis.resize(n+1);
    n--;
    while(n--)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(1,0);
    return 0;
}
```

### How to find connected components using DFS?

A graph is said to be disconnected if it is not connected, i.e. if two nodes exist in the graph such that there is no edge in between those nodes. In an undirected graph, a connected component is a set of vertices in a graph that are linked to each other by paths.

In DFS, if we start from a start node it will mark all the nodes connected to the start node as visited. Therefore, if we choose any node in a connected component and run DFS on that node it will mark the whole connected component as visited.

```cpp
for(int i = 1;i <= nodes;++i) 
{
    if(visited[i] == false)     
    {
         dfs(i);
         cnt_component++;
    }
}
```
### How to Check if an undirected graph has cycle ?
```cpp
vector<vector<int>>adj;
vector<bool>vis;
vector<int>parent;
int cnt;
void dfs(int u)
{
    vis[u] = 1;
    for(auto v:adj[u])
    if(vis[v])
    {
        if(parent[u]!=v)
            cnt++;
    }
    else
    {
        parent[v] = u;
        dfs(v);
    }
}
int main()
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
    if(!vis[i])dfs(i);

    if(cnt)cout<<"YES";
    else cout<<"NO";
    
    return 0;
}
```
### Maximum number of edges removed
Calculate maximum number of edges that can be removed from the graph so that it contains exactly K connected components.
```cpp
vector<vector<int>>adj;
vector<bool>vis;
vector<int>parent;
int cnt;
void dfs(int u)
{
    vis[u] = 1;
    for(auto v:adj[u])
    if(vis[v])
    {
        if(parent[u]!=v)
            cnt++;
    }
    else
    {
        parent[v] = u;
        dfs(v);
    }
}
int main()
{
    int n,m,k,cnt_component=0;
    cin>>n>>m>>k;
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
    {
        dfs(i);
        cnt_component++;
    }
    if(cnt_component>k)
        cout<<-1;
    else
    {
        cnt = cnt/2;
        cout<<cnt+(k-cnt_component);
    }
    return 0;
}
```
**Remove edges from the graph**
```cpp
void dfs(int u)
{
    vis[u] = 1;
    vector<int>newadj;
    for(auto v:adj[u])
    if(vis[v])
    {
        if(parent[u]!=v)
            cnt++;
        else
            newadj.push_back(v);
    }
    else
    {
        parent[v] = u;
        newadj.push_back(v);
        dfs(v);
    }
    adj[u] = newadj;
}
```

### Sum of lengths of all paths possible in a given tree
```cpp
int n,a,b,sz[100001];
vector<int>g[100001];
long long ans = 0;
void dfs(int u=1, int p=-1)
{
    sz[u] = 1;
    for(int i = 0; i < g[u].size(); ++i)
    {
        int v = g[u][i];
        if(v == p)
            continue;
        dfs(v,u);
        sz[u] += sz[v];
    }
    if(u != 1)
        ans += 1ll*sz[u]*(n-sz[u]);
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    cin>>n;
    for (int i = 0; i < n-1; ++i)
    {
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs();
    cout<<ans<<endl;
    return 0;
}
```