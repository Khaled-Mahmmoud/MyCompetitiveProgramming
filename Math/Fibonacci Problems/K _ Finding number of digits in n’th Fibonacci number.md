# Finding number of digits in n’th Fibonacci number

Given a number n, find number of digits in n’th Fibonacci Numbers. First few Fibinacci numbers are 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ….

Input : n = 6, Output : 1
  
6'th Fibonacci number is 8 and it has 1 digit.

A **simple solution** is to find n’th Fibonacci Number and then count number of digits in it.
This solution may lead to overflow problems for large values of n.

A direct way is to count number of digits in the nth Fibonacci number using below **Binet’s Formula**.

```cpp
long long numberOfDigits(long long n) 
{ 
    if (n == 1) 
        return 1; 
    // using phi = 1.6180339887498948 
    long double d = n * log10(1.6180339887498948) - log10(5) / 2; 
  
    return ceil(d); 
} 
