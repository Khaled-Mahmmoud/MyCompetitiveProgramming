
# String to Palindrome

In this problem you are asked to convert a string into a palindrome with minimum number of operations.
The operations are described below:

- Add any character at any position
- Remove any character from any position
- Replace any character at any position with another character

```cpp
#include<bits/stdc++.h>
#define ll long long
using namespace std;
string str;int dp[1009][1009];
int solve(int i,int j)
{
    if(i>=j||(str[i]==str[j]&&i+1==j))
        return 0;
    int &rt = dp[i][j];
    if(~rt)
        return rt;
    if(str[i]==str[j])
        return rt = solve(i+1,j-1);
    return rt = min(solve(i+1,j),min(solve(i,j-1),solve(i+1,j-1)))+1;
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int t;cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>str;memset(dp,-1,sizeof dp);
        cout<<"Case "<<i<<":"<<" "<<solve(0,str.size()-1)<<'\n';
    }
}
```
