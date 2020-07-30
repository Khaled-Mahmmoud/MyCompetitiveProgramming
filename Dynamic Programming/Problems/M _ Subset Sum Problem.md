# Subset Sum Problem

Given a set of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum.
    
Input:  set[] = {3, 34, 4, 12, 5, 2}, sum = 9.
    
Output:  True.  

There is a subset (4, 5) with sum 9.
    
<< Memoization Method – Top Down Dynamic Programming >>
    
Complexity : O(n.sum)

```cpp
vector<int>v;int dp[1000][1000];
bool subset(int n,int sum)
{
    if(!sum)return true;
    if(!n)return false;
    int &rt = dp[n][sum];
    if(~rt)return rt;
    if(v[n-1]>sum)
        return rt = subset(n-1,sum);
    return subset(n-1,sum)||subset(n-1,sum-v[n-1]);
}
int main()
{
    int n,sum;cin>>n>>sum;v.resize(n);
    for(int i=0;i<n;i++)cin>>v[i];
    memset(dp,-1,sizeof(dp));
    if(subset(n,sum))
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}
```
<< Tabulation Method – Bottom Up Dynamic Programming >>
    
Complexity : O(n.sum)

```cpp
vector<int>v;
bool subset(int set[], int n, int sum) 
{ 
    bool dp[n+1][sum+1]; 
    for (int i = 0; i <= n; i++) 
      dp[i][0] = true; 
    for (int i = 1; i <= sum; i++) 
      dp[0][i] = false;
      
     for (int i = 1; i <= n; i++) 
     for (int j = 1; j <= sum; j++) 
     { 
         if(j<v[i-1]) 
         dp[i][j] = dp[i-1][j]; 
         else
           dp[i][j] = dp[i-1][j] || dp[i - 1][j-v[i-1]]; 
     } 
     return dp[n][sum]; 
} 
int main()
{
    int n,sum;cin>>n>>sum;v.resize(n);
    for(int i=0;i<n;i++)cin>>v[i];
    if(subset(n,sum))
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}
```
