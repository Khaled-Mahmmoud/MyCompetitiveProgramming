# Functions again

[Problem Link](https://codeforces.com/contest/788/problem/A0)

```cpp
#define ll long long
int n;
int a[200005];
ll dp[200005][2];
ll ans = -1e15;
ll solve(int idx,int cur)
{

    if(idx==n)
        return 0;
       
    if(dp[idx][cur]+1e15)
        return dp[idx][cur];
    int x = 0;
    if(cur)
        x = -1;
    else
        x = 1;
    
    dp[idx][cur] = x * a[idx] + max(0ll,solve(idx+1,!cur));
   
    ans = max(ans,dp[idx][cur]);
    return dp[idx][cur];
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    n--;
    for(int i=0;i<n;i++)
        a[i] = abs(a[i]-a[i+1]);
   
    //memset(dp,-1e15,sizeof dp);   please note that there no way to memset -1e15 or any value except 0 and -1
    
    for(int i=0;i<200005;i++)
        dp[i][0] = dp[i][1] = -1e15;

    for(int i=n-1;i>=0;i--)
       dp[i][0] = solve(i,0);
       
    cout<<ans;
    
    return 0;
}
```
