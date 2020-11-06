# Kefa and Dishes


[Problem Link](https://codeforces.com/contest/580/problem/D)

```cpp
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
ll v[19],c[19][19],dp[1<<19][19];
ll solve(int cur,int mask)
{
    if(__builtin_popcount(mask)==m)
        return 0;
    ll &rt = dp[mask][cur];
    if(~rt)
        return rt;
    for(int i=0;i<n;i++)
    {
        if(mask&(1<<i))
            continue;
        int tmask = mask | (1<<i);
        rt = max(rt,v[i]+c[cur][i]+solve(i,tmask));
    }
    return rt;
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int k;
    cin>>n>>m>>k;
    for(int i=0;i<n;i++)
        cin>>v[i];
    while(k--)
    {
        int u,v,ci;
        cin>>u>>v>>ci;
        u--;v--;
        c[u][v] = ci;
    }
    memset(dp,-1,sizeof dp);
    cout<<solve(n,0);
    return 0;
}
```
