# Print indegree of all vertices

```cpp
int main()
{
    int n,m;
    map<int,int>m;
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        m[u]++;
        m[v]++;
    }
    for(auto z:m)
        cout<<z.first<<' '<<z.second<<'\n';
    return 0;
}
```

