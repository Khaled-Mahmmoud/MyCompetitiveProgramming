# Sum of lengths of all paths possible in a given tree

Given a tree with N nodes, the task is to find the sum of lengths of all the paths. Path length for two nodes in the tree is the number of edges on the path and for two adjacent nodes in the tree, the length of the path is 1.
```
       0
     /   \
   1      2
 /  \
3    4 
```
Paths of length 1 = (0, 1), (0, 2), (1, 3), (1, 4) = 4

Paths of length 2 = (0, 3), (0, 4), (1, 2), (3, 4) = 4

Paths of length 3 = (3, 2), (4, 2) = 2

The sum of lengths of all paths = (4 * 1) + (4 * 2) + (2 * 3) = 18

```cpp
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,a,b,sz[100001];
vector<int>g[100001];
long long ans = 0;
void dfs(int u=1, int p=-1)
{
	sz[u] = 1;
	for(int i = 0; i < g[u].size(); ++i)
    {
		int v = g[u][i];
		if(v == p)
		    continue;
		dfs(v,u);
		sz[u] += sz[v];
	}
	if(u != 1)
		ans += 1ll*sz[u]*(n-sz[u]);
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    cin>>n;
	for (int i = 0; i < n-1; ++i)
    {
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs();
	cout<<ans<<endl;
    return 0;
}
```
