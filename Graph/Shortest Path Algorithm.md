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
### Dijkstra Algorithm

Computes the shortest path between the given source node and all the other nodes in a weighted graph.

Complexity: O((n+m)log(n))

[Problem Link](https://codeforces.com/contest/20/problem/C)

```cpp
vector<vector<pair<int,int>>>adj;
vector<int>par;
int n,m;
long long dijkstra()
{
    vector<long long>d(n+1,1e18);
    vector<bool>vis(n+1);
    deque<int>dq;
    dq.push_front(1);
    vis[1]=true;
    d[1]=0;
    while(dq.size())
    {
        int u=dq.front();
        dq.pop_front();
        vis[u]=0;
        for(auto i:adj[u])
        {
            int v=i.first,w=i.second;
            if(d[u]+w<d[v])
            {
                d[v]=d[u]+w;
                par[v]=u;
                if(!vis[v])
                    dq.push_front(v);
                vis[v]=true;
                if(d[dq.front()]>d[dq.back()])
                {
                    int k=dq.front();
                    dq.pop_front();
                    dq.push_back(k);
                }
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
using namespace std;
int main()
{
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
    long long k=dijkstra();
    if(k==1e18)
        return cout<<-1,0;
    backtrack(n);
    return 0;
}
```
