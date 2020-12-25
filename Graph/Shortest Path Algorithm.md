### Single Source Shortest Path (SSSP)

- BFS
- BFS on Complement Graph
- Dijkstra's Algorithm
- Bellman Ford's Algorithm
- Optimized Bellman Ford's Algorithm

### All Pair Shortest Path (APSP)

- Floyd Warshal's Algorithm

----------------------------------------------------------------------------------------------------------------------------------------------

### BFS

Computes the shortest path between the given source node and all the other nodes in an unweighted graph.
 
Complexity: O(n+m)
```cpp
const int N = 100100;
int n, m, dis[N], par[N];             
vector<int> edges[N];   
void bfs(int src) 
{
    queue<int> q;
    q.push(src);
    memset(par, -1, sizeof(par));
    memset(dis, -1, sizeof(dis));
    dis[src] = 0;
    while(!q.empty()) 
    {
        int u = q.front();q.pop();
        for(int v : edges[u]) 
            if (dis[v] == -1)
            {
                dis[v] = dis[u] + 1;
                par[v] = u;
                q.push(v);
            }
    }
}
void printPath(int v)
{
    if(~par[v]) 
        printPath(par[v]);
    cout<<v<<'\n';
}
```

### BFS on Complement of graph

Calculates the shortest path between the given source node and all other nodes for the complement of the given unweighted graph.

Complexity: O(n+m)
```cpp
const int N = 100100;
int n, dis[N], vis[N];
vector<int> adj[N];
void bfs(int src)
{
    queue<int> q;
    q.push(src);

    memset(dis, -1, sizeof(dis));
    dis[src] = 0;

    int id = 0;
    list<int> l1, l2;
    memset(vis,  0, sizeof(vis));

    for (int i = 1; i <= n; ++i)
    {
        if (i != src)
        {
            l1.push_back(i);
        }
    }

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        id++;

        for (int v : adj[u])
        {
            if (dis[v] == -1)
            {
                vis[v] = id;
            }
        }

        for (int v : l1)
        {
            if (vis[v] == id)
            {
                l2.push_back(v);
                continue;
            }

            dis[v] = dis[u] + 1;
            q.push(v);
        }

        l1.clear();
        l1.swap(l2);
    }
}
```
### Multi-source BFS
calculate which colored node is the closest to the given node and print the shortest distance to the closest colored node.
```cpp
void bfs()
{
    memset(dis,-1,sizeof(dis));
    queue<int>q;
    for(int i=1; i<=n; i++)
        if(col[i])
            q.push(i),dis[i] = 0;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(auto v:adj[u])
            if(dis[v] == -1)
            {
                dis[v] = dis[u] + 1;
                q.push(v);
            }
    }
}
```

### Dijkstra Algorithm

Computes the shortest path between the given source node and all the other nodes in non-negative weighted graph.

Complexity: O((n+m)log(n))

[Problem Link](https://codeforces.com/contest/20/problem/C)

```cpp
#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<vector<pair<int,int>>>adj;
vector<int>par;
int n,m;
ll dijkstra()
{
    vector<ll>d(n+1,1e18);
    vector<bool>vis(n+1);
    priority_queue<pair<ll,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push(make_pair(0,1));
    d[1] = 0;
    while(pq.size())
    {
        int u = pq.top().second;
        ll cost = pq.top().first;
        pq.pop();
        if(vis[u])
            continue;
        vis[u] = true;
        for(auto i:adj[u])
        {
            int v=i.first,w=i.second;
            if(d[u]+w<d[v])
            {
                d[v]=d[u]+w;
                par[v]=u;
                pq.push(make_pair(d[v],v));
            }
        }
    }
    return d[n];
}
void backtrack(int u)
{
    if(u!=1)
        backtrack(par[u]);
    cout<<u<<' ';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    adj.resize(n+1);
    par.resize(n+1);
    while(m--)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    ll k=dijkstra();
    if(k==1e18)
    {
        return cout<<-1,0;
    }
    backtrack(n);
    return 0;
}
```
