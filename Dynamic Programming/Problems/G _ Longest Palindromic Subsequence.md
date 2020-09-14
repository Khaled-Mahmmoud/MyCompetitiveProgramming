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
        cout<<lps(0,s.size()-1)<<'\n';
    }
    return 0;
}
```
Complexity : O(n^2)
