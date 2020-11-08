# Nikita and string

[Problem Link](https://codeforces.com/problemset/problem/877/B)
```cpp
string str;
int n, dp[5005][5];
int solve(int i, int group)
{
    if(i == n)
        return 0;
    if(~dp[i][group])
        return dp[i][group];
    int ans = 0;
    if(str[i] == 'a')
    {
        if(group == 0 || group == 2)
            ans = solve(i + 1, group) + 1;
        else
            ans = max(solve(i + 1, group), solve(i + 1, group + 1) + 1);
    }
    else
    {
        if(group == 0)
            ans = max(solve(i + 1, group), solve(i + 1, group + 1) + 1);
        else if(group == 1)
            ans = solve(i + 1, group) + 1;
        else
            ans = solve(i + 1, group);
    }
    return dp[i][group] = ans;
}
int main()
{
    cin>>str;
    n = str.size();
    memset(dp,-1,sizeof dp);
    cout<<solve(0,0);
    return 0;
}

```

# Weather

```cpp
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[100009],n,dp[100009][2];
int solve(int idx,int group)
{
    if(idx==n-1)
        return 0;
    int &rt = dp[idx][group];
    if(~rt)return rt;
    if(a[idx]<0)
    {
        if(group)
            rt = solve(idx+1,group) + 1;
        else
            rt = solve(idx+1,group);
    }
    else if(a[idx]>0)
    {
        if(group)
            rt = solve(idx+1,group);
        else
            rt = min(1+solve(idx+1,group),solve(idx+1,group+1));
    }
    else
        rt = 1 + solve(idx+1,group);
    return rt;
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
       cin>>a[i];
    memset(dp,-1,sizeof dp);
    int ans = solve(1,0) + (a[0]>=0) + (a[n-1]<=0);
    cout<<ans<<'\n';
    return 0;
}
```
