```cpp
// Hamiltonian Path 
int n,cnt = 0;
int label[20];
int adj[20][20];
void dfs(int v,int k)
{
    if(k == n)
        cnt++;
    for(int i=0; i<n; i++)
        if(adj[v][i] && label[i] == 0)
        {
            label[i] = 1;
            dfs(i,k + 1);
            label[i] = 0;
        }
}
void check()
{
    for(int i=0; i<n; i++)
    {
        label[i] = 1;
        dfs(i,1);
        label[i] = 0;
    }
}
void hamil()
{
    cnt = 0;
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
    check();
    cout<<cnt<<'\n';
}

// Hamiltonian Cycle 
int n,cnt = 0,start;
int label[20];
int adj[20][20];
void dfs(int v,int k)
{
    if(k == n&&adj[start][v])
        cnt++;
    for(int i=0; i<n; i++)
        if(adj[v][i] && label[i] == 0)
        {
            label[i] = 1;
            dfs(i,k + 1);
            label[i] = 0;
        }
}
void hamil()
{
    cnt = 0;
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
    start = 0;
    label[start] = 1;
    dfs(start,1);
    cout<<cnt/2<<'\n';
}
```
