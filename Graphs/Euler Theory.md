```cpp
__Undirected Graph Euler__
// Fence (USACO)
vector<queue<pair<int,int>>>adj;
vector<vector<pair<int, int>>> adjv;
vector<int> rnode, redge, vis, deg;
void init(int n,int m)
{
    vis = vector<int>(m);
    deg = vector<int>(n);
    rnode = vector<int>();
    redge = vector<int>();
    adj = vector<queue<pair<int, int>>>(n);
    adjv = vector<vector<pair<int, int>>>(n);
}
void euler(int node)
{
    while (sz(adj[node]))
    {
        auto it = adj[node].front();
        adj[node].pop();
        if (vis[it.second])
            continue;
        vis[it.second] = true;
        euler(it.first);
        redge.push_back(it.second);
    }
    rnode.push_back(node);
}
void solve()
{
    int n, m;
    cin>>n>>m;
    init(n, m);
    int st = n;
    for (int i = 0; i<m; i++)
    {
        int u,v;
        cin>>u>>v;
        u--, v--;
        adjv[u].push_back({v,i});
        adjv[v].push_back({u,i});
        deg[u] ^= 1;
        deg[v] ^= 1;
        st = min(u,v);
    }
    for(int i=0; i<n; i++)
        sort(adjv[i].begin(),adjv[i].end());
    for(int i=0; i<n; i++)
        for(int j=0; j<sz(adjv[i]); j++)
            adj[i].push(adjv[i][j]);
    int cntOdd = count(deg.begin(), deg.end(), 1);
    if (cntOdd > 2)
    {
        cout<<-1<<'\n';
        return;
    }
    if (cntOdd)
        st = find(deg.begin(), deg.end(), 1) - deg.begin();
    euler(st);
    // OR if(sz(redge) != m)
    if (sz(rnode) - 1 != m)
    {
        cout<<-1<<'\n';
        return;
    }
    reverse(rnode.begin(),rnode.end());
    for(int i=0; i<sz(rnode); i++)
        cout<<rnode[i]<<' ';
    cout<<'\n';
}
```
```cpp
__Dirct Graph Euler__	
// https://open.kattis.com/problems/eulerianpath
vector<queue<pair<int,int>>>adj;
vector<vector<pair<int, int>>> adjv;
vector<int> rnode, redge, vis, deg;
void init(int n)
{
    vis = vector<int>(n);
    deg = vector<int>(n);
    rnode = vector<int>();
    redge = vector<int>();
    adj = vector<queue<pair<int, int>>>(n);
    adjv = vector<vector<pair<int, int>>>(n);
}
void euler(int node)
{
    while (sz(adj[node]))
    {
        auto it = adj[node].front();
        adj[node].pop();
        if (vis[it.second])
            continue;
        vis[it.second] = true;
        euler(it.first);
        redge.push_back(it.second);
    }
    rnode.push_back(node);
}
void solve()
{
    int n, m;
    cin>>n>>m;
    init(n);
    int st = n;
    for (int i = 0; i<m; i++)
    {
        int u,v;
        cin>>u>>v;
        u--,v--;
        adjv[u].push_back({v,i});
        adjv[v].push_back({u,i});
        deg[u]++;
        deg[v]--;
        st = min(u,v);
    }
    for(int i=0; i<n; i++)
        sort(adjv[i].begin(),adjv[i].end());
    for(int i=0; i<n; i++)
        for(int j=0; j<sz(adjv[i]); j++)
            adj[i].push(adjv[i][j]);
    bool valid = true;
    int odd = 0;
    for (int i = 0; i < n; i++)
    {
        if (deg[i] == 1)
        {
            odd++;
            st = i;
        }
        else if (abs(deg[i]) > 1)
            valid = false;
    }
    if (odd > 1)
        valid = false;
    euler(st);
    // OR if(sz(redge) != m)
    if (sz(rnode) - 1 != m || !valid)
    {
        cout<<-1<<'\n';
        return;
    }
    reverse(rnode.begin(),rnode.end());
    for(int i=0; i<sz(rnode); i++)
        cout<<rnode[i]<<'\n';
}
```
