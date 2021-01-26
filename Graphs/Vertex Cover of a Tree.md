```cpp
// A vertex cover is a set of marked vertices that covers every edge in a tree
// this means that every node or its parent is marked.
// A minimum vertex cover is a vertex cover that marks the fewest nodes.
vector<vector<int>>adj;
int cnt;
bool dfs(int u, int p)
{
    bool black = false;
    for(auto v:adj[u])
        if(v!= p)
        {
            bool cur = dfs(v, u);
            if(cur)
                black = true;
        }
    if(black)
        ++res;
    return !black;
}
void solve()
{
    int n,m;
    cin>>n>>m;
    adj.resize(n+1);
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,-1);
    cout<<res;
}
```
