# Civilization

[Problem Link](https://codeforces.com/contest/455/problem/C)

**Solution**

You can see that the road system is a forest. For efficient storage component we need to use DSU. First, we need to build the initial system of roads. For each component of the initial road system, we must find the diameter of component. This can be done using a DFS or BFS. Let a — any vertex of component. Let b — furthest vertex from vertex a. Let c — furthest vertex from vertex b. Diameter equal to distance from b to c. This algorithm for finding the diameter is correct only for tree. For each component in the DSU, we know its diameter.

Now it is very easy to answer the query of the 1st type: To know the component which contains the vertex x and output diameter of this component. Query of the 2nd type also very easy to process: Let u — of component in which lie the vertex x, v — of component in which lie the vertex y. If u ≠ v, then we can merge components: The diameter of the new component is computed as follows:

`diameter_new = max(diameter_u , diameter_v , ceil(diameter_u/2) + ceil(diameter_v/2) + 1)`
```cpp
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,q,cnt=0;
vector<vector<int>>adj;
vector<int>group,diameter,par,dis,p,vc;
int bfs(int u)
{
    group[u] = cnt;
    dis[u] = 0;
    queue<int>q;
    q.push(u);
    while(!q.empty())
    {
        vc.push_back(u);
        u = q.front();
        q.pop();
        for(auto v:adj[u])
        {
            if(group[v]==-1)
            {
                group[v] = cnt;
                dis[v] = dis[u] + 1;
                par[v] = u;
                q.push(v);
            }
        }
    }
    return u;
}
int find(int u)
{
    if(u==p[u])
        return u;
    return p[u] = find(p[u]);
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    cin>>n>>m>>q;
    adj.resize(n+1);
    group.resize(n+1);
    diameter.resize(n+1);
    par.resize(n+1);
    dis.resize(n+1);
    p.resize(n+1);
    vc.resize(n+1);
    fill(group.begin(),group.end(),-1);
    fill(par.begin(),par.end(),-1);
    fill(dis.begin(),dis.end(),-1);

    while(m--)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
    {
        if(group[i]==-1)
        {
            int u = bfs(i);
            for(int i=0;i<vc.size();i++)
                group[vc[i]] = par[vc[i]] = dis[vc[i]]  = -1;
            int v = bfs(u);
            diameter[cnt++] = dis[v];
            vc.clear();
        }
    }
    for(int i=0;i<n;i++)p[i] = i;
    while(q--)
    {
        int t,x,y,a,b;
        cin>>t>>x;
        if(t==2)
        {
            cin>>y;
            a = find(group[x]);
            b = find(group[y]);
            if(a==b)continue;
            p[a] = b;
            diameter[b] = max(diameter[a],max(diameter[b],(diameter[a]+1)/2+(diameter[b]+1)/2+1));
        }
        else
        {
            a = find(group[x]);
            cout<<diameter[a]<<'\n';
        }
    }
    return 0;
}
```
