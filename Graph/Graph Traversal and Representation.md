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

### Depth-First Search

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
Time complexity : O(V+E)  the number of nodes and edges in the graph
