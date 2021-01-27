```cpp
// Prim Algorithm 
// Computes the minimum spanning tree of a weighted graph
class MST
{
    struct edge
    {
        int to, weight;
        edge() {}
        edge(int t, int w) : to(t), weight(w) {}
        bool operator<(const edge& rhs) const
        {
            return weight > rhs.weight; // < for Maximum Spanning Tree
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

```
