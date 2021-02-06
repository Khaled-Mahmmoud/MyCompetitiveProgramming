```cpp
//Floyd Warshal: Computes the shortest path between any pair of nodes in the graph (All-Pair Shortest Path (APSP))
const int N = 505, oo = 1e9;
int n;
int adj[N][N];
int par[N][N];
void init()
{
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            adj[i][j] = (i == j ? 0 : oo), par[i][j] = i;
}
// Computes the shortest path between any pair of nodes in the graph
void floyd()
{
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (adj[i][j] > adj[i][k] + adj[k][j])
                    adj[i][j] = adj[i][k] + adj[k][j], par[i][j] = par[k][j];
} // O(n^3)
// Checks whether the graph has negative cycles or not.
bool checkNegativeCycle()
{
    bool ret = false;
    for (int i = 0; i < n; ++i)
    {
        ret = ret || (adj[i][i] < 0);
    }
    return ret;
}// O(n)
void printPath(int u,int v)
{
    if(u != v)
        printPath(u,par[u][v]);
    cout<<v+1<<' ';
}
void solve()
{
    cin >> n;
    init();
    int m, u, v, w;
    cin >> m;
    while (m--)
    {
        cin>>u>>v>>w;
        adj[u - 1][v - 1] = w;
    }
    floyd();
    cout<<"\nAll-Pairs Shortest Path:\n";
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            cout<< adj[i][j] <<"  ";
        cout<<'\n';
    }
    cout << endl;
    cin >> m;
    while (m--)
    {
        cin>>u>>v;
        printPath(u - 1, v - 1);
        cout<<endl;
    }
}
```
