```cpp
// Connected Components (Undirected Graph)
for(int i = 1;i <= nodes;++i) 
{
    if(visited[i] == false)     
    {
         dfs(i);
         cnt_component++;
    }
}

// Strongly Connected Components (Directed Graph)
const int N = 1e5;
int n,m,idx[N],low[N],comp[N],cmp,t;
vector<vector<int>>adj;
vector<int>s;
bool vis[N];
void tarjan(int u)
{
    idx[u] = low[u] = ++t;
    s.push_back(u);
    vis[u] = true;
    for(auto &v:adj[u])
    {
        if(idx[v]==0)
           tarjan(v);
        if(vis[v])
            low[u] = min(low[u],low[v]);
    }
    if(idx[u]==low[u])
    {
        while(true)
        {
            int v = s.back();
            s.pop_back();
            vis[v] = false;
            comp[v] = cmp;
            if(v==u)
                break;
        }
        ++cmp;
    }
}
int main()
{
    cin>>n>>m;
    adj.resize(n+1);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    for(int i=1;i<=n;i++)
        if(idx[i]==0)
        tarjan(i);
    return 0;
}
// Time Complexity O(N+E) 
// Space Requirement O(N)
```
