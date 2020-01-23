/*
Consider a money system consisting of n coins . Each coin has a positive integer value
Your task is to produce a sum of money x using the available coins in such a way that the number of coins is minimal.
For example, if the coins are {1,5,7} and the desired sum is 11, an optimal solution is 5+5+1 which requires 3 coins.
n <= 100
x <= 10^6
a[i] <= 10^6
CSES problem link : https://cses.fi/problemset/task/1634
Solution :
dp[x] = minimum number of coins with sum x
The complexity : O(nx)
*/
int main()
{
    int n,x;cin>>n>>x;
    vector<int>v(n);
    for(auto& z:v)cin>>z;
    vector<int>dp(n+1,1e9);
    dp[0]=0;
    for(int i=1;i<=x;i++)
    for(int j=0;j<n;j++)
    {
        if(i-a[i]>=0)
        dp[i] = min(dp[i],dp[i-a[i]]+1);
    }
    if(dp[x]==1e9)
        cout<<-1;
    else 
        cout<<dp[x];
    return 0;
}
