/*
Count all possible paths from top left to bottom right of a mXn matrix
The problem is to count all the possible paths from top left to bottom right of a mXn matrix with the constraints that from each cell
you can either move only to right or down

Input :  m = 2, n = 2;
Output : 2
There are two paths
(0, 0) -> (0, 1) -> (1, 1)
(0, 0) -> (1, 0) -> (1, 1)

Input :  m = 2, n = 3;
Output : 3
There are three paths
(0, 0) -> (0, 1) -> (0, 2) -> (1, 2)
(0, 0) -> (0, 1) -> (1, 1) -> (1, 2)
(0, 0) -> (1, 0) -> (1, 1) -> (1, 2)

1<=M<=1000
1<=N<=1000
*/
int dp[1009][1009];
int path(int m,int n)
{
    if(m==1||n==1)return 1;
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
        cout<<path(m,n)<<'\n';
    }
    return 0;
}
