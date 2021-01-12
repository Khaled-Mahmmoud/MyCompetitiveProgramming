```cpp
int n;
vector<vector<int> > g;
vector<int> idx, low;
int DFSTime;
vector<pair<int, int> > bridges;
vector<bool> art;
int child = 0;
void DFS(int u, int p)
{
    idx[u] = low[u] = ++DFSTime;
    for(int i = 0; i < g[u].size(); ++i)
    {
        int v = g[u][i];
        if(idx[v] == 0)
        {
            if(p == -1)
                ++child;
            DFS(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] > idx[u])
                bridges.push_back(make_pair(u, v));
            if(low[v] >= idx[u])
                art[u] = true;
        }
        else if(v != p)
            low[u] = min(low[u], idx[v]);
    }
}
void Bridges()
{
    int e;
    cin >> n >> e;
    art.resize(n);
    idx.resize(n);
    low.resize(n);
    g.resize(n);
    for(int i = 0; i < e; ++i)
    {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    DFS(0, -1);
    art[0] = child > 1;
}
```
