```cpp
// Prim Algorithm 
// Computes the minimum/maximum spanning tree of a weighted graph
// O(n.log(n))
struct edge
{
    int to, weight;
    edge() {}
    edge(int t, int w) : to(t), weight(w) {}
    bool operator<(const edge& rhs) const
    {
        // for maximum spanning tree we used
        //  return weight < rhs.weight;
        return weight > rhs.weight;
    }
};
const int N = 100100;
int n,m;
int vis[N];
vector<edge> adj[N];
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
int main()
{
    cin >> n >> m;
    while (m--)
    {
        int u, v, w;
        cin>>u>>v>>w;
        adj[u].push_back(edge(v, w));
        adj[v].push_back(edge(u, w));
    }
    cout<<primMST();
}

// Kruskal Algorithm
// Computes the minimum spanning tree of a weighted graph
// O(n.log(n))
struct edge
{
	int from, to, weight;
	edge() {}
	edge(int f, int t, int w) : from(f), to(t), weight(w) {}
	bool operator<(const edge& rhs) const {return (weight < rhs.weight);}
};
const int N = 100100;
int n,m;                  
int par[N];            
vector<edge> edges;		
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
void read() 
{
	cin >> n >> m;
	while (m--) 
    {
		int u, v, w;
		cin>>u>>v>>w;
		edges.push_back(edge(u, v, w));
	}
	cout<<kruskalMST;
}
```
