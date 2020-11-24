### How to determine the level of each node in the given tree?
```cpp
vector<vector<int>>adj;
vector<bool>vis;
void bfs(int u,int level)
{
    queue<pair<int,int>>q;
    q.push({u,level});
    while(!q.empty())
    {
        u = q.front().first;
        level = q.front().second;
        vis[u] = true;
        cout<<u<<' '<<level<<endl;
        q.pop();
        for(int v:adj[u])
          if(!vis[v])
            q.push({v,level+1});
    }
}
int main()
{
    int n;
    cin>>n;
    adj.resize(n+1);
    vis.resize(n+1);
    n--;
    while(n--)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(1,0);
    return 0;
}
```

