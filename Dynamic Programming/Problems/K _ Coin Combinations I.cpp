/*
Consider a money system consisting of n coins. Each coin has a positive integer value
Your task is to calculate the number of  distinct ways you can produce a money sum x using the available coins
For example, if the coins are {2,3,5} and the desired sum is 9, there are 8 ways:
2+2+5
2+5+2
5+2+2
3+3+3
2+2+2+3
2+2+3+2
2+3+2+2
3+2+2+2
*/
int main()
{
    int n,x;cin>>n>>x;
    vector<int>v(n);
    for(auto& z:v)cin>>z;
    vector<int>dp(n+1,1e9);
    dp[0]=1;
    for(int i=1;i<=x;i++)
    for(int j=0;j<n;j++)
    {
        if(i-a[i]>=0)
        dp[i] = + dp[i-a[i]];
    }
    if(dp[x]==1e9)
        cout<<-1;
    else 
        cout<<dp[x];
    return 0;
}
