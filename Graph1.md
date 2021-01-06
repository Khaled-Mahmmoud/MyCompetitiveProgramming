```cpp
// Lowest Common Ancestor
/*
the lowest common ancestor (LCA) of two nodes v and w in a tree or directed acyclic graph (DAG) T is the lowest node 
that has both v and w as descendants, where we define each node to be a descendant of itself 
(so if v has a direct connection from w, w is the lowest common ancestor).
*/
int n,a,b,dp[100010][18],depth[100010];
vector<int>adj[100100];
void dfs(int u, int parent)
{
    dp[u][0] = parent;
    for(auto v:adj[u])
    {
        if(v == parent)
            continue;
        depth[v] = depth[u] + 1;
        dfs(v,u);
    }
}
int lca(int u, int v)
{
    if(depth[u] < depth[v])
        swap(u,v);
    for(int k = 17 ; k >= 0 ; --k)
    {
        if(depth[u]-(1<<k) >= depth[v])
        {
            u = dp[u][k];
        }
    }
    if(u == v)
        return u;
    for(int k = 17 ; k >= 0 ; --k)
    {
        if(dp[u][k] != dp[v][k])
        {
            u = dp[u][k];
            v = dp[v][k];
        }
    }
    return dp[u][0];
}
int main()
{
    cin>>n;
    for (int i = 0; i < n-1; ++i)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(dp,-1,sizeof dp);
    dfs(1,-1);
    for(int k = 1 ; k <= 17; ++k)
    {
        for(int u = 1 ; u <= n ; ++u)
        {
            if(dp[u][k-1] == -1)
                continue;
            dp[u][k] = dp[dp[u][k-1]][k-1];
        }
    }
    cin>>a>>b;
    cout<<lca(a,b);
    return 0;
}
// Build Complexity : O(n.log n)
// Query Complexity : O(log n)

// Prim Algorithm (Minimum Spanning Tree)
// Computes the minimum/maximum spanning tree of a weighted graph.
const int N = 100100;
struct edge
{
    int to, weight;
    edge() {}
    edge(int t, int w) : to(t), weight(w) {}
};
struct comp
{
    bool operator()(const edge &l,const edge &r)const
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
    priority_queue<edge,vector<edge>,comp> pq;
    pq.push(edge(1, 0));
    int MST = 0;
    while(!pq.empty())
    {
        int u = pq.top().to;
        int w = pq.top().weight;
        pq.pop();
        if (vis[u]++)
            continue;
        MST += w;
        for(edge& e : adj[u])
            if(!vis[e.to])
                pq.push(e);
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
// O(n.log(n)+m.log(n))
/*
Single Source Shortest Path (SSSP)
BFS - BFS on Complement Graph - Dijkstra's Algorithm
Bellman Ford's Algorithm - Optimized Bellman Ford's Algorithm

All Pair Shortest Path (APSP) - Floyd Warshal's Algorithm
*/
// BFS : Computes the shortest path between the given source node and all the other nodes in an unweighted graph.
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
// Complexity: O(n+m)

// BFS on Complement of graph: Calculates the shortest path between the given source node 
// and all other nodes for the complement of the given unweighted graph.
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
// Complexity: O(n+m)

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

// Dijkstra Algorithm : Computes the shortest path between the given source node
/ and all the other nodes in non-negative weighted graph.
vector<vector<pair<int,int>>>adj;
vector<int>par;
int n,m;
ll dijkstra()
{
    vector<ll>d(n+1,1e18);
    set<pair<ll,int>>st;
    st.insert(make_pair(0,1));
    d[1] = 0;
    while(st.size())
    {
        int u = st.begin()->second;
        ll cost = st.begin()->first;
        st.erase(st.begin());
        for(auto i:adj[u])
        {
            int v = i.first,w = i.second;
            if(d[v] > d[u]+w)
            {
                st.erase(make_pair(d[v],v));
                d[v] = d[u]+w;
                par[v] = u;
                st.insert(make_pair(d[v],v));
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
// Complexity: O((n+m)log(n))

// The Diameter of a tree is the number of nodes on the longest path between two leaves in the tree. 
const int N = 100100;
int n,m;                  
int dis[N];             
int par[N];             
vector<int> edges[N];   
void bfs(int u) 
{
    queue<int> q;
    q.push(u);
    memset(par, -1, sizeof(par));
    memset(dis, -1, sizeof(dis));
    dis[u] = 0;
    while(!q.empty()) 
    {
        u = q.front();q.pop();
        for(int v : edges[u]) 
            if (dis[v] == -1)
            {
                dis[v] = dis[u] + 1;
                par[v] = u;
                q.push(v);
            }
    }
    return u;
}
int calcTreeDiameter(int root) 
{
    int u = bfs(root);
    int v = bfs(u);
    printPath(v);
    return dis[v];
}
void printPath(int v)
{
    if(~par[v]) 
        printPath(par[v]);
    cout<<v<<'\n';
}
// Complexity: O(n+m)

// Strongly Connected Components
const int N = 1e5;
int n,e,idx[N],low[N],comp[N],cmp,t;
vector<vector<int>>adj;
vector<int>s;
bool vis[N];
void dfs(int u)
{
    idx[u] = low[u] = ++t;
    s.push_back(u);
    vis[u] = true;
    for(auto &v:adj[u])
    {
        if(idx[v]==0)
           dfs(v);
        if(vis[v])
            low[u] = min(low[u],low[v]);
    }
    if(idx[u]==low[u])
    {
        while(true)
        {
            int v = s.back();
            s.pop_back();
            vis[v] = false;
            comp[v] = cmp;
            if(v==u)
                break;
        }
        ++cmp;
    }
}
int main()
{
    cin>>n>>e;
    adj.resize(n+1);
    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    for(int i=1;i<=n;i++)
        if(idx[i]==0)
        dfs(i);
    return 0;
}
/*
Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge uv
vertex u comes before v in the ordering. Topological Sorting for a graph is not possible if the graph is not a DAG.
*/
// DFS
vector<vector<int>>adj;
vector<bool>vis;
vector<int>result;
void toposordfs(int u)
{
    vis[u] = true;
    for (int z : adj[u])
        if (!vis[z])
            dfs(z);
    result.push_back(u);
}
int main()
{
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
// BFS
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
int main()
{
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
/*
<Euler Theory>
Euler Path: a path that use every edge exactly once
path: different start and end
number of odd degree vertices = 2
graph can have multiple edges / self edges


Euler Cycle: a cycle that use every edge exactly once
cycle: start node = end node
number of odd degree vertices = 0
graph can have multiple edges / self edges

- Note that there is not exist graph where number of odd degree vertices = 1,3,5,7
- every graph has an even number of odd vertices
- 2 * edges = sum of nodes degree
*/
vector<vector<int>>adj;
vector<int>tour;
int n,m;
void euler(int i)
{
    for(int j=1;j<=n;j++)
    {
        if(adj[i][j]) // this condtion for self loops
        {
            adj[i][j]--;
            adj[j][i]--;
            euler(j);
        }
    }
    tour.push_back(i);
}
// this code don't work with multiple edges
```
