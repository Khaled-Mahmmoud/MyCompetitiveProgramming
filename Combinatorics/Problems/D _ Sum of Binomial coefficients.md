# Sum of Binomial coefficients

Given a positive integer n, the task is to find the sum of binomial coefficient.
    
nC0 + nC1 + nC2 + ……. + nCn-1 + nCn

**Method 1 (Brute Force)**

The idea is to evaluate each binomial coefficient term i.e nCr, where 0 <= r <= n and calculate the sum of all the terms

**Method 2 (Using Formula)**

nC0 + nC1 + nC2 + ……. + nCn-1 + nCn = 2^n

Proof :

We know, (1 + x)^n = nC0 + nC1 x + nC2 x2 + ..... + nCn x^n

we put x = 1
    
(1 + 1)^n = nC0 + nC1 + nC2 + ..... + nCn 

2^n = nC0 + nC1 + nC2 + ..... + nCn 

```cpp
int binomialCoeffSum(int n) 
{ 
    return (1 << n); 
} 
int main() 
{ 
    int n = 4; 
    cout<<binomialCoeffSum(n); 
    return 0; 
} 
```cpp
