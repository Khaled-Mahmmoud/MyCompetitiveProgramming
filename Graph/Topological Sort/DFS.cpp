/*Topological Sorting
Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge uv
vertex u comes before v in the ordering. Topological Sorting for a graph is not possible if the graph is not a DAG*/
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>adj;
vector<bool>vis;vector<int>result;
void toposordfs(int u)
{
    vis[u] = true;
    for (int z : adj[u])
        if (!vis[z])
            dfs(z);
    result.push_back(u);
}
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,m;cin>>n>>m;
    adj.resize(n+1);
    vis.resize(n+1);
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    for(int i=1;i<=n;i++)
    if(!vis[i])toposordfs(i);
    reverse(result.begin(),result.end());
    for(int i=0;i<result.size();i++)
        cout<<result[i]<<' ';
    return 0;
}
