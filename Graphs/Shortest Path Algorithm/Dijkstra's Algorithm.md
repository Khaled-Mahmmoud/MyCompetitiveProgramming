```cpp
// Dijkstra Algorithm : Computes the shortest path between the given source node
// and all the other nodes in non-negative weighted graph. (Single Source Shortest Path (SSSP))
vector<vector<pair<int,int>>>adj;
vector<int>par;
int n,m;
ll dijkstra(int src,int dist)
{
    vector<ll>d(n+1,1e18);
    set<pair<ll,int>>st;
    st.insert(make_pair(0,src));
    d[src] = 0;
    while(st.size())
    {
        int u = st.begin()->second;
        st.erase(st.begin());
        for(auto i:adj[u])
        {
            int v = i.first,w = i.second;
            if(d[v] > d[u]+w)
            {
                st.erase(make_pair(d[v],v));
                d[v] = d[u] + w;
                par[v] = u;
                st.insert(make_pair(d[v],v));
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
    ll k=dijkstra(src,dist);
    if(k==1e18)
        cout<<-1;
    else
        backtrack(n);
} // O((n+m)log(n))
```
