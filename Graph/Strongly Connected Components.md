### Strongly Connected Components

```cpp
#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;
const int N = 1e5;
int n,e,idx[N],low[N],comp[N],cmp,t;
vector<vector<int>>adj;
vector<int>s;
bool vis[N];
void dfs(int u)
{
    idx[u] = low[u] = ++t;
    s.push_back(u);
    vis[u] = true;
    for(auto &v:adj[u])
    {
        if(idx[v]==0)
           dfs(v);
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
    ios_base::sync_with_stdio(false),cin.tie(0);
    cin>>n>>e;
    adj.resize(n+1);
    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    for(int i=1;i<=n;i++)
        if(idx[i]==0)
        dfs(i);
    return 0;
}
```
