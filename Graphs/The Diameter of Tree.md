```cpp
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

```
