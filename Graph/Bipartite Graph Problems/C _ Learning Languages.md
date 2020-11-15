# Learning Languages
 
 [Problem Link](https://codeforces.com/problemset/problem/277/A)

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

# Another Solution by DSU

```cpp
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 209;
int p[N];
int find(int u)
{
    if(p[u]==u)
        return u;
    return p[u] = find(p[u]);
}
int main()
{
    ios::sync_with_stdio(false);
    int n,m,a,b,ans=0;cin>>n>>m;
    bool fg = true;
    for(int i=1;i<=n+m;i++)
        p[i] = i;
    for(int i=1;i<=n;i++)
    {
        int cnt,v;cin>>cnt;
        while(cnt--)
        {
            fg = false;
            cin>>v;v+=n;
            a = find(v);
            b = find(i);
            if(p[a]!=p[b])
                p[a] = b;
        }
    }
    for(int i=2;i<=n;i++)
    {
        a = find(i);
        b = find(1);
        if(p[a]!=p[b])
            p[a] = b,ans++;
    }
    if(fg)
        cout<<n;
    else
        cout<<ans;
    return 0;
}
```
