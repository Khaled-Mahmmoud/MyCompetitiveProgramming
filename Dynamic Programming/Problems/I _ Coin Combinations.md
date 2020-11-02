# Coin Combinations

Consider a money system consisting of n coins . Each coin has a positive integer value
Your task is to produce a sum of money x using the available coins in such a way that 
the number of coins is minimal.
    
For example, if the coins are {1,5,7} and the desired sum is 11, an optimal solution 
is 5+5+1 which requires 3 coins.
    
n <= 100
    
x <= 10^6

a[i] <= 10^6

**Solution**

dp[x] = minimum number of coins with sum x
    
```cpp
int dp[1000006];
int n;int a[102];
int solve(int x)
{
    if(!x)
        return 0;
    if(x<0)
        return 1e9-1;
    int &rt = dp[x];
    if(~rt)
        return rt;
    rt = 1e9;
    for(int i=0;i<n;i++)
        rt = min(rt,1 + solve(x-a[i]));
    return rt;
}
int main()
{
    int x;
    cin>>n>>x;
    for(int i=0;i<n;i++)
        cin>>a[i];
    memset(dp,-1,sizeof dp);
    int ans = solve(x);
    if(ans==1e9)
        cout<<-1;
    else
        cout<<ans;
    return 0;
}
```
The complexity : O(nx)
