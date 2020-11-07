# Bath Queue

[Problem Link](https://codeforces.com/contest/28/problem/C)

```cpp
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 55;int n,m;
int w[N];double dp[N][N][N];ll c[N][N];
void init()
{
    for(int i=0;i<N;i++)
    for(int j=0;j<=i;j++)
    {
        if(!j||i==j)c[i][j] = 1;
        else c[i][j] = c[i-1][j-1] + c[i-1][j];
    }
}
double solve(int r,int s,int q)
{
    if(r==m)
        return !s?q:0;
    double &rt = dp[r][s][q];
    if(abs(rt+1)>1e-9)
        return rt;
    rt = 0;
    double p = 1.0;
    for(int i=0;i<=s;i++)
    {
        int large = (i+w[r]-1)/w[r];
        rt += c[s][i] * p * solve(r+1,s-i,max(q,large));
        p /= m;
    }
    return rt;
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    init();
    cin>>n>>m;
    for(int i=0;i<m;i++)cin>>w[i];
    memset(dp,-1,sizeof dp);
    cout<<fixed<<setprecision(10)<<solve(0,n,0);
    return 0;
}
```
