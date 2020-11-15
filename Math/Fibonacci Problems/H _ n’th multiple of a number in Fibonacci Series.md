# n’th multiple of a number in Fibonacci Series

Given two integers n and k. Find position the n’th multiple of K in the Fibonacci series.

Input : k = 2, n = 3, Output : 9
            
3'rd multiple of 2 in Fibonacci Series is 34 which appears at position 9.

Fibonacci Series(F) : 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ...(neglecting the first 0).


A **Simple Solution** is to traverse Fibonacci numbers starting from first number
While traversing, keep track of counts of multiples of k. Whenever the count becomes n, return the position.

An **Efficient Solution** is based on below interesting property.
Fibonacci series is always periodic under modular representation. Below are examples.

F (mod 2) = 1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0
            
Here 0 is repeating at every 3rd index and the cycle repeats at every 3rd index. 

F (mod 3) = 1,1,2,0,2,2,1,0,1,1,2,0,2,2,1,0,

Here 0 is repeating at every 4th index and the cycle repeats at every 4rd index. 


**Why is Fibonacci Series Periodic under Modulo?**

Under modular representation, we know that each Fibonacci number will be represented as some residue 0 ? F (mod m) < m
Thus, there are only m possible values for any given F (mod m) and hence m*m = m^2 possible pairs of consecutive 
terms within the sequence. Since m^2 is finite, we know that some pair of terms must eventually repeat itself
Also, as any pair of terms in the Fibonacci sequence determines the rest of the sequence
we see that the Fibonacci series modulo m must repeat itself at some point, and thus must be periodic

Based on above fact, we can quickly find position of n’th multiple of K by simply finding first multiple
If position of first multiple is i, we return position as n*i

```cpp
const int MAX = 1000; 
int findPosition(int k, int n) 
{ 
    unsigned long long int f1 = 0,  
                           f2 = 1,  
                           f3; 
    for (int i = 2; i <= MAX; i++) 
    { 
        f3 = f1 + f2; 
        f1 = f2; 
        f2 = f3; 
        if (f2 % k == 0) 
        return n * i; 
    } 
} 
```
