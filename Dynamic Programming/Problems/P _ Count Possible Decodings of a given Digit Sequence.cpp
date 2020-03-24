/*

Count Possible Decodings of a given Digit Sequence
Let 1 represent ‘A’, 2 represents ‘B’, etc. 
Given a digit sequence, count the number of possible decodings of the given digit sequence.
Examples:

Input:  digits[] = "121"
Output: 3
// The possible decodings are "ABA", "AU", "LA"

Input: digits[] = "1234"
Output: 3
// The possible decodings are "ABCD", "LCD", "AWD"
An empty digit sequence is considered to have one decoding
It may be assumed that the input contains valid digits from 0 to 9 and there are no leading 0’s,
no extra trailing 0’s and no two or more consecutive 0’s.

This problem is recursive and can be broken in sub-problems. We start from end of the given digit sequence.
We initialize the total count of decodings as 0. We recur for two subproblems.
1) If the last digit is non-zero, recur for remaining (n-1) digits and add the result to total count.
2) If the last two digits form a valid character (or smaller than 27), recur for remaining (n-2) digits and
add the result to total count

*/

int dp[100000];
int countDecoding(string digits, int n) 
{ 
    if (n == 0 || n == 1) 
        return 1; 
    if(digits[0]=='0') 
          return 0; 
    if(dp[n])return dp[n];
    int count = 0;  
    if (digits[n-1] > '0') 
        count +=  countDecoding(digits, n-1); 
        
    if (digits[n-2] == '1' || (digits[n-2] == '2' && digits[n-1] < '7') ) 
        count +=  countDecoding(digits, n-2); 
  
    return dp[n] = count; 
} 
int main()
{
    int n;
    string s;
    cin>>s>>n;
    if(s=="0")
        cout<<0;
    else
        cout<<countDecoding(s,n);
}
