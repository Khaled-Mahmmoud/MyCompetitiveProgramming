# Tree Diameter

Computes the length of the diameter of the tree. (i.e. the length of the longest path in the tree).
 
```cpp
const int N = 100100;
int n,m;                  
int dis[N];             
int par[N];             
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
```
Complexity: O(n+m)
