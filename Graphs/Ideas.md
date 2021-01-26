```CPP
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
