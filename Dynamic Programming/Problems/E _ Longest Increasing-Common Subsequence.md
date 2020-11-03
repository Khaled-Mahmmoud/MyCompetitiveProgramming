# Longest Increasing Subsequence

The Longest Increasing Subsequence (LIS) problem is to find the length of the longest subsequence 
of a given sequence such that all elements of the subsequence are sorted in increasing order.
        
For example, the length of LIS for {10, 22, 9, 33, 21, 50, 41, 60, 80} is 6 and LIS is {10, 22, 33, 50, 60, 80}

```cpp
// a[n] = -1e9
// called with LIS(0, n)
int LIS(int i, int prev)
{
	if(i == n)
		return 0;
        int &rt = dp[i][prev];
        if(~rt)
            return rt;
	 rt = LIS(i+1, prev);	// LEAVE
	if(a[prev] <= a[i])
		rt = max(rt,LIS(i+1, i) + 1);
	return rt;
}
```      
Complexity : O(n * n)

```cpp
// called with LIS(0, -1)
int LIS(int i, int item)
{
	if(i == n)
		return 0;
        int &rt = dp[i][item];
        if(~rt)
            return rt;
	 rt = LIS(i+1, item);	// LEAVE
	if(item <= a[i])
		rt = max(rt,LIS(i+1, a[i]) + 1);
	return rt;
}
```      
Complexity : O(n * item) where item is maximum element in array

# Printing longest increasing subsequence

Complexity : O(nlogn)

using segment tree.

[problem1](https://www.spoj.com/problems/LMIS/)

[problem2](https://www.spoj.com/problems/ELIS/)

# Longest Common Subsequence

Given two sequences, find the length of longest subsequence present in both of them

1 <= size(str1), size(str2) <= 1000

**Memoization Method – Top Down Dynamic Programming**

Complexity : O(mn)
```cpp
int dp[1009][1009];
string s1,s2; int m,n;
int lcs(int i,int j)
{
    if(i==m||j==n)return 0;
    int &rt=dp[i][j];
    if(rt)return rt;
    if(s1[i]==s2[j])
        return rt = 1 + lcs(i+1,j+1);
    return rt = max(lcs(i,j+1),lcs(i+1,j));
}
int main()
{
    int t;cin>>t;while(t--)
    {
       
        cin>>m>>n>>s1>>s2;
        memset(dp,0,sizeof(dp));
        cout<<lcs(0,0)<<'\n';
    }
    return 0;
}

```
**Tabulation Method – Bottom Up Dynamic Programming**

Complexity : O(mn)
```cpp
int lcs(string s1, string s2, int m, int n )  
{  
    int dp[m + 1][n + 1];  
    for (int i = 0; i <= m; i++)  
    {  
        for (int j = 0; j <= n; j++)  
        {  
        if (i == 0 || j == 0)  
            dp[i][j] = 0;  
      
        else if (s1[i - 1] == s2[j - 1])  
            dp[i][j] = dp[i - 1][j - 1] + 1;  
      
        else
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);  
        }  
    }  
    return dp[m][n];  
}  
```

# Printing Longest Common Subsequence
```cpp
void lcs(string s1, string s2, int m, int n )
{
    int dp[m + 1][n + 1],i,j;
    for (i = 0; i <= m; i++)
    {
        for (j = 0; j <= n; j++)
        {
        if (i == 0 || j == 0)
            dp[i][j] = 0;

        else if (s1[i - 1] == s2[j - 1])
            dp[i][j] = dp[i - 1][j - 1] + 1;
        else
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    int index = dp[m][n];
    string s;
    s.assign(index,' ');
    i=m;j=n;
    while(i&&j)
    {
        if(s1[i-1]==s2[j-1])
        {
            s[--index] = s1[i-1];
            i--;j--;
        }
        else if(dp[i-1][j]>dp[i][j-1])
            i--;
        else j--;
    }
    cout<<s;
}
```
