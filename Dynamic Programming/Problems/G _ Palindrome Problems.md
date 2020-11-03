# Longest Palindromic Subsequence

Given a sequence, find the length of the longest palindromic subsequence .in it

input  : GeeksforGeeks

output : 5

**Memoization Method – Top Down Dynamic Programming**

```cpp
const int MAX = 1009;
string s;int dp[MAX][MAX];
int lps(int i,int j)
{
    if(i==j)return 1;
    if(s[i]==s[j]&&i+1==j)return 2;

    int &rt = dp[i][j];
    if(~rt)return rt;
    if(s[i]==s[j])
        return rt = 2+lps(i+1,j-1);
    return rt = max(lps(i+1,j),lps(i,j-1));
}
int main()
{
    int t;cin>>t;while(t--)
    {
        memset(dp,-1,sizeof(dp));cin>>s;
        cout<<lps(0,s.size()-1)<<endl;
    }
    return 0;
}
```
Complexity : O(n^2)


# Form a palindrome

[Problem link](https://practice.geeksforgeeks.org/problems/form-a-palindrome/0)

```cpp
#include<bits/stdc++.h>
using namespace std;
const int MAX = 1009;
string s;int dp[MAX][MAX];
int lps(int i,int j)
{
    if(i==j||(s[i]==s[j]&&i+1==j))
       return 0;

    int &rt = dp[i][j];
    if(~rt)return rt;
    if(s[i]==s[j])
        return rt = lps(i+1,j-1);
    return rt = min(lps(i+1,j),lps(i,j-1))+1;
}
int main()
{
    int t;cin>>t;while(t--)
    {
        memset(dp,-1,sizeof(dp));cin>>s;
        cout<<lps(0,s.size()-1)<<'\n';
    }
    return 0;
}
```

# Creating Palindrome

[Problem link](https://vjudge.net/problem/UVA-11753)

```cpp
int n,k,a[10009],dp[10009][29][29];
int solve(int i,int k1,int k2)
{
	int j=(n-1)-i-k1+k2;
	if(i>=j)return 0;
	if(~dp[i][k1][k2])
        return dp[i][k1][k2];
	if(k1+k2>k)
		return 30;
	if(a[i]==a[j])
	    return dp[i][k1][k2]=solve(i+1,k1,k2);
	return dp[i][k1][k2]=1+min(solve(i+1,k1,k2+1),solve(i,k1+1,k2));
}
int main()
{
    int t;cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n>>k;
        for(int j=0;j<n;j++)
            cin>>a[j];
        memset(dp,-1,sizeof dp);
        int ans = solve(0,0,0);
        cout<<"Case "<<i<<": ";
        if(!ans)
            cout<<"Too easy";
        else if(ans>k)
            cout<<"Too difficult";
        else
            cout<<ans;
        cout<<'\n';
    }
    return 0;
}
```
