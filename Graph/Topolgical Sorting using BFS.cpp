/*Topological Sorting
Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge uv
vertex u comes before v in the ordering. Topological Sorting for a graph is not possible if the graph is not a DAG*/
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>adj;int n,m;
vector<bool>vis;vector<int>result;
void toposorbfs()
{
    queue<int> q;
    vector<int> indeg(n + 1, 0);
    for (int i = 1; i <= n; ++i)
        for (int v : adj[i])
            ++indeg[v];
    for (int i = 1; i <= n; ++i)
        if (indeg[i] == 0)
            q.push(i);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        result.push_back(u);
        for (int v : adj[u])
            if (--indeg[v] == 0)
                q.push(v);
    }
}
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    adj.resize(n+1);
    vis.resize(n+1);
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    toposorbfs();
    for(int i=0;i<result.size();i++)
        cout<<result[i]<<' ';
    return 0;
}
