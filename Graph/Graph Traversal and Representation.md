# Graph representation

You can represent a graph in many ways. The two most common ways of representing a graph is as follows:

### Adjacency matrix

An adjacency matrix is a VxV binary matrix A. Element  is 1 if there is an edge from vertex i to vertex j else  is 0.

Note: A binary matrix is a matrix in which the cells can have only one of two possible values - either a 0 or 1.

The adjacency matrix can also be modified for the weighted graph in which instead of storing 0 or 1 in , the weight or cost of the edge will be stored.

In an undirected graph, if  = 1, then  = 1. In a directed graph, if  = 1, then  may or may not be 1.

Adjacency matrix provides constant time access (O(1) ) to determine if there is an edge between two nodes. Space complexity of the adjacency matrix is O().

The adjacency matrix of [the following graph](https://github.com/Khaled-Mahmmoud/MyCompetitiveProgramming/blob/master/img/Graph/adjacency%20matrix%20undirected%20graph.jpg) is:

$ : 1 2 3 4

1 : 0 1 0 1

2 : 1 0 1 0

3 : 0 1 0 1

4 : 1 0 1 0

The adjacency matrix of [the following graph](https://github.com/Khaled-Mahmmoud/MyCompetitiveProgramming/blob/master/img/Graph/adjacency%20matrix%20directed%20graph.jpg) is:


$ : 1 2 3 4

1 : 0 1 0 0

2 : 0 0 0 1

3 : 1 0 0 1

4 : 0 1 0 0

```cpp
bool A[10][10];
int main()
{
    int x, y, nodes, edges;
    cin >> nodes;       
    cin >> edges;      
    for(int i = 0; i < edges; ++i)
    {
        cin >> x >> y;
        A[x][y] = true;     //Mark the edges from vertex x to vertex y
    }
    if(A[3][4] == true)
        cout << “There is an edge between 3 and 4” << endl;
    else
        cout << “There is no edge between 3 and 4” << endl;
    return 0;
}
```

### Adjacency list

The other way to represent a graph is by using an adjacency list. An adjacency list is an array A of separate lists. 

Each element of the array Ai is a list, which contains all the vertices that are adjacent to vertex i.

For a weighted graph, the weight or cost of the edge is stored along with the vertex in the list using pairs. 

In an undirected graph, if vertex j is in list Ai then vertex i will be in list Aj.

The space complexity of adjacency list is O(V + E) because in an adjacency list information is stored only for those edges that actually exist in the graph. 

In a lot of cases, where a matrix is sparse using an adjacency matrix may not be very useful. 

This is because using an adjacency matrix will take up a lot of space where most of the elements will be 0, anyway. In such cases, using an adjacency list is better.

Note: A sparse matrix is a matrix in which most of the elements are zero, whereas a dense matrix is a matrix in which most of the elements are non-zero.

```cpp
vector <int> adj[10];
int main()
{
    int x, y, nodes, edges;
    cin >> nodes;       
    cin >> edges;       
    for(int i = 0; i < edges; ++i)
    {
        cin >> x >> y;
        adj[x].push_back(y);    
    }
    for(int i = 1; i <= nodes; ++i)
    {
        cout << "Adjacency list of node " << i << " : ";
        for(int j = 0; j < adj[i].size(); ++j)
            cout << adj[i][j] <<' ';
        cout<<'\n';
    }
    return 0;
}

```

# Graph Traversal

### Depth-First Search (DFS)

The DFS algorithm is a recursive algorithm that uses the idea of backtracking. It involves exhaustive searches of all the nodes by going ahead, if possible, else by backtracking.

Here, the word backtrack means that when you are moving forward and there are no more nodes along the current path, you move backwards on the same path to find nodes to traverse. All the nodes will be visited on the current path till all the unvisited nodes have been traversed after which the next path will be selected.

```cpp
vector<vector<int>>adj;
vector<bool>vis;
void dfs(int u)
{
    vis[u] = true;
    for (int z : adj[u])
        if (!vis[z])
            dfs(z);
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
        adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
    if(!vis[i])dfs(i);
    return 0;
}
```
The time complexity of DFS is O(V + E), where V is the number of nodes and E is the number of edges.

**Applications**

How to find connected components using DFS?

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
         counter-connected-components++;
    }
}
```


### Breadth-First Search (BFS)

There are many ways to traverse graphs. BFS is the most commonly used approach.

BFS is a traversing algorithm where you should start traversing from a selected node (source or starting node) and traverse the graph layerwise thus exploring the neighbour nodes (nodes which are directly connected to source node). You must then move towards the next-level neighbour nodes.

As the name BFS suggests, you are required to traverse the graph breadthwise as follows:

1) First move horizontally and visit all the nodes of the current layer
2) Move to the next layer

Traversing child nodes

A graph can contain cycles, which may bring you to the same node again while traversing the graph. To avoid processing of same node again, use a boolean array which marks the node after it is processed. While visiting the nodes in the layer of a graph, store them in a manner such that you can traverse the corresponding child nodes in a similar order.

In the earlier diagram, start traversing from 0 and visit its child nodes 1, 2, and 3. Store them in the order in which they are visited. This will allow you to visit the child nodes of 1 first (i.e. 4 and 5), then of 2 (i.e. 6 and 7), and then of 3 (i.e. 7) etc.

To make this process easy, use a queue to store the node and mark it as 'visited' until all its neighbours (vertices that are directly connected to it) are marked. The queue follows the First In First Out (FIFO) queuing method, and therefore, the neigbors of the node will be visited in the order in which they were inserted in the node i.e. the node that was inserted first will be visited first, and so on.

```cpp
vector<vector<int>>adj;
vector<bool>vis;
void bfs(int u) 
{
    queue<int> q;
    q.push(u);
    while (!q.empty()) 
    {
        u = q.front();
        vis[u] = true;
        q.pop();
        for(int z:adj[u]) 
          if(!vis[z]) 
             q.push(z);
    }
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
        adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
      if(!vis[i])bfs(i);
    return 0;
}
```
The time complexity of BFS is O(V + E), where V is the number of nodes and E is the number of edges.

**Applications**

1. How to determine the level of each node in the given tree?

by [diagram](https://github.com/Khaled-Mahmmoud/MyCompetitiveProgramming/blob/master/img/Graph/level%20of%20node.jpg), As you know in BFS, you traverse level wise. You can also use BFS to determine the level of each node.

```cpp
vector<vector<int>>adj;
vector<bool>vis;
void bfs(int u,int level)
{
    queue<pair<int,int>>q;
    q.push({u,level});
    while(!q.empty())
    {
        u = q.front().first;
        level = q.front().second;
        vis[u] = true;
        cout<<u<<' '<<level<<endl;
        q.pop();
        for(int z:adj[u])
          if(!vis[z])
            q.push({z,level+1});
    }
}
int main()
{
    int n;
    cin>>n;
    adj.resize(n+1);
    vis.resize(n+1);
    n--;
    while(n--)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bfs(1,0);
    return 0;
}
```
