```cpp
// BFS : Computes the shortest path between the given source node and all the other nodes in an unweighted graph.
// (Single Source Shortest Path (SSSP))
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
} // O(n+m)

// BFS on Complement of graph: Calculates the shortest path between the given source node 
// and all other nodes for the complement of the given unweighted graph. (Single Source Shortest Path (SSSP))
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
} // O(n+m)

// Multi-source BFS : calculate which colored node is the closest to the given node 
// and print the shortest distance to the closest colored node. 
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
