# How to find connected components using DFS?

A graph is said to be disconnected if it is not connected, i.e. if two nodes exist in the graph such that there is no edge in between those nodes. In an undirected graph, a connected component is a set of vertices in a graph that are linked to each other by paths.

Consider the example given in [the diagram](https://github.com/Khaled-Mahmmoud/MyCompetitiveProgramming/blob/master/img/Graph/connected%20components.jpg). Graph G is a disconnected graph and has the following 3 connected components.

First connected component is 1 -> 2 -> 3 as they are linked to each other

Second connected component 4 -> 5

Third connected component is vertex 6

In DFS, if we start from a start node it will mark all the nodes connected to the start node as visited. Therefore, if we choose any node in a connected component and run DFS on that node it will mark the whole connected component as visited.

```cpp
for(int i = 1;i <= nodes;++i) 
{
    if(visited[i] == false)     
    {
         dfs(i);
         cnt_component++;
    }
}
```
