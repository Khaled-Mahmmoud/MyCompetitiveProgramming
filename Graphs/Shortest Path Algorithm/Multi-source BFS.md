```cpp
// Multi-source BFS : calculate which colored node is the closest to the given node 
// and print the shortest distance to the closest colored node. 
void bfs()
{
    memset(dis,-1,sizeof(dis));
    queue<int>q;
    for(int i=1; i<=n; i++)
        if(col[i])
            q.push(i),dis[i] = 0;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(auto v:adj[u])
            if(dis[v] == -1)
            {
                dis[v] = dis[u] + 1;
                q.push(v);
            }
    }
}
```
