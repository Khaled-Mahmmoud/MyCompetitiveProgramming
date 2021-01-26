```cpp
// The Diameter of a tree is the number of nodes on the longest path between two leaves in the tree. 
const int N = 100100;
int n,m;
int dis[N];
int par[N];
vector<int> adj[N];
int bfs(int u)
{
    queue<int>q;
    q.push(u);
    memset(par, -1, sizeof(par));
    memset(dis, -1, sizeof(dis));
    dis[u] = 0;
    while(!q.empty())
    {
        u = q.front();q.pop();
        for(int v : adj[u])
            if (dis[v] == -1)
            {
                dis[v] = dis[u] + 1;
                par[v] = u;
                q.push(v);
            }
    }
    return u;
}
void printPath(int v)
{
    if(~par[v])
        printPath(par[v]);
    cout<<v<<'\n';
}
int calcTreeDiameter()
{
    int root = 1;
    int u = bfs(root);
    int v = bfs(u);
    printPath(v);
    return dis[v];
}
void solve()
{
    int n,m;
    cin>>n>>m;
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout<<calcTreeDiameter();
}
// Complexity: O(n+m)
```
