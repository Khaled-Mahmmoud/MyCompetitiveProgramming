# Dice Combinations	

Your task is to count the number of ways to construct sum n by throwing a dice one or more times	
Each throw produces an outcome between 1 and 6.	

For example, if n = 3, there are 4 ways.	

1+1+1 , 1+2 , 2+1 , 3	

n <= 10^6	

Print the number of ways modulo 10^9+7	

**Solution**	

dp[x] = number of ways to make sum x using numbers from 1 to 6	

Summing over the possibilities gives `dp[x] = dp[x-1] + dp[x-2] + dp[x-3] + dp[x-4] + dp[x-5] + dp[x-6]`	
We initialize by dp[0] = 1, saying there is one way with sum zero 	

The complexity is O(n)	

```cpp	
#define mod 1000000007
int dp[1000006];
int solve(int n)
{
    if(!n)
        return 1;
    if(n<0)
        return 0;
    int &rt = dp[n];
    if(~rt)
        return rt;
    rt = 0;
    for(int i=1;i<=6;i++)
        (rt += (solve(n-i))%mod)%=mod;
    return rt;
}
int main()
{
    int n;
    cin>>n;
    memset(dp,-1,sizeof dp);
    cout<<solve(n);
```
