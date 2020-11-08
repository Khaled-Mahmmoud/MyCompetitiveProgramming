# Functions again

[Problem Link](https://codeforces.com/contest/788/problem/A)

```cpp
#define ll long long
int n;
int a[200005];
ll dp[200005][2];
ll ans = -1e15;
ll solve(int idx,int c)
{
 
    if(idx==n)
        return 0;
    ll &rt = dp[idx][c];
    if(~rt)
        return rt;
    rt =max(0ll,(c?-1:1) * a[idx] + solve(idx+1,!c));
    ans = max(ans,rt);
    return rt;
}
int main()
{
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>a[i];
    n--;
    for(int i=0; i<n; i++)
        a[i] = abs(a[i]-a[i+1]);
 
   memset(dp,-1,sizeof(dp));
 
    for(int i=n-1; i>=0; i--)
        dp[i][0] = solve(i,0);
 
    cout<<ans;
    return 0;
}
```
