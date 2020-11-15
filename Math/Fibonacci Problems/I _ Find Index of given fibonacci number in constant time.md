# Find Index of given fibonacci number in constant time

We are given a Fibonacci number. We have to find index of given Fibonacci number.

**Method** 1 (Simple) : Simple approach is to find Fibonacci numbers up to given Fibonacci number and count number of iteration performed

**Method** 2 (Formula based) : But here, we needed to generate all the fibonacci number up to provided fibonacci number
But, there is quick solution for this problem. Let’s see how !

Note that computing log of a number is O(1) operation in most of the platforms 

Fibonacci number is described as,
Fn = 1 / sqrt(5) * (pow(a,n) – pow(b,n)) where a = 1 / 2 ( 1 + sqrt(5) ) and b = 1 / 2 ( 1 – sqrt(5) )

On neglecting pow(b, n) which is very small for large value of n, we get n = round { 2.078087 * log(Fn) + 1.672276 }

where round means round to nearest integer.

```cpp
int findIndex(int n) 
{ 
    return round(2.078087 * log(n) + 1.672276); 
} 
```
