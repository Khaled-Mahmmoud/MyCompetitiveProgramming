/*

Modular Division
Given three positive numbers a, c and m. Compute c/a under modulo m
The task is basically to find a number x such that 

  (c/a) = x (mod m)
  a * x = c (mod m)

Input  : a  = 4, c = 8, m = 5
Output : 2

Input  : a  = 3, c = 8, m = 5
Output : 1
Note that (1*3)%5 is same as 8%5

Input  : a  = 4, c = 11, m = 5
Output : 4
Note that (4*4)%5 is same as 11%5

    
    x % m = (c/a) % m
    
Can we always do modular division?
The answer is “NO”. First of all, like ordinary arithmetic, division by 0 is not defined
For example, 4/0 is not allowed. In modular arithmetic, 4%0 is not allowed

When is modular division defined?
Modular division is defined when modular inverse of the divisor exists
(The inverse of an integer ‘x’ is a another integer ‘y’ such that (x*y) % m = 1 where m is the modulus
When does inverse exist? inverse a number ‘a’ exists under modulo ‘m’ if ‘a’ and ‘m’ are co-prime )

How to find modular division?

The task is to compute c/a under modulo m.
1) First check if inverse of a under modulo m exists or not. 
    a) If inverse doesn't exists (GCD of a and m is not 1), 
          print "Division not defined"
    b) Else return  "(inverse * c) % m" 

*/


int gcdExtended(int a, int b, int *x, int *y) 
{ 
    if (a == 0) 
    { 
        *x = 0, *y = 1; 
        return b; 
    } 
  
    int x1, y1; 
    int gcd = gcdExtended(b%a, a, &x1, &y1); 
    *x = y1 - (b/a) * x1; 
    *y = x1; 
  
    return gcd; 
} 
int modInverse(int a, int m) 
{ 
    int x, y; 
    int g = gcdExtended(a, m, &x, &y); 
    if (g != 1) 
        return -1; 
    return (x%m + m) % m; 
} 

void modDivide(int a, int c, int m) 
{ 
    c = c % m; 
    int inv = modInverse(a, m); 
    if (inv == -1) 
       cout << "Division not defined"; 
    else
       cout << "Result of division is " << (inv * c) % m; 
} 
int main() 
{ 
    int  a  = 3, c = 8, m = 5; 
    modDivide(a, c, m); 
    return 0; 
} 
