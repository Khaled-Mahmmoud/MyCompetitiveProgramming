#include <bits/stdc++.h>
using namespace std;
void fast()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
}
vector<vector<pair<int,int>>>adj;
vector<int>par;
int n,m;
long long dijkstra()
{
    vector<long long>d(n+1,1e18);
    vector<bool>vis(n+1);
    deque<int>dq;
    dq.push_front(1);
    vis[1]=true;d[1]=0;
    while(dq.size())
    {
        int u=dq.front();
        dq.pop_front();
        vis[u]=0;
        for(auto i:adj[u])
        {
            int v=i.first,w=i.second;
            if(d[u]+w<d[v])
            {
                d[v]=d[u]+w;
                par[v]=u;
                if(!vis[v])
                    dq.push_front(v);
                vis[v]=true;
                if(d[dq.front()]>d[dq.back()])
                {
                    int k=dq.front();
                    dq.pop_front();
                    dq.push_back(k);
                }
            }
        }
    }
    return d[n];
}
void backtrack(int u)
{
    if(u!=1)backtrack(par[u]);
    cout<<u<<' ';
}
int main()
{
    fast();
    cin>>n>>m;
    adj.resize(n+1);
    par.resize(n+1);
    while(m--)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    long long k=dijkstra();
    if(k==1e18){return cout<<-1,0;}
    backtrack(n);
    return 0;
}
