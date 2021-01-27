```cpp
// Kruskal Algorithm
// Computes the second minimum spanning tree of a weighted graph
class MST
{
    struct edge
    {
        int from, to, weight,idx;
        bool del;
        edge() {}
        edge(int f, int t, int w,int id) : from(f), to(t), weight(w), idx(id)
        {
            del=false;
        }
        bool operator<(const edge& rhs) const
        {
            return (weight < rhs.weight);
        }
    };
    int n,e;
    vector<int>par;
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
    void solve()
    {
        vector<edge> edges;
        cin>>n>>e;
        for(int i=0; i<e; i++)
        {
            int u, v, w;
            cin>>u>>v>>w;
            edges.push_back(edge(u, v, w,i));
        }
        pair<int,vector<edge>> res = kruskalMST(n,edges);
        int sc = INT_MAX;
        for(int i = 0 ; i < sz(res.second); i++)
        {
            edges[res.second[i].idx].del = true;
            pair<int,vector<edge>>res2 = kruskalMST(n,edges);
            sc = (res2.first < sc)?res2.first:sc;
            edges[res.second[i].idx].del = false;
        }
        cout<<res.first <<" "<<sc<< '\n';
    }
}; // O(n.log(n))
```
