# Cover it!

[Problem Link](https://codeforces.com/contest/1176/problem/E)

```cpp
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>adj,ans;
vector<int>vis;
void dfs(int u,bool fg)
{
	vis[u] = true;
	ans[fg].push_back(u);
	for (int v : adj[u])
	    if (!vis[v]) 
		dfs(v, !fg);
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    int t;cin>>t;
    while(t--)
    {
	int n, m;
	cin>>n>>m;
        adj.resize(n+1);
        vis.resize(n+1);
        ans.resize(2);
	while(m--)
        {
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1,0);
	bool fg = (ans[1].size() <= ans[0].size());
	cout<<ans[fg].size()<< '\n';
	for(auto z:ans[fg])
	     cout<<z<< ' ';
	cout<<'\n';
	adj.clear();
	ans.clear();
	vis.clear();
    }
    return 0;
}
```
