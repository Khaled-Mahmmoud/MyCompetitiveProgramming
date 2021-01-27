```cpp
// Prim Algorithm 
// Computes the minimum/maximum spanning tree of a weighted graph
class MST
{
    struct edge
    {
        int to, weight;
        edge() {}
        edge(int t, int w) : to(t), weight(w) {}
        bool operator<(const edge& rhs) const
        {
            return weight > rhs.weight;
        }
    };
    int n,e;
    vector<int>vis;
    vector<vector<edge>>adj;
public:
    int primMST()
    {
        priority_queue<edge> pq;
        pq.push(edge(1, 0));
        int MST = 0;
        while(!pq.empty())
        {
            int u = pq.top().to;
            int w = pq.top().weight;
            pq.pop();
            if (vis[u]++)
                continue;
            MST += w;
            for(edge& v : adj[u])
                if(!vis[v.to])
                    pq.push(v);
        }
        return MST;
    }
    void solve()
    {
        cin >> n >> e;
        adj.resize(n);
        vis.resize(n);
        while (e--)
        {
            int u, v, w;
            cin>>u>>v>>w;
            u--,v--;
            adj[u].push_back(edge(v, w));
            adj[v].push_back(edge(u, w));
        }
        cout<<primMST();
    }
}; // O(n.log(n))

// Kruskal Algorithm
// Computes the minimum spanning tree of a weighted graph
class MST
{
    struct edge
    {
        int from, to, weight;
        edge() {}
        edge(int f, int t, int w) : from(f), to(t), weight(w) {}
        bool operator<(const edge& rhs) const
        {
            return (weight < rhs.weight);
        }
    };
    int n,e;
    vector<int>par;
    vector<edge>edges;
public:
    int find(int u)
    {
        return u == par[u] ? u : par[u] = find(par[u]);
    }
    int kruskalMST()
    {
        int MST = 0;
        sort(edges.begin(), edges.end());
        for(int i = 1; i <= n; ++i)
            par[i] = i;
        for(auto& e : edges)
        {
            int x = find(e.from);
            int y = find(e.to);
            if (x != y)
            {
                par[x] = y;
                MST += e.weight;
            }
        }
        return MST;
    }
    void solve()
    {
        cin>>n>>e;
        par.resize(n);
        while (e--)
        {
            int u, v, w;
            cin>>u>>v>>w;
            u--,v--;
            edges.push_back(edge(u, v, w));
        }
        cout<<kruskalMST();
    }
}; // O(n.log(n))

// Kruskal Algorithm
// Computes the second minimum spanning tree of a weighted graph
// O(n.log(n))
struct edge
{
    int from, to, weight,idx;
    bool del;
    edge() {}
    edge(int f, int t, int w,int id) : from(f), to(t), weight(w), idx(id) {del=false;}
    bool operator<(const edge& rhs) const
    {
        return (weight < rhs.weight);
    }
};
const int N = 102;
int n,m;
int par[N];
int find(int u)
{
    return u == par[u] ? u : par[u] = find(par[u]);
}
pair<int,vector<edge>> kruskalMST(int n,vector<edge> edges)
{
    int MST = 0;
    sort(edges.begin(), edges.end());
    vector<edge> res;
    for(int i = 1; i <= n; ++i)
        par[i] = i;
    for(auto& e : edges)
    {
        if(e.del)
            continue;
        int x = find(e.from);
        int y = find(e.to);
        if (x != y)
        {
            par[x] = y;
            MST += e.weight;
            res.push_back(e);
        }
    }
    if(sz(res)!= n-1)
        return make_pair(INT_MAX,vector<edge>());
    return make_pair(MST,res);
}
void read()
{
    vector<edge> edges;
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        int u, v, w;
        cin>>u>>v>>w;
        edges.push_back(edge(u, v, w,i));
    }
    pair<int,vector<edge>> res = kruskalMST(n,edges);
    int sc = INT_MAX;
    for(int i = 0 ; i < res.second.size(); i++)
    {
        edges[res.second[i].idx].del = true;
        
        pair<int,vector<edge>>res2 = kruskalMST(n,edges);
        sc = (res2.first < sc)?res2.first:sc;
        
        edges[res.second[i].idx].del = false;
    }
    cout<<res.first <<" "<<sc<< '\n';
}
```
