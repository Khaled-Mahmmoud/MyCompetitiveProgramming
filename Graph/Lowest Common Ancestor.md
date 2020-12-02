### Lowest Common Ancestor

`Sparse Table`

the lowest common ancestor (LCA) of two nodes v and w in a tree or directed acyclic graph (DAG) T is the lowest (i.e. deepest) node that has both v and w as descendants, where we define each node to be a descendant of itself (so if v has a direct connection from w, w is the lowest common ancestor).
```cpp
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,a,b,dp[100010][18],depth[100010];
vector<int>adj[100100];
void dfs(int u, int parent)
{
    dp[u][0] = parent;
    for (int i = 0; i < adj[u].size(); ++i)
    {
        int v = adj[u][i];
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
        if(depth[u]-(1<<k) >= depth[v])
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
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    cin>>n;
    for (int i = 0; i < n-1; ++i)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
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
    cin>>a>>b;
    cout<<lca(a,b);
    return 0;
}
Build Complexity : O(n.log n)
Query Complexity : O(log n)
```
