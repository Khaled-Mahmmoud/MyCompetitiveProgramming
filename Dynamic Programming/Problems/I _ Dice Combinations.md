# Dice Combinations

Your task is to count the number of ways to construct sum n by throwing a dice one or more times
Each throw produces an outcome between 1 and 6,
For example, if n=3, there are 4 ways:

1+1+1 , 1+2 , 2+1 , 3
    
n <= 10^6

Print the number of ways modulo 10^9+7
    
**Solution**

dp[x] = number of ways to make sum x using numbers from 1 to 6
    
Summing over the possibilities gives dp[x] = dp[x-1] + dp[x-2] + dp[x-3] + dp[x-4] + dp[x-5] + dp[x-6]
We initialize by dp[0] = 1, saying there is one way with sum zero 

The complexity is O(n)
```cpp
int main()
{
    int n;cin>>n;
    vector<int>dp(n+1);
    dp[0]=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=6&&i-j>=0;j++)
           (dp[i]+=dp[i-j])%=mod;
    cout<<dp[n];
    return 0;
}
```
