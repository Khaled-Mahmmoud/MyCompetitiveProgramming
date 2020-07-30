# paths top-left bottom-right

The problem is to count all the possible paths from top left to bottom right of a mXn matrix with the constraints that from each cell
you can either move only to right or down

Input :  m = 2, n = 2;

Output : 2
    
There are two paths

1) (0, 0) -> (0, 1) -> (1, 1)
2) (0, 0) -> (1, 0) -> (1, 1)

Input :  m = 2, n = 3;

Output : 3
    
There are three paths

1) (0, 0) -> (0, 1) -> (0, 2) -> (1, 2)
2) (0, 0) -> (0, 1) -> (1, 1) -> (1, 2)
3) (0, 0) -> (1, 0) -> (1, 1) -> (1, 2)

1<=M<=1000
    
1<=N<=1000
    

<< Memoization Method – Top Down Dynamic Programming >>

Complexity : O(mn)
    
```cpp
int dp[1009][1009];
int path(int m,int n)
{
    if(!m||!n)return 1;
    int &rt = dp[m][n];
    if(rt)return rt;
    return rt = path(m-1,n) + path(m,n-1);
}
int main()
{
    int t;cin>>t;while(t--)
    {
        memset(dp,0,sizeof(dp));
        int m,n;cin>>m>>n;
        cout<<path(m-1,n-1)<<'\n';
    }
    return 0;
}
```

<< Tabulation Method – Bottom Up Dynamic Programming >>
    
Complexity : O(mn)
    
```cpp
int path(int m,int n)
{
    int dp[m][n];
    for(int i=0;i<m;i++)
    for(int j=0;j<n;j++)
    {
        if(!i||!j)dp[i][j] = 1;
        dp[i][j]=dp[i-1][j]+dp[i][j-1];
    } 
    return dp[m-1][n-1];
}
```
Consider an n×n grid whose squares may have traps. It is not allowed to move to a square with a trap
Your task is to calculate the number of paths from the upper-left square to the lower-right square where
you only can move right or down.
    
4
    
....
    
.*..
    
...*

*...
    
n <= 1000
    
```cpp
    int n;
    cin>>n;
    char v[n][v];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>v[i][j];
    int dp[n][n];memset(dp,0,sizeof(dp));
    for(int i=0; i<n; i++)
        if(v[i][0]=='*')
            break;
        else
            dp[i][0]=1;
    for(int j=0; j<n; j++)
        if(v[0][j]=='*')
            break;
        else
           dp[0][j]=1;
    for(int i=1; i<n; i++)
        for(int j=1; j<n; j++)
            if(v[i][j]=='*')
                dp[i][j]=0;
            else
                dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;
    cout<<dp[n-1][n-1];
```
