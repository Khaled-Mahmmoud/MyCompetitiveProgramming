```cpp
__Dirct Graph__	
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
__Undirected Graph__
// Fence (USACO)
const int N = 2003;
vector<queue<pair<int,int>>>adj(N);
vector<vector<pair<int, int>>> adj_(N);
vector<int> res, vis(N),deg(N);
int odd[N];
void init()
{
    vis = vector<int>(N);
    deg = vector<int>(N);
    res = vector<int>();
    adj = vector<queue<pair<int, int>>>(N);
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
    }
    res.push_back(node);
}
void solve()
{
    init();
    int n;
    cin >> n;
    int st = N;
    for (int i = 0; i<n; i++)
    {
        int u,v;
        cin>>u>>v;
        adj_[u].push_back({v,i});
        adj_[v].push_back({u,i});
        odd[u] ^= 1;
        odd[v] ^= 1;
        st = min(u,v);
    }
    for(int i=0; i<N; i++)
        sort(adj_[i].begin(),adj_[i].end());
    for(int i=0; i<N; i++)
        for(int j=0; j<sz(adj_[i]); j++)
            adj[i].push(adj_[i][j]);
    int cntOdd = count(odd, odd + N, 1);
    if (cntOdd > 2)
    {
        cout<<-1<<'\n';
        return;
    }
    if (cntOdd)
        st = find(odd, odd + N, 1) - odd;
    euler(st);
    if (sz(res) - 1 != n)
    {
        cout<<-1<<'\n';
        return;
    }
    reverse(res.begin(),res.end());
    for(int i=0; i<sz(res); i++)
        cout<<res[i]<<'\n';
}
```
