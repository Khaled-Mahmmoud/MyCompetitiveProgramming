# New Year Permutation

[New Year Permutation](https://codeforces.com/contest/500/problem/B)

```cpp
#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<vector<int>>adj;
vector<int>vis,group;
int cnt=0;
void dfs(int u)
{
    vis[u] = 1;
    group[u] = cnt;
    for(auto v:adj[u])
        if(!vis[v])
            dfs(v);
}
int main()
{
    ios::sync_with_stdio(false);
    int n;cin>>n;int a[n];
    adj.resize(n+1);vis.resize(n+1);group.resize(n+1);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            char c;cin>>c;
            if(c=='1');
                adj[i].push_back(j);
        }
    for(int i=1;i<=n;i++)
        if(!vis[i])dfs(i),cnt++;
    vector<set<int>>v(cnt);
    for(int i=0;i<n;i++)
        v[group[i+1]].insert(a[i]);
    for(int i=1;i<=n;i++)
    {
        cout<<*v[group[i]].begin()<<' ';
        v[group[i]].erase(v[group[i]].begin());
    }
    return 0;
}
```
