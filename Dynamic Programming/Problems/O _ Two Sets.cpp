/*
Your task is to count the number of ways numbers 1,2,…,n can be divided into two sets of equal sum
For example, if n=7, there are four solutions:
{1,3,4,6} and {2,5,7}
{1,2,5,6} and {3,4,7}
{1,2,4,7} and {3,5,6}
{1,6,7} and {2,3,4,5}

Print the answer modulo 10^9+7
1 <= n <= 500

solution :
If we are to have two subsets of equal sum, they must sum to half the total sum each. This means if the total sum n(n+1)/2 is odd
the answer is zero (no possibilities). Otherwise we get the number of ways to reach n(n+1)/4 using subsets of the numbers 1..n-1
Why n-1? Because by only considering numbers up to n-1, we always put n in the second set, and therefore only count each pair of 
sets once (otherwise we count every pair of sets twice)

Complexity : O(nx)
*/

int main()
{
    int n,mod=1e9+7;
    cin>>n;
    int x=n*(n+1)/2;
    if(x & 2){cout<<0;return 0;}
    x/=2;
    int dp[n][x+1];
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(int i=1;i<n;i++)
    for(int j=0;j<=x;j++)
    {
        dp[i][j]=dp[i-1][j];
        if(j-i>=0)
            (dp[i][j]+=dp[i-1][j-i])%=mod;
    }
    cout<<dp[n-1][x];
    return 0;
}
