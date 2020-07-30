# Rectangle Cutting

Given a paper of size A x B . Task is to cut the paper into squares of any size
Find the minimum number of squares that can be cut from the paper.

Input  : 36 x 30
    
Output : 5
    
Explanation : 3 (squares of size 12x12) + 2 (squares of size 18x18)

Input  : 4 x 5
    
Output : 5
    
Explanation : 1 (squares of size 4x4) + 4 (squares of size 1x1)

    
m,n < 1000
    
Complexity : O(mn)

```cpp
int dp[1009][1009];
int solve(int m,int n)
{
    if(m==n)return 1;
    if(dp[m][n])return dp[m][n];
    int r=INT_MAX;
    for(int i=1;i<=m/2;i++)
        r=min(r,solve(i,n)+solve(m-i,n));
    for(int i=1;i<=n/2;i++)
        r=min(r,solve(m,i)+solve(m,n-i));
    return dp[m][n]=r;
}
int main()
{
    int m,n;
    cin>>m>>n;
    memset(dp,0,sizeof(dp));
    cout<<solve(m,n);
}
```
