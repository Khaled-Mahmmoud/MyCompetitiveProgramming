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
    if(dp[idx][c]+1e15)
        return dp[idx][c];
    dp[idx][c] =max(0ll,(c?-1:1) * a[idx] + solve(idx+1,!c));
    ans = max(ans,dp[idx][c]);
    return dp[idx][c];
}
int main()
{
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>a[i];
    n--;
    for(int i=0; i<n; i++)
        a[i] = abs(a[i]-a[i+1]);
    for(int i=0; i<200005; i++)
        dp[i][0] = dp[i][1] = -1e15;
 
    for(int i=n-1; i>=0; i--)
        dp[i][0] = solve(i,0);
        
    cout<<ans;
    return 0;
}
```
