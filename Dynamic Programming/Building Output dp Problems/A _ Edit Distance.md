# Edit Distance


Given two strings str1 and str2 and below operations that can performed on str1. 
    
Find minimum number of edits (operations) required to convert ‘str1’ into ‘str2’

1) Insert
2) Remove
3) Replace

**Solution** : 
The idea is process all characters one by one staring from either from left or right sides of both strings.
Let us traverse from right corner, there are two possibilities for every pair of character being traversed.
    
m: Length of str1 (first string)
    
n: Length of str2 (second string)
    

1) Insert: Recur for m and n-1
2) Remove: Recur for m-1 and n
3) Replace: Recur for m-1 and n-1

**Memoization Method – Top Down Dynamic Programming**
```cpp
int dp[1009][1009];
string str1,str2;
int solve(int m,int n)
{
    if(m==0)return n;
    if(n==0)return m;

    int &rt = dp[m][n];
    if(~rt)return rt;

    if(str1[m-1]==str2[n-1])
        return rt = solve(m-1,n-1);
    return rt = 1 + min(solve(m-1,n),min(solve(m,n-1),solve(m-1,n-1)));
}
```
Complexity : O(mn)

**Tabulation Method – Bottom Up Dynamic Programming**
```cpp
int ed(string s1,string s2,int m,int n)
{
    int dp[m+1][n+1]; // please use 2d-array in dp , not to use 2d-vector , because 2d-vector is slower
    for(int i=0;i<=m;i++)
    for(int j=0;j<=n;j++)
    {
        if(i==0)dp[i][j]=j;
        else if(j==0)dp[i][j]=i; // please use else
        else if(s1[i-1]==s2[j-1]) // please use else
            dp[i][j]=dp[i-1][j-1];
        else
            dp[i][j]=1+min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));
    }
    return dp[m][n];
}
```
Complexity : O(mn)

# Printing Edit Distance

```cpp
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int dp[1009][1009];
string str1,str2;
int cnt,idx;
int solve(int m,int n)
{
    if(m==0)return n;
    if(n==0)return m;

    int &rt = dp[m][n];
    if(~rt)return rt;

    if(str1[m-1]==str2[n-1])
        return rt = solve(m-1,n-1);
    return rt = 1 + min(solve(m-1,n),min(solve(m,n-1),solve(m-1,n-1)));
}
void print(int m,int n)
{
    if(m==0)
    {
        while(n--)
            cout<<++cnt<<" Insert 1,"<<str2[n]<<'\n';
        return;
    }
    if(n==0)
    {
        while(m)
        cout<<++cnt<<" Delete "<<m--<<'\n';
        return;
    }

    if(str1[m-1]==str2[n-1])
    {
        idx--;
        print(m-1,n-1);
        return;
    }

    int optimal = dp[m][n];
    if(optimal == 1+solve(m-1,n))
    {
        cout<<++cnt<<" Delete "<<idx--<<'\n';
        print(m-1,n);
    }
    else if(optimal == 1+solve(m,n-1))
    {
        cout<<++cnt<<" Insert "<<idx+1<<','<<str2[n-1]<<'\n';
        print(m,n-1);
    }
    else
    {
        cout<<++cnt<<" Replace "<<idx--<<','<<str2[n-1]<<'\n';
        print(m-1,n-1);
    }
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    while(getline(cin,str1)&&getline(cin,str2))
    {
        memset(dp,-1,sizeof dp);
        cout<<solve(str1.size(),str2.size())<<'\n';
        cnt = 0;idx = str1.size();
        print(str1.size(),str2.size());
    }
    return 0;
}
```
