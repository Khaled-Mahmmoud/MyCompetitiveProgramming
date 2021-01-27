```cpp
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

```
