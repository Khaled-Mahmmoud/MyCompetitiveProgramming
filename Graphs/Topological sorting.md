```cpp
/*
Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge uv
vertex u comes before v in the ordering. Topological Sorting for a graph is not possible if the graph is not a DAG.
*/
// DFS
vector<vector<int>>adj;
vector<bool>vis;
vector<int>result;
void dfs(int u)
{
    vis[u] = true;
    for (int z : adj[u])
        if (!vis[z])
            dfs(z);
    result.push_back(u);
}
int main()
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
    }
    for(int i=1; i<=n; i++)
        if(!vis[i])
            dfs(i);
    reverse(result.begin(),result.end());
    for(int i=0; i<result.size(); i++)
        cout<<result[i]<<' ';
    return 0;
}
// BFS
vector<vector<int>>adj;int n,m;
vector<bool>vis;vector<int>result;
void bfs()
{
    queue<int> q;
    vector<int> indeg(n + 1, 0);
    for (int i = 1; i <= n; ++i)
        for (int v : adj[i])
            ++indeg[v];
    for (int i = 1; i <= n; ++i)
        if (indeg[i] == 0)
            q.push(i);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        result.push_back(u);
        for (int v : adj[u])
            if (--indeg[v] == 0)
                q.push(v);
    }
}
int main()
{
    cin>>n>>m;
    adj.resize(n+1);
    vis.resize(n+1);
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    bfs();
    for(int i=0;i<result.size();i++)
        cout<<result[i]<<' ';
    return 0;
}
```
