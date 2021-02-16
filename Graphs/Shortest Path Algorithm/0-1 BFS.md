```cpp
vector<vector<pair<int,int>>>adj;
vector<int>par;
int n,m;
ll zbfs(int src,int dist)
{
    vector<ll>d(n+1,1e18);
    deque<int> q;
    q.push_front(s);
    d[src] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop_front();
        for (auto i : adj[u])
        {
            int v = i.first;
            int w = i.second;
            if (d[v] + w < d[u])
            {
                d[v] = d[u] + w;
                if (w == 1)
                    q.push_back(v);
                else
                    q.push_front(v);
            }
        }
    }
    return d[dist];
}
void backtrack(int u)
{
    if(u!=1)
        backtrack(par[u]);
    cout<<u<<' ';
}
void solve()
{
    cin>>n>>m;
    adj.resize(n+1);
    par.resize(n+1);
    while(m--)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    int src,dist;
    cin>>src>>dist;
    ll k=zbfs(src,dist);
    if(k==1e18)
        cout<<-1;
    else
        backtrack(n);
} // O(n+m)
```
