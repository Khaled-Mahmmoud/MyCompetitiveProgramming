# Factorial

Factorial of a non-negative integer, is multiplication of all integers smaller than or equal to n

For example factorial of 6 is 6*5*4*3*2*1 which is 720

`!n = n * (n-1) * (n-2) * (n-3) * .... * 1`

!4 = 4 * 3 * 2 * 1

!6 = 6 * 5 * 4 * 3 * 2 * 1

Recursive Solution:

Factorial can be calculated using following recursive formula

n! = n * (n-1)!
  
0! = 1 
  
1! = 1
  
```cpp
int factorial(int n) 
{ 
    if(n == 0) 
        return 1; 
    return n * factorial(n - 1); 
} 
int factorial(int n) 
{ 
    int res = 1; 
    for(int i = 1; i <= n; i++) 
        res *= i; 
    return res; 
} 
```
**Facts**

- n! % x = 0 where x <= n
- Wilson's theorem: (p-1)!%p = p-1 IFF p is prime
- 2! is the only prime factorial

### Number of factorial digits?
 
how many digit for 1000? 1050? 9000 ? 9999? 4 digits. Use 1 + (int)log10(n)

pow(10, log10(X) ) = X 

log(a * b) = log(a)+log(b)

log(n!) = log(1) + log(2) .... log(n)


### What about calc gcd(m, n!)

Let m =  2^3 * 5^7

Let n! =  2^10 * 5^3 * 11^3

then gcd is min of each power

gcd = 2 ^ min(3, 10) * 5 ^ min(7, 3) * 11 ^ min(0, 3)
