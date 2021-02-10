```cpp
/*
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
