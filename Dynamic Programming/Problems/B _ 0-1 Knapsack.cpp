/*
Given weights and values of n items , put these items in a knapsack of capacity W to get the maximum total 
value in the knapsack In other words, given two integer arrays val[0..n-1] and wt[0..n-1] which represent
values and weights associated with n items respectively. Also given an integer W which represents knapsack
capacityfind out the maximum value subset of val[] such that sum of the weights of this subset is smaller
than or equal to W You cannot break an item, either pick the complete item, or don’t pick it (0-1 property)

GeeksfroGeeks problem link : https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem/0
1 ≤ N ≤ 1000
1 ≤ W ≤ 1000
1 ≤ wt[i] ≤ 1000
1 ≤ val[i] ≤ 1000
*/
/*
<< Memoization Method – Top Down Dynamic Programming >>
In the following recursion tree, K() refers to knapSack().
The two parameters indicated in the following recursion tree are n and W.  
The recursion tree is for following sample inputs.
wt[] = {1, 1, 1}, W = 2, val[] = {10, 20, 30}

                       K(3, 2)         ---------> K(n, W)
                   /            \ 
                 /                \               
            K(2,2)                  K(2,1)
          /       \                  /    \ 
        /           \              /        \
       K(1,2)      K(1,1)        K(1,1)     K(1,0)
       /  \         /   \          /   \
     /      \     /       \      /       \
K(0,2)  K(0,1)  K(0,1)  K(0,0)  K(0,1)   K(0,0)
Recursion tree for Knapsack capacity 2 units and 3 items of 1 unit weight

Complexity : O(mn)

*/
const int MAX = 1009;
int dp[MAX][MAX];     // please do not use vector , it's runtime 
int knapSack(int w, int wt[], int val[], int n)
{
      if (n == 0 || w == 0)
          return 0;
      if(dp[n][w])
          return dp[n][w];
      if (wt[n-1] > w)
         return dp[n][w] = knapSack(w, wt, val, n-1);
      else
        return dp[n][w] = max( val[n-1] + knapSack(w-wt[n-1], wt, val, n-1),knapSack(w, wt, val, n-1) );
}
/*
<< Tabulation Method – Bottom Up Dynamic Programming >>
------------------------------------------
val  wt | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
(0)  0  | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
(1)  1  | 0 | 1 | 1 | 1 | 1 | 1 | 1 | 1 |
(4)  3  | 0 | 1 | 1 | 4 | 5 | 5 | 5 | 5 |
(5)  4  | 0 | 1 | 1 | 4 | 5 | 6 | 6 | 9 |
(7)  5  | 0 | 1 | 1 | 4 | 5 | 7 | 8 | 9 |
------------------------------------------

Complexity : O(mn)

*/
int main()
{
    int n,w;
    cin>>n>>w;
    vector<int>val(n),wt(n);
    for(auto &z:wt)cin>>z;
    for(auto &z:val)cin>>z;
    //vector<vector<int>>dp(n+1,vector<int>(w+1,0));
    int dp[n+1][w+1];  // please do not 2d-vector in dp , it's slower
    for(int i=0;i<=n;i++)
    for(int j=0;j<=w;j++)
    {
        if(!i||!j)
            dp[i][j] = 0;
        else
            {
                if(j<wt[i-1])dp[i][j]=dp[i-1][j];
                else dp[i][j]=max(dp[i-1][j],val[i-1]+dp[i-1][j-wt[i-1]]);
            }
    }
    cout<<dp[n][w];
}
