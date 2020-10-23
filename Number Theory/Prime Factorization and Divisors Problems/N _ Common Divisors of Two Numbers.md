# Common Divisors of Two Numbers

Given two integer numbers, the task is to find count of all common divisors of given numbers?

Input : a = 12, b = 24
    
Output: 6
    
// all common divisors are 1, 2, 3, 4, 6 and 12

Input : a = 3, b = 17
    
Output: 1
    
// all common divisors are 1

Input : a = 20, b = 36
    
Output: 3
    
// all common divisors are 1, 2, 4

A **simple solution** is to first find all divisors of first number and store them in an array or hash
Then find common divisors of second number and store them. Finally print count common elements of two stored arrays or hash.

A **better solution** is to calculate the greatest common divisor (gcd) of given two numbers
and then count divisors of that gcd
```cpp
int gcd(int a, int b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b%a, a); 
} 
int commDiv(int a,int b) 
{ 
    int n = gcd(a, b);   
    int result = 0; 
    for (int i=1; i<=sqrt(n); i++) 
    { 
        if (n%i==0) 
        { 
            if (n/i == i) 
                result += 1; 
            else
                result += 2; 
        } 
    } 
    return result; 
} 
int main() 
{ 
    int a = 12, b = 24; 
    cout << commDiv(a, b); 
    return 0; 
} 
```
