/*
Program for factorial of a number
Factorial of a non-negative integer, is multiplication of all integers smaller than or equal to n
For example factorial of 6 is 6*5*4*3*2*1 which is 720

!n = n * (n-1) * (n-2) * (n-3) * .... * 1
!4 = 4 * 3 * 2 * 1
!6 = 6 * 5 * 4 * 3 * 2 * 1

Recursive Solution:
Factorial can be calculated using following recursive formula

  n! = n * (n-1)!
  0! = 1 
  1! = 1
  
  
unsigned int factorial(unsigned int n) 
{ 
    if(n == 0) 
        return 1; 
    return n * factorial(n - 1); 
} 

unsigned int factorial(unsigned int n) 
{ 
    int res = 1, i; 
    for(i = 2; i <= n; i++) 
        res *= i; 
    return res; 
} 

