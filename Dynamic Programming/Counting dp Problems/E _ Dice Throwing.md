# Dice Throwing

[Problem Link](https://vjudge.net/problem/UVA-10759?fbclid=IwAR1pRMAWC90nkOaFpJn5-DfvjPsMEpubs71VJqmdKak8Xo27NzK3xyB3tLU)


```
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,x;ll dp[25][145];
ll solve(int idx,int sum)
{
    if(idx==n)
        return sum>=x;
    ll &rt = dp[idx][sum];
    if(~rt)
        return rt;
    rt = 0;
    for(int i=1;i<=6;i++)
        rt += solve(idx+1,sum+i);
    return rt;
}
ll gcd(ll a,ll b)
{
    if(!b)return a;
    return gcd(b,a%b);
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    while(cin>>n&&cin>>x)
    {
        if(!n&&!x)break;
        memset(dp,-1,sizeof dp);
        ll down = 1,up = solve(0,0);
        for(int i=1;i<=n;i++)down*=6;
        ll g = gcd(up,down);
        up /= g; down /= g;
        if(down==1)
            cout<<up<<'\n';
        else
        cout<<up<<'/'<<down<<'\n';
    }
    return 0;
}

```
