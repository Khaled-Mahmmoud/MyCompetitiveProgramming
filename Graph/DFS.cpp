// a depth-first search
#include <bits/stdc++.h>
using namespace std;
void fast()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
}
vector<vector<int>>adj;
vector<bool>vis;
void dfs(int u)
{
    vis[u] = true;
    for (int z : adj[u])
        if (!vis[z])
            dfs(z);
}
int main()
{
    fast();
    int n,m;cin>>n>>m;
    adj.resize(n+1);
    vis.resize(n+1);
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
        dfs(i);
    return 0;
}
