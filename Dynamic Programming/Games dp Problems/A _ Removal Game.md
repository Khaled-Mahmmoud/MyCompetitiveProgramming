# Removal Game

There is a list of n numbers and two players who move alternately. On each move, a player removes either the first or last number
from the list, and their score increases by that number. Both players try to maximize their scores.
    
What is the maximum possible score for the first player when both players play optimally?
    
Input: 4 {4 5 1 3}, Output : 8

1 <= n <= 1000, 10^-9 <= v[i] <= 10^9
   
```cpp
vector<int>v;
long long dp[5009][5009];
long long get(int i,int j)
{
    if(dp[i][j])return dp[i][j];
    if(i==j)return v[i];
    if(i+1==j)return max(v[i],v[j]);
    return dp[i][j]=max(v[i]+min(get(i+2,j),get(i+1,j-1)),v[j]+min(get(i,j-2),get(i+1,j-1)));
}
int main()
{
    int n;
    cin>>n;
    v.resize(n);
    for(int i=0;i<n;i++)
    cin>>v[i];
    cout<<get(0,n-1)<<'\n';
    return 0;
}
```
Complexity : O(n^2)
