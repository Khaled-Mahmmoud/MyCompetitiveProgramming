# Fractional Knapsack Problem

`Greedy`

Given weights and values of n items, we need to put these items in a knapsack
of capacity W to get the maximum total value in the knapsack.

Input:
Items as (value, weight) pairs
arr[] = {{60, 10}, {100, 20}, {120, 30}}
Knapsack Capacity, W = 50;

Output:
Maximum possible value = 220
by taking items of weight 20 and 30 kg
  
In **Fractional Knapsack**, we can break items for maximizing the total value of knapsack.
This problem in which we can break an item is also called the fractional knapsack problem

Input : 
Same as above
   
Output :
Maximum possible value = 240,
By taking full items of 10 kg, 20 kg and 
2/3rd of last item of 30 kg
   
An **efficient solution** is to use **Greedy** approach. The basic idea of the greedy approach is 
to calculate the `ratio = value/weight` for each item and sort the item on basis of this ratio
Then take the item with the highest ratio and add them until we can’t add the next item as
a whole and at the end add the next item as much as we can. Which will always be the optimal
solution to this problem

```cpp
struct item
{
    int value,weight;
    item(int value,int weight):value(value),weight(weight){}
};
bool cmp(struct item a,struct item b)
{
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1>r2;
    
}
double fraction(struct item arr[],int w,int n)
{
    sort(arr,arr+n,cmp);
    int curweight = 0;
    double finalvalue = 0.0;
    for(int i=0;i<n;i++)
    {
        if(curweight + arr[i].weight <= w)
        {
            curweight+=arr[i].weight;
            finalvalue +=arr[i].value;
        }
        else
        {
            double remain = w - curweight;
            finalvalue += arr[i].value * (remain/arr[i].weight);
            break;
        }
    }
    return finalvalue;
}
int main()
{
    int w = 50;
    item arr[] = {{60,10},{100,20},{120,30}};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<fraction(arr,w,n);
    return 0;
}
```

# 0-1 Knapsack

`Subset Style dp`

Given weights and values of n items , put these items in a knapsack of capacity W to get the maximum total 
value in the knapsack. In other words, given two integer arrays val[0..n-1] and wt[0..n-1] which represent
values and weights associated with n items respectively. Also given an integer W which represents knapsack
capacity. find out the maximum value subset of val[] such that sum of the weights of this subset is smaller
than or equal to W You cannot break an item, either pick the complete item, or don’t pick it (0-1 property)

1 ≤ N , W , wt[i] , va[i] ≤ 1000
  
**Memoization Method – Top Down Dynamic Programming**

In the following recursion tree, K() refers to knapSack().
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
        return dp[n][w] = max(knapSack(n-1,w), val[n-1] + knapSack(n-1,w-wt[n-1]));
}
```

**Tabulation Method – Bottom Up Dynamic Programming**

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
