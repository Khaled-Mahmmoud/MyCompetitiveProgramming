# Minimum Spanning Tree 

### Prim Algorithm

Computes the minimum/maximum spanning tree of a weighted graph.

```cpp
#include <bits/stdc++.h>
using namespace std;
const int N = 100100;
struct edge
{
    int to, weight;
    edge() {}
    edge(int t, int w) : to(t), weight(w) {}
};
struct comp
{
    bool operator()(const edge& l,const edge& r)const
    {
        return l.weight > r.weight;
        // for maximum spanning tree we used
        //  return l.weight < r.weight;
    }
};
int n,m;
int vis[N];
vector<edge> adj[N];
int primMST()
{
    priority_queue<edge,vector<edge>,comp> q;
    q.push(edge(1, 0));
    int MST = 0;
    while(!q.empty())
    {
        int u = q.top().to;
        int w = q.top().weight;
        q.pop();
        if (vis[u]++)
            continue;
        MST += w;
        for(edge& e : adj[u])
            if(!vis[e.to])
                q.push(e);
    }
    return MST;
}
int main()
{
    cin >> n >> m;
    while (m--)
    {
        int u, v, w;
        cin>>u>>v>>w;
        adj[u].push_back(edge(v, w));
        adj[v].push_back(edge(u, w));
    }
    cout<<primMST();
}
```
Complexity: O(n.log(n)+m.log(n))
