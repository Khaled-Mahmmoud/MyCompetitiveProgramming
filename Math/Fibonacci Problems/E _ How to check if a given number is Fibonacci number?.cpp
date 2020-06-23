/*


Given a number ‘n’, how to check if n is a Fibonacci number. First few Fibonacci numbers are 
0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 141, ..

Examples :

Input : 8
Output : Yes

Input : 34
Output : Yes

Input : 41
Output : No
A simple way is to generate Fibonacci numbers until the generated number is greater than or equal to ‘n’
Following is an interesting property about Fibonacci numbers that can also be used to check if a given number is Fibonacci or not
A number is Fibonacci if and only if one or both of (5*n^2 + 4) or (5*n^2 – 4) is a perfect square (Source: Wiki)
Following is a simple program based on this concept


*/


bool isPerfectSquare(int x) 
{ 
    int s = sqrt(x); 
    return (s*s == x); 
} 
  
bool isFibonacci(int n) 
{ 
    // n is Fibinacci if one of 5*n*n + 4 or 5*n*n - 4 or both 
    return isPerfectSquare(5*n*n + 4) || isPerfectSquare(5*n*n - 4); 
} 
