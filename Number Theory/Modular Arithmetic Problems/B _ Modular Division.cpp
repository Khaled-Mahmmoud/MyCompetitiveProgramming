/*
Modular Division
Given three positive numbers a, b and m. Compute a/b under modulo m
The task is basically to find a number c such that (b * c) % m = a % m

Input  : a  = 8, b = 4, m = 5
Output : 2

Input  : a  = 8, b = 3, m = 5
Output : 1
Note that (1*3)%5 is same as 8%5

Input  : a  = 11, b = 4, m = 5
Output : 4
Note that (4*4)%5 is same as 11%5

    
    c % m = (a/b) % m
    
Can we always do modular division?
The answer is “NO”. First of all, like ordinary arithmetic, division by 0 is not defined
For example, 4/0 is not allowed. In modular arithmetic, 4%0 is not allowed

When is modular division defined?
Modular division is defined when modular inverse of the divisor exists
(The inverse of an integer ‘x’ is a another integer ‘y’ such that (x*y) % m = 1 where m is the modulus
When does inverse exist? inverse a number ‘a’ exists under modulo ‘m’ if ‘a’ and ‘m’ are co-prime )

How to find modular division?

The task is to compute a/b under modulo m.
1) First check if inverse of b under modulo m exists or not. 
    a) If inverse doesn't exists (GCD of b and m is not 1), 
          print "Division not defined"
    b) Else return  "(inverse * a) % m" 

*/


int gcdExtended(int a, int b, int *x, int *y); 
int modInverse(int b, int m) 
{ 
    int x, y; 
    int g = gcdExtended(b, m, &x, &y); 
    if (g != 1) 
        return -1; 
    return (x%m + m) % m; 
} 

void modDivide(int a, int b, int m) 
{ 
    a = a % m; 
    int inv = modInverse(b, m); 
    if (inv == -1) 
       cout << "Division not defined"; 
    else
       cout << "Result of division is " << (inv * a) % m; 
} 
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
int main() 
{ 
    int  a  = 8, b = 3, m = 5; 
    modDivide(a, b, m); 
    return 0; 
} 
