/*
Your task is to count the number of ways to construct sum n by throwing a dice one or more times
Each throw produces an outcome between 1 and 6
For example, if n=3, there are 4 ways:
1+1+1
1+2
2+1
3
CSES problem link : https://cses.fi/problemset/task/1633
n <= 10^6
Print the number of ways modulo 10^9+7
*/
#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;cin>>n;
    vector<int>dp(n+1);
    dp[0]=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=6&&i-j>=0;j++)
           (dp[i]+=dp[i-j])%=mod;
    cout<<dp[n];
    return 0;
}
