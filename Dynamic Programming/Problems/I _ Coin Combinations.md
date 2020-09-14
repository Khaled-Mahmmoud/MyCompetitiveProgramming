# Coin Combinations

Consider a money system consisting of n coins. 
Each coin has a positive integer value.
Your task is to calculate the number of distinct ordered ways you can produce a money 
sum x using the available coins.
    
For example, if the coins are {2,3,5} and the desired sum is 9, there are 3 ways:

2 + 2 + 5
    
3 + 3 + 3
    
2 + 2 + 2 + 3

n <= 100
    
x <= 10^5

a[i] <= 10^6

**Solution**

dp[i][x] = number of ways to make value x using the first i coins
The complexity : O(nx)
    
```cpp
#define mod 1000000007
int n,a[102];
int dp[1000006][102];
int solve(int x,int j)
{
    if(!x)
        return 1;
    if(x<0)
        return 0;
    int &rt = dp[x][j];
    if(~rt)
        return rt;
    rt = 0;
    for(int i=j;i<n;i++)
        (rt += solve(x-a[i],i))%=mod;
    return rt;
}
int main()
{
    int x;
    cin>>n>>x;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    memset(dp,-1,sizeof dp);
    cout<<solve(x,0);
    return 0;
}
```
