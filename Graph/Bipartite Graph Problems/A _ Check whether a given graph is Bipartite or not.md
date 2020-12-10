# Check whether a given graph is Bipartite or not

A Bipartite Graph is a graph whose vertices can be divided into two independent sets, U and V such that every edge (u, v) either connects a vertex from U to V
or a vertex from V to U. In other words, for every edge (u, v), either u belongs to U and v to V, or u belongs to V and v to U.
We can also say that there is no edge that connects vertices of same set.

A bipartite graph is possible if the graph coloring is possible using two colors such that vertices in a set are colored with the same color.
Note that it is possible to color a cycle graph with even cycle using two colors. 

It is not possible to color a cycle graph with odd cycle using two colors.


Algorithm to check if a graph is Bipartite:

One approach is to check whether the graph is 2-colorable or not using backtracking algorithm m coloring problem.

```cpp
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
```
Time Complexity: O(n + m)
