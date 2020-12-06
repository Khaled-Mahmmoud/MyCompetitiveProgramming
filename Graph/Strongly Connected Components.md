### Strongly Connected Components

```cpp
const int N = 100000;
int n, e, idx[N], low[N], T;
vector<vector<int> > g;
vector<int> S;
bool vis[N];
int compID[N], cmp;
void DFS(int u)
{
    idx[u] = low[u] = ++T;
    S.push_back(u);
    vis[u] = true;
    for (int i = 0; i < g[u].size(); ++i)
    {
        int v = g[u][i];
        if (idx[v] == 0)
            DFS(v);
        if (vis[v])
            low[u] = min(low[u], low[v]);
    }
    if (idx[u] == low[u])
    {
        while (true)
        {
            int v = S.back();
            S.pop_back();
            vis[v] = false;
            compID[v] = cmp;
            if (v == u)
                break;
        }
        ++cmp;
    }
}
int main()
{
    cin >> n >> e;
    g.resize(n);
    for (int i = 0; i < e; ++i)
    {
        int from, to;
        cin >> from >> to;
        --from;
        --to;
        g[from].push_back(to);
    }
    for (int i = 0; i < n; ++i)
        if (idx[i] == 0)
            DFS(i);

    cout<<cmp<<endl;
    return 0;
}
```
