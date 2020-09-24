# Maximum number of edges removed

You are given a graph with  nodes and  edges.
Calculate maximum number of edges that can be removed from the graph so that it contains exactly K connected components.

Input : 
The first line contains n , m , k, the next m lines have two number,u and v that show there is an edge between those nodes.

It is guaranteed that input is valid(no multiple edges and no loops).

Output : Maximum number of edges that can be removed from the graph such that it contains exactly K connected components.

If the graph intially has more than K components print -1. 

1 <= n,m <= 100 000 

1 <= k <=n

SAMPLE INPUT 

4 3 2

1 2

2 3

1 3

SAMPLE OUTPUT : 1

Explanation : Initially, the graph has two connected components, hence we can remove only one edge.

```cpp
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
```

To remove edges from the graph

```cpp
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
```
