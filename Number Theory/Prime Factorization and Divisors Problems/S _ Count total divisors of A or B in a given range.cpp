/*


Count total divisors of A or B in a given range
Given four integers m, n, a, b. Find how many integers from range m to n are divisible by a or b.

Examples :

Input: 3 11 2 3
Output: 6
Explanation:
m = 3, n = 11, a = 2, b = 3
There are total 6 numbers from 3 to 
11 which are divisible by 2 or 3 i.e, 
3, 4, 6, 8, 9, 10 

Input: arr[] = {11, 1000000, 6, 35}
Output: 190475

A Naive approach is to run a loop from m to n and count all numbers which are divisible by either a or b
Time complexity of this approach will be O(m – n) which will definitely time out for large values of m.

An efficient approach is to use simple LCM and division method.

Divide n by a to obtain total count of all numbers(1 to n) divisible by ‘a’.
Divide m-1 by a to obtain total count of all numbers(1 to m-1) divisible by ‘a’.
Subtract the count of step 1 and 2 to obtain total divisors in range m to n.
Now we have a total number of divisors of ‘a’ in given range. Repeat the above to count total divisors of ‘b’.
Add these to obtain total count of divisors ‘a’ and ‘b’.
But the number divisible by both a and b counted twice. Therefore to remove this ambiguity we can use LCM of a and b 
to count total number divisible by both ‘a’ and ‘b’.

Find LCM of ‘a’ and ‘b’.
Divide n by LCM to obtain the count of numbers(1 to n) divisible by both ‘a’ and ‘b’.
Divide m-1 by LCM to obtain the count of numbers(1 to m-1) divisible by both ‘a’ and ‘b’.
Subtract the count of step 2 and 3 to obtain total divisors of both ‘a’ and ‘b’.
Now subtract this result from the previous calculated result to find total count of all unique divisors of ‘a’ or ‘b’.

*/

int FindLCM(int a, int b) 
{ 
    return (a * b) / __gcd(a, b); 
} 
int rangeDivisor(int m, int n, int a, int b) 
{ 
    int lcm = FindLCM(a, b); 
  
    int a_divisor = n / a - (m - 1) / a; 
    int b_divisor = n / b - (m - 1) / b; 
  
    int common_divisor = n / lcm - (m - 1) / lcm; 
  
    int ans = a_divisor + b_divisor - common_divisor; 
    return ans; 
} 
// Time complexity: O(log(MAX(a, b))
