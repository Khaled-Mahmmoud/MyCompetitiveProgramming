#  Degree of vertices

```cpp
int main()
{
    int n,m;
    map<int,int>degree,indegree,outdegree;
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        
        degree[u]++;
        degree[v]++;
        
        indegree[v]++;
        outdegree[u]++;
    }
    for(int i=1;i<=n;i++)
    cout<<indegree[i]<<' '<<outdegree[i]<<' '<<degree[i]<<'\n';
    return 0;
}
```

