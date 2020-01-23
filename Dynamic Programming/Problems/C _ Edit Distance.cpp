/*
Given two strings str1 and str2 and below operations that can performed on str1. Find minimum number of edits (operations) required to 
convert ‘str1’ into ‘str2’

Insert
Remove
Replace
All of the above operations are of equal cost.

Input:   str1 = "geek", str2 = "gesek"
Output:  1
We can convert str1 into str2 by inserting a 's'.

Input:   str1 = "cat", str2 = "cut"
Output:  1
We can convert str1 into str2 by replacing 'a' with 'u'.

Input:   str1 = "sunday", str2 = "saturday"
Output:  3
Last three and first characters are same.  We basically
need to convert "un" to "atur".  This can be done using
below three operations. 
Replace 'n' with 'r', insert t, insert a

What are the subproblems in this case?
The idea is process all characters one by one staring from either from left or right sides of both strings.
Let us traverse from right corner, there are two possibilities for every pair of character being traversed.
m: Length of str1 (first string)
n: Length of str2 (second string)
If last characters of two strings are same, nothing much to do
Ignore last characters and get count for remaining strings,So we recur for lengths m-1 and n-1.
Else (If last characters are not same), we consider all operations on ‘str1’, consider all three operations on 
last character of first  string, recursively compute minimum cost for all three operations and take minimum of three values.

Insert: Recur for m and n-1
Remove: Recur for m-1 and n
Replace: Recur for m-1 and n-1

GeeksforGeeks problem link : https://practice.geeksforgeeks.org/problems/edit-distance/0
m <= 1000
n <= 1000
*/


// << Memoization Method – Top Down Dynamic Programming >>

int dp[1009][1009];
int ed(string s1,string s2,int m,int n)
{
    if(m==0)return n;
    if(n==0)return m;
    if(dp[m][n])return dp[m][n];

    if(s1[m-1]==s2[n-1])
        return dp[m][n] = ed(s1,s2,m-1,n-1);
    return dp[m][n] = 1 + min(ed(s1,s2,m-1,n),min(ed(s1,s2,m,n-1),ed(s1,s2,m-1,n-1)));
}
//Complexity : O(mn)

// << Tabulation Method – Bottom Up Dynamic Programming >>

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
//Complexity : O(mn)
