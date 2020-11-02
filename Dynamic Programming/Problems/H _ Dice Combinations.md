# Dice Combinations	

Your task is to count the number of ways to construct sum n by throwing a dice one or more times. Each throw produces an outcome between 1 and 6.	

For example, if n = 3, there are 4 ways.	

1+1+1 , 1+2 , 2+1 , 3	

n <= 10^6	

Print the number of ways modulo 10^9+7	

```cpp	
#define mod 1000000007
int dp[1000006];
int solve(int n)
{
    if(!n)
        return 1;
    if(n<0)
        return 0;
    int &rt = dp[n];
    if(~rt)
        return rt;
    rt = 0;
    for(int i=1;i<=6;i++)
        (rt += solve(n-i))%=mod;
    return rt;
}
int main()
{
    int n;
    cin>>n;
    memset(dp,-1,sizeof dp);
    cout<<solve(n);
}

```
The complexity : O(n * 6)	


# Dice Combinations	II

Your task is to count the number of ways to construct sum n by throwing a dice one or more times. Each throw produces an outcome between 1 and 6.  Changing the order of listing does not increase the count.

For example, if n = 3, there are 3 ways.	

1+1+1 , 1+2 , 3	

n <= 10^6	

Print the number of ways modulo 10^9+7	

```cpp	
#define mod 1000000007
int dp[1000006][7];
int solve(int n,int j)
{
    if(!n)
        return 1;
    if(n<0)
        return 0;
    int &rt = dp[n][j];
    if(~rt)
        return rt;
    rt = 0;
    for(int i=j;i<=6;i++)
        (rt += solve(n-i,i))%=mod;
    return rt;
}
int main()
{
    int n;
    cin>>n;
    memset(dp,-1,sizeof dp);
    cout<<solve(n,1);
}
```
The complexity : O(n * 6)	
