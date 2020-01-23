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


/*
Consider a money system consisting of n coins. Each coin has a positive integer value
Your task is to calculate the number of distinct ways you can produce a money sum x using the available coins
For example, if the coins are {2,3,5} and the desired sum is 9, there are 8 ways:
2+2+5
2+5+2
5+2+2
3+3+3
2+2+2+3
2+2+3+2
2+3+2+2
3+2+2+2
n <= 100
x <= 10^6
a[i] <= 10^6
CSES problem link : https://cses.fi/problemset/task/1635
Solution :
dp[x] = number of ways to make value x
The complexity : O(nx)
*/
int main()
{
    int n,x;cin>>n>>x;
    vector<int>v(n);
    for(auto& z:v)cin>>z;
    vector<int>dp(n+1,0);
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

/*
Consider a money system consisting of n coins. Each coin has a positive integer value
Your task is to calculate the number of  distinct ordered ways you can produce a money sum x using the available coins
For example, if the coins are {2,3,5} and the desired sum is 9, there are 3 ways:
2+2+5
3+3+3
2+2+2+3

n <= 100
x <= 10^6
a[i] <= 10^6
CSES problem link : https://cses.fi/problemset/task/1636
Solution :
dp[i][x] = number of ways to make value x using the first i coins
The complexity : O(nx)
*/

    int mod = 1e9+7;
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for (int& z: v)
        cin >> z;

    vector<vector<int>> dp(n+1,vector<int>(x+1,0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= x; j++)
        {
            dp[i][j] = dp[i-1][j];
            int left = j-v[i-1];
            if (left >= 0)
            {
                (dp[i][j] += dp[i][left]) %= mod;
            }
        }
    }
    cout << dp[n][x] << endl;
