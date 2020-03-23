/*

Finding number of digits in n’th Fibonacci number
Given a number n, find number of digits in n’th Fibonacci Numbers. First few Fibinacci numbers are 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ….

Input : n = 6
Output : 1
6'th Fibonacci number is 8 and it has 
1 digit.

Input : n = 12
Output : 3
12'th Fibonacci number is 144 and it has 
3 digits.
Recommended: Please solve it on “PRACTICE ” first, before moving on to the solution.
A simple solution is to find n’th Fibonacci Number and then count number of digits in it
This solution may lead to overflow problems for large values of n.

A direct way is to count number of digits in the nth Fibonacci number using below Binet’s Formula.

fib(n) = (Φn - Ψ-n) / √5
where
Φ = (1 + √5) / 2
Ψ = (1 - √5) / 2

The above formula can be simplified, 
fib(n) = round(Φn / ? 5) 
Here round function indicates nearest integer.

Count of digits in Fib(n) = Log10Fib(n)
                          = Log10(Φn / √5)
                          = n*Log10(Φ) - Log10√5
                          = n*Log10(Φ) - (Log105)/2
As mentioned in this G-Fact, this formula doesn’t seem to work and produce correct Fibonacci numbers 
due to limitations of floating point arithmetic. However, it looks viable to use this formula to find 
count of digits in n’th Fibonacci number

*/

long long numberOfDigits(long long n) 
{ 
    if (n == 1) 
        return 1; 
    // using phi = 1.6180339887498948 
    long double d = (n * log10(1.6180339887498948)) - ((log10(5)) / 2); 
  
    return ceil(d); 
} 
