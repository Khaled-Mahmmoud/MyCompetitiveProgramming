```cpp
/*
Directed graph : is a graph in which all the edges are uni-directional
Undirected graph: is a graph in which all the edges are bi-directional 
Weighted graph: In which each edge is assigned a weight or cost
Cyclic graph: if the graph comprises a path that starts from a vertex and ends at the same vertex
Connected graph: if from any node in graph , we can reach to all nodes
Disconnected graph: if above condition is not met
Null Graph: A graph having no edges
Trivial Graph: a graph with only one vertex
Simple graph: if graph doesn't contain any loop or parallel edges
Not simple graph: if above condition is not met
K-regular Graph: if all its vertices have the same degree k.
Complete graph: if from any node in graph , we can reach to all nodes but path = 1
Bipartite Graph: vertices can be divided into two disjoint sets, every edge connects a vertex in V1 to one in V2.  
Complete Bipartite Graph: if every vertex in V1 is connected to every vertex of V2.
Star Graph: a grapth that n – 1 vertices are connected to a single central vertex
Complement of a Graph: if both graph I and graph II are combined together to form a complete graph,
then graph I and graph II are called complements of each other
Simple path: is a path from v to w with no repeated vertices, except that the first and last may be the same vertex.
Tree is a connected graph that doesn't contain any cycles in which any two vertices are connected by only one path.
Tree is an acyclic graph and has N - 1 edges where N is the number of vertices. Each node in a graph may have one 
or multiple parent nodes. However, in a tree, each node (except the root node) comprises exactly one parent node.

                A           Level : 0
             /  |  \ brunch or edge
            B   E   F       Level : 1
          /  \    / | \ brunch
         C    D  G  H  I    Level : 2
         
root      -->> A
parent    -->> A , B , F
child  -->> B,E,F  C,D  G,H,I
leaves    -->> C,D  E  G,H,I
Siblings  -->> {B,E,F}  {C,D}   {G,H,I}
Ancestor  -->> C{A,B}  E{A}    I{A,F}
Depth(C) = 2 (path from root to C) , Depth(E) = 1 , Depth(A) = 0
Height(B) = 1 (path from B to the farthest leave node) , Height(A) = 2
Height of tree is path from root to the farthest leave node
Height of tree that has only one node is zero
Height of empty tree is -1
`Edges = number of nodes - 1` 
outdegree(A) = 3 (number of nodes branched from A) 
indegree(F) = 1 (number of nodes that F is branched from) 
degree(B) = outdegree(B) + indegree(B) = 2 + 1 = 3

Parenthetical notation = A(B(CD)EF(GHI))

            B   
          /  \     is subtree of above tree
         C    D

     I         root (root is also an internal node, unless it is leaf)
   /   \
  I     I      internal nodes
 /     / \
o     o   o    external nodes (or leaves)


Full(strictly) Binary Tree : if Every node has zero or two children
           O
         /   \
        O     O
      /   \
     O     O
         /   \
        O     O
Complete Binary Tree
1) all levels is completely filled except the last level
2) all Nodes as left as possible in the last level
           O
         /   \
        O     O
      /   \
     O     O
This below binary trees is not complete binary tree
           O            
         /   \
        O     O
      /   \     \
     O     O     O
     
           O            
         /   \
        O     O
            /   \
           O     O

Perfect Binary tree
1) every node has two children except leaves
2) all leaves are at the same level

            O            
         /     \
        O       O
      /   \   /   \
     O     O O     O

Balanced Binary Tree
1) the height of tree = O(log2(n))
2) | height(left subtree) - height(right subtree) | <= 1   //   {1,0,-1}
          3 - 2 = (1)--> Balance Factor
           3O2          
         /     \
       2O1     2O1
      /   \   /   \
     O     O O     O
    /         \
   O           O
   
A degenerate (or Pathological) tree : every parent node has only one child eigher left or right
         O
          \
           O
            \
             O
              \
               O
               
            O           Max no. of nodes at level 0 = 1 = 2^0
         /     \
        O       O       Max no. of nodes at level 1 = 2 = 2^1
      /   \   /   \
     O     O O     O    Max no. of nodes at level 2 = 4 = 2^2
Max no. of nodes at level L = 2^L
Max no. of nodes in binary tree = 2^(h+1) - 1 (where h is height of tree)   //  as perfect tree

The number of paths or simple paths in the tree = n * (n-1) / 2
   O
 /   \
O     O 
       \
        O
*/

// Depth-First Search (DFS)
vector<vector<int>>adj;
vector<bool>vis;
void dfs(int u)
{
    vis[u] = true;
    for (int v : adj[u])
        if (!vis[v])
            dfs(v);
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
// O(V + E), where V is the number of nodes and E is the number of edges.
// DFS on tree
vector<vector<int>>adj;
void dfs(int u = 1,int par = -1)
{
    for (int v : adj[u])
        if (v!=par)
            dfs(v,u);
}
// DFS Numbering
int w = 0;
void dfs(int node , int par) 
{
    l[node] = ++w;
    for(auto &i : adj[node])
        if(i != par)
            dfs(i , node);
    r[node] = w;
}
// Breadth-First Search (BFS)
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
        for(int v:adj[u]) 
          if(!vis[v]) 
             q.push(v);
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
// O(V + E), where V is the number of nodes and E is the number of edges.
// How to determine the level of each node in the given tree?
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
        for(int v:adj[u])
          if(!vis[v])
            q.push({v,level+1});
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
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(1,0);
    return 0;
}

// How to find connected components using DFS?
for(int i = 1;i <= nodes;++i) 
{
    if(visited[i] == false)     
    {
         dfs(i);
         cnt_component++;
    }
}
// How to Check if an undirected graph has cycle ?
vector<vector<int>>adj;
vector<bool>vis;
vector<int>parent;
int cnt;
void dfs(int u)
{
    vis[u] = 1;
    for(auto v:adj[u])
    if(vis[v])
    {
        if(parent[u]!=v)
            cnt++;
    }
    else
    {
        parent[v] = u;
        dfs(v);
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    adj.resize(n+1);
    vis.resize(n+1);
    parent.resize(n+1);
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=1; i<=n; i++)
    if(!vis[i])dfs(i);

    if(cnt)cout<<"YES";
    else cout<<"NO";
    
    return 0;
}
// Calculate maximum number of edges that can be removed from the graph 
// so that it contains exactly K connected components.
vector<vector<int>>adj;
vector<bool>vis;
vector<int>parent;
int cnt;
void dfs(int u)
{
    vis[u] = 1;
    for(auto v:adj[u])
    if(vis[v])
    {
        if(parent[u]!=v)
            cnt++;
    }
    else
    {
        parent[v] = u;
        dfs(v);
    }
}
int main()
{
    int n,m,k,cnt_component=0;
    cin>>n>>m>>k;
    adj.resize(n+1);
    vis.resize(n+1);
    parent.resize(n+1);
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1; i<=n; i++)
    if(!vis[i])
    {
        dfs(i);
        cnt_component++;
    }
    if(cnt_component>k)
        cout<<-1;
    else
    {
        cnt = cnt/2;
        cout<<cnt+(k-cnt_component);
    }
    return 0;
}
// Remove edges from the graph
void dfs(int u)
{
    vis[u] = 1;
    vector<int>newadj;
    for(auto v:adj[u])
    if(vis[v])
    {
        if(parent[u]!=v)
            cnt++;
        else
            newadj.push_back(v);
    }
    else
    {
        parent[v] = u;
        newadj.push_back(v);
        dfs(v);
    }
    adj[u] = newadj;
}
// Sum of lengths of all paths possible in a given tree
int n,a,b,sz[100001];
vector<int>g[100001];
long long ans = 0;
void dfs(int u=1, int p=-1)
{
    sz[u] = 1;
    for(int i = 0; i < g[u].size(); ++i)
    {
        int v = g[u][i];
        if(v == p)
            continue;
        dfs(v,u);
        sz[u] += sz[v];
    }
    ans += 1ll*sz[u]*(n-sz[u]);
}
int main()
{
    cin>>n;
    for (int i = 0; i < n-1; ++i)
    {
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs();
    cout<<ans<<endl;
    return 0;
}
// How to count number of vertices in subtree of every node of cycle in the given graph ?
int main()
{
    int n;
    cin>>n;
    vector<set<int>>adj(n);
    for(int i=0; i<n; i++)
    {
        int u,v;
        cin>>u>>v;
        u--,v--;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    vector<int>val(n,1);
    queue<int>leaf;
    for(int i=0; i<n; i++)
    {
        if(adj[i].size()==1)
            leaf.push(i);
    }
    while(!leaf.empty())
    {
        int v = leaf.front();
        leaf.pop();
        int to = *adj[v].begin();
        val[to] += val[v];
        val[v] = 0;
        adj[v].clear();
        adj[to].erase(v);
        if(adj[to].size()==1)
        {
            leaf.push(to);
        }
    }
    for(int i=0; i<n; i++)
        cout<<i+1<<" : "<<val[i]<<'\n';
    return 0;
}
// Bridges and Articulation Points
int n;
vector<vector<int> > g;
vector<int> idx, low;
int DFSTime;
vector<pair<int, int> > bridges;
vector<bool> art;
int child = 0;
void DFS(int u, int p)
{
    idx[u] = low[u] = ++DFSTime;
    for(int i = 0; i < g[u].size(); ++i)
    {
        int v = g[u][i];
        if(idx[v] == 0)
        {
            if(p == -1)
                ++child;
            DFS(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] > idx[u])
                bridges.push_back(make_pair(u, v));
            if(low[v] >= idx[u])
                art[u] = true;
        }
        else if(v != p)
            low[u] = min(low[u], idx[v]);
    }
}
int main()
{
    int e;
    cin >> n >> e;
    art.resize(n);
    idx.resize(n);
    low.resize(n);
    g.resize(n);
    for(int i = 0; i < e; ++i)
    {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    DFS(0, -1);
    art[0] = child > 1;
    return 0;
}
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
