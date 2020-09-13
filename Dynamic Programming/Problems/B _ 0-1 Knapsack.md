# 0-1 Knapsack

Given weights and values of n items , put these items in a knapsack of capacity W to get the maximum total 
value in the knapsack. In other words, given two integer arrays val[0..n-1] and wt[0..n-1] which represent
values and weights associated with n items respectively. Also given an integer W which represents knapsack
capacity. find out the maximum value subset of val[] such that sum of the weights of this subset is smaller
than or equal to W You cannot break an item, either pick the complete item, or don’t pick it (0-1 property)

1 ≤ N , W , wt[i] , va[i] ≤ 1000
  
**Memoization Method – Top Down Dynamic Programming**

In the following [recursion tree](https://github.com/Khaled-Mahmmoud/MyCompetitiveProgramming/blob/master/img/Dynamic%20Programming/recursion%20tree%200-1%20knapsack.png), K() refers to knapSack().
The two parameters indicated in the following recursion tree are n and W.  
The recursion tree is for following sample inputs.
wt[] = {1, 1, 1}, W = 2, val[] = {10, 20, 30}

Complexity : O(wn)

```cpp
const int MAX = 1009;
int dp[MAX][MAX];     // please do not use vector , it's runtime 
int wt[MAX], int val[MAX];
int knapSack(int n,int w)
{
      if (n == 0 || w == 0)
          return 0;
      if(dp[n][w])
          return dp[n][w];
      if (wt[n-1] > w)
         return dp[n][w] = knapSack(n-1,w);
      else
        return dp[n][w] = max(val[n-1] + knapSack(n-1,w-wt[n-1]),knapSack(n-1,w));
}
```

**Tabulation Method – Bottom Up Dynamic Programming**

[See This Table](https://github.com/Khaled-Mahmmoud/MyCompetitiveProgramming/blob/master/img/Dynamic%20Programming/table%200-1%20knapsack.png)

Complexity : O(wn)

```cpp
int main()
{
    int n,w;
    cin>>n>>w;
    vector<int>val(n),wt(n);
    for(auto &z:wt)cin>>z;
    for(auto &z:val)cin>>z;
    //vector<vector<int>>dp(n+1,vector<int>(w+1,0));
    int dp[n+1][w+1];  // please do not use 2d-vector in dp , it's slower
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
```
