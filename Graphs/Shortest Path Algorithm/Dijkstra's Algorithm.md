```cpp
// Dijkstra Algorithm : Computes the shortest path between the given source node
// and all the other nodes in non-negative weighted graph. (Single Source Shortest Path (SSSP))
vector<vector<pair<int,int>>>adj;
vector<int>par;
int n,m;
ll dijkstra()
{
    vector<ll>d(n+1,1e18);
    set<pair<ll,int>>st;
    st.insert(make_pair(0,1));
    d[1] = 0;
    while(st.size())
    {
        int u = st.begin()->second;
        ll cost = st.begin()->first;
        st.erase(st.begin());
        for(auto i:adj[u])
        {
            int v = i.first,w = i.second;
            if(d[v] > d[u]+w)
            {
                st.erase(make_pair(d[v],v));
                d[v] = d[u]+w;
                par[v] = u;
                st.insert(make_pair(d[v],v));
            }
        }
    }
    return d[n];
}
void backtrack(int u)
{
    if(u!=1)
        backtrack(par[u]);
    cout<<u<<' ';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
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
    ll k=dijkstra();
    if(k==1e18)
    {
        return cout<<-1,0;
    }
    backtrack(n);
    return 0;
} // O((n+m)log(n))
```
