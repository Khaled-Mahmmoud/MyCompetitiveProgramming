```cpp
/*
the lowest common ancestor (LCA) of two nodes v and w in a tree or directed acyclic graph (DAG) T is the lowest node 
that has both v and w as descendants, where we define each node to be a descendant of itself 
(so if v has a direct connection from w, w is the lowest common ancestor).
*/
int n,dp[100010][18],depth[100010];
vector<int>adj[100100];
void dfs(int u, int parent)
{
    dp[u][0] = parent;
    for(auto v:adj[u])
    {
        if(v == parent)
            continue;
        depth[v] = depth[u] + 1;
        dfs(v,u);
    }
}
int lca(int u, int v)
{
    if(depth[u] < depth[v])
        swap(u,v);
    for(int k = 17 ; k >= 0 ; --k)
    {
        if(depth[u]-depth[v] >= (1<<k))
        {
            u = dp[u][k];
        }
    }
    if(u == v)
        return u;
    for(int k = 17 ; k >= 0 ; --k)
    {
        if(dp[u][k] != dp[v][k])
        {
            u = dp[u][k];
            v = dp[v][k];
        }
    }
    return dp[u][0];
}
void solve()
{
    cin>>n;
    for (int i = 0; i < n-1; ++i)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(dp,-1,sizeof dp);
    dfs(1,-1);
    for(int k = 1 ; k <= 17; ++k)
    {
        for(int u = 1 ; u <= n ; ++u)
        {
            if(dp[u][k-1] == -1)
                continue;
            dp[u][k] = dp[dp[u][k-1]][k-1];
        }
    }
    int a,b;
    cin>>a>>b;
    cout<<lca(a,b);
}
// Build Complexity : O(n.log n)
// Query Complexity : O(log n)
