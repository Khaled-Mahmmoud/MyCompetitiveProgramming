```cpp
// Check whether a given graph is Bipartite or not
const int N = 100100;
int color[N];           
vector<int> edges[N];   
bool dfs(int u = 1) 
{
    for (int v : edges[u]) 
    {
        if (color[v] == color[u]) 
            return false;
        if (color[v] == -1) 
        {
            color[v] = 1 - color[u];
            if (!dfs(v)) 
                return false;
        }
    }
    return true;
}
bool isBipartiteGraph() 
{
    memset(color, -1, sizeof(color));
    color[1] = 0;
    return dfs();
}
// Time Complexity: O(n + m)
```
