# Learning Languages

```cpp
#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<vector<int>>adj;
vector<int>vis;
void dfs(int u)
{
    vis[u] = 1;
    for(auto v:adj[u])
        if(!vis[v])dfs(v);
}
int main()
{
    ios::sync_with_stdio(false);
    int n,m,cnt=0;cin>>n>>m;bool fg = true;
    adj.resize(n+m+1);
    vis.resize(n+m+1);
    for(int i=1;i<=n;i++)
    {
        int c,u;cin>>c;
        while(c--)
        {
            cin>>u;fg = false;
            adj[i].push_back(u+n);
            adj[u+n].push_back(i);
        }
    }
    for(int i=1;i<=n;i++)
    if(!vis[i])
        dfs(i),cnt++;
    if(fg)
        cout<<cnt;
    else
        cout<<cnt-1;
    return 0;
}
```
