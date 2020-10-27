# Smallest number divisible by n and has at-least k trailing zeros

Two integers n and k are given. Our task is to print K-rounding of n.
    
K-rounding is the minimum positive integer X, such that x ends with k or more zeros and is divisible by n.

Input :  n = 30, k = 3.
    
Output : 3000
    
3000 is the smallest number that has at-least k 0s and is divisible by n.
    
Input : n = 375, k = 4.
    
Output : 30000
    
**Method** 1 : The brute force approach is to start with result = 10^k. Check if result is divided by n

If yes, it’s the answer, else increase it by 10^k

Method 2 : The efficient approach is to calculate the LCM of 10^k and n.
    
Suppose, n = 375, k = 4.
    
result = 10000.
    
Now, LCM of 375 and 10000 is the lowest number divided by both of them.
    
It will contain k or more zeros (because it is multiple of 10^k) and will be a multiple of n as well.
```cpp
long long getRounding(long long n, long long k) 
{ 
    long long rounding = pow(10, k); 
    long long result = __gcd(rounding, n); 
    return ((rounding * n) / result); 
} 
int main() 
{ 
    long long n = 375, k = 4; 
    cout << getRounding(n, k); 
    return 0; 
}
```
