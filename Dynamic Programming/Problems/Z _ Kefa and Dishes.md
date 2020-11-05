# Kefa and Dishes

`Bitwise dp`

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

# Antimatter Ray Clearcutting 

`Bitwise dp` `Geometry`

[Problem Link](https://vjudge.net/problem/UVA-11008)

```cpp
#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool getbit(int n,int idx){return ((n>>idx)&1);}
int setbit(int n,int idx){return (n|(1<<idx));}
int n,m;
int c[20][20];
int x[20],y[20],dp[1<<17];
int cntbit(int n)
{
    int res = 0;
    while(n)
    {
        if(n&1)
            res++;
        n>>=1;
    }
    return res;
}
int solve(int mask)
{
    if(cntbit(mask)>=m)
        return 0;
    if(cntbit(mask)>=m-1)
        return 1;
    int &rt = dp[mask];
    if(~rt)
        return rt;
    rt = 100;
    for(int i=0;i<n;i++)
        if(!getbit(mask,i))
            for(int j=i+1;j<n;j++)
                if(!getbit(mask,j))
                {
                    int tmask = mask | c[i][j];
                    rt = min(rt,1+solve(tmask));
                }
    if(rt==100)
        rt = 1;
    return rt;
}
void build()
{
    for(int i=0; i<n; i++)
        for(int j=i+1; j<n; j++)
        {
            int temp = 0;
            temp = setbit(temp,i);
            temp = setbit(temp,j);
            for(int k=j+1; k<n; k++)
            {
                int x1 = x[j] - x[i];
                int y1 = y[j] - y[i];
                int x2 = x[k] - x[i];
                int y2 = y[k] - y[i];
                if(x1*y2==x2*y1)
                    temp = setbit(temp,k);
            }
            c[i][j] = temp;
        }
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int t;
    cin>>t;
    for(int k=1; k<=t; k++)
    {
        cin>>n>>m;
        for(int i=0; i<n; i++)
            cin>>x[i]>>y[i];
        build();
        memset(dp,-1,sizeof dp);
        cout<<"Case #"<<k<<":\n";
        cout<<solve(0)<<'\n';
        if(k<t)
            cout<<'\n';
    }
    return 0;
}
```

