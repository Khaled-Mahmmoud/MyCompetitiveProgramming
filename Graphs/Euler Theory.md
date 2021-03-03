```cpp
__Dirct Graph Euler__	
// https://open.kattis.com/problems/catenyms	
vector<queue<pair<int, int>>> adj;
vector<int> res, vis;
void init()
{
    vis = vector<int>(N);
    res = vector<int>();
    adj = vector<queue<pair<int, int>>>(N);
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
        res.push_back(it.second);
    }
}
void solve()
{
    init();
    int n;
    cin >> n;
    vector<string> v(n);
    vector<int> deg(26);
    for (auto &it : v)
        cin >> it;
    sort(v.begin(),v.end());
    int st = 26;
    for (int i = 0; i < n; i++)
    {
        int a = v[i][0] - 'a', b = v[i].back() - 'a';
        deg[a]++; deg[b]--;
        adj[a].push( { b, i });
        st = min( { st, a, b });
    }
    bool valid = true;
    int odd = 0;
    for (int i = 0; i < 26; i++)
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
    if (sz(res) != n)
        valid = false;
    if (valid)
    {
        reverse(res.begin(),res.end());
        for (int i = 0; i < n; i++)
            cout << v[res[i]] << ".\n"[i + 1 == n];
    }
    else
        cout << "***\n";
}
```
```cpp
__Undirected Graph Euler__
// Fence (USACO)
vector<queue<pair<int,int>>>adj;
vector<vector<pair<int, int>>> adjv;
vector<int> rnode, redge, vis, deg, odd;
void init(int n)
{
    vis = vector<int>(n);
    deg = vector<int>(n);
    odd = vector<int>(n);
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
        adjv[u].push_back({v,i});
        adjv[v].push_back({u,i});
        odd[u] ^= 1;
        odd[v] ^= 1;
        st = min(u,v);
    }
    for(int i=0; i<n; i++)
        sort(adjv[i].begin(),adjv[i].end());
    for(int i=0; i<n; i++)
        for(int j=0; j<sz(adjv[i]); j++)
            adj[i].push(adjv[i][j]);
    int cntOdd = count(odd.begin(), odd.end(), 1);
    if (cntOdd > 2)
    {
        cout<<-1<<'\n';
        return;
    }
    if (cntOdd)
        st = find(odd.begin(), odd.end(), 1) - odd.begin();
    euler(st);
    // OR if(sz(redge) != m)
    if (sz(rnode) - 1 != m)
    {
        cout<<-1<<'\n';
        return;
    }
    reverse(rnode.begin(),rnode.end());
    for(int i=0; i<sz(rnode); i++)
        cout<<rnode[i]<<'\n';
}
```
