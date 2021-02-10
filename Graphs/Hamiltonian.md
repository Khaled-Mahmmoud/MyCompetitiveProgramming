```cpp
//  Check undirected graph contains a Hamiltonian Path or not?
int n;
int label[20];
int adj[20][20];
bool dfs(int v,int cnt)
{
    if(cnt == n)
        return true;
    for(int i=0; i<n; i++)
        if(adj[v][i] && label[i] == 0)
        {
            label[i] = 1;
            if(dfs(i , cnt + 1))
                return true;
            label[i] = 0;
        }
    return false;
}
bool check()
{
    for(int i=0; i<n; i++)
    {
        label[i] = 1;
        if(dfs(i,1))
            return true;
        label[i] = 0;
    }
    return false;
}
void solve()
{
    int e;
    cin>>n>>e;
    memset(label,0,sizeof label);
    memset(adj,0,sizeof adj);
    while(e--)
    {
        int u,v;
        cin>>u>>v;
        u--,v--;
        adj[u][v] = adj[v][u] = 1;
    }
    cout<<(check()?"YES":"NO")<<'\n';
}

```
