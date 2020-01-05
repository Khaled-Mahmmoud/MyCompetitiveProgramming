// a Breadth-First Search
#include <bits/stdc++.h>
using namespace std;
void fast()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
}
vector<vector<int>>adj;
vector<bool>vis;
void bfs(int u) 
{
    queue<int> q;
    q.push(u);
    vis[u] = true;
    while (!q.empty()) 
    {
        u = q.front();
        q.pop();
        for(int z:adj[u]) 
            if(!vis[z]) 
            {
                vis[z] = true;
                q.push(z);
            }
    }
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
      if(!vis[i])bfs(i);
    return 0;
}
