# Form a palindrome

Given a string, find the minimum number of characters to be inserted to convert it to palindrome.

For Example:

ab: Number of insertions required is 1. bab or aba

aa: Number of insertions required is 0. aa

abcd: Number of insertions required is 3. dcbabcd

```cpp
#include<bits/stdc++.h>
using namespace std;
const int MAX = 1009;
string s;int dp[MAX][MAX];
int lps(int i,int j)
{
    if(i>=j||(s[i]==s[j]&&i+1==j))
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
