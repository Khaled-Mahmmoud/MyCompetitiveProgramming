/*
#########
22/1/2020
#########
Given weights and values of n items , put these items in a knapsack of capacity W to get the maximum total value in the knapsack
In other words, given two integer arrays val[0..n-1] and wt[0..n-1] which represent values and weights associated with n items 
respectively. Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that 
sum of the weights of this subset is smaller than or equal to W
You cannot break an item, either pick the complete item, or don’t pick it (0-1 property)

GeeksfroGeeks problem link : https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem/0
1 ≤ N ≤ 1000
1 ≤ W ≤ 1000
1 ≤ wt[i] ≤ 1000
1 ≤ val[i] ≤ 1000
*/

/*
Tabulation Method – Bottom Up Dynamic Programming 
------------------------------------------
val  wt | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
(0)  0  | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
(1)  1  | 0 | 1 | 1 | 1 | 1 | 1 | 1 | 1 |
(4)  3  | 0 | 1 | 1 | 4 | 5 | 5 | 5 | 5 |
(5)  4  | 0 | 1 | 1 | 4 | 5 | 6 | 6 | 9 |
(7)  5  | 0 | 1 | 1 | 4 | 5 | 7 | 8 | 9 |
------------------------------------------


*/
int main()
{
    int n,w;
    cin>>n>>w;
    vector<int>val(n),wt(n);
    for(auto &z:wt)cin>>z;
    for(auto &z:val)cin>>z;
    vector<vector<int>>dp(n+1,vector<int>(w+1,0));
    for(int i=0;i<=n;i++)
    for(int j=0;j<=w;j++)
    {
        if(!i||!j)
            dp[i][j] = 0;
        else
            {
                if(j<w[i-1])dp[i][j]=dp[i-1][j];
                else dp[i][j]=max(dp[i-1][j],v[i-1]+dp[i-1][j-w[i-1]]);
            }
    }
    cout<<dp[n][w];
}
