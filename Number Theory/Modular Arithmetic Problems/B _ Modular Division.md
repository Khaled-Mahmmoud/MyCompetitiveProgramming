# Modular Division

### Linear Congruence Equation


Given three positive numbers a, c and m. Compute c/a under modulo m.
  
The task is basically to find a number x such that 

`(c/a) ≡ x (mod m)`
 
 `a * x ≡ c (mod m)` ==>> Linear Congruence Equation


Input  : a  = 3, c = 8, m = 5
Output : 1
Note that (1*3)%5 is same as 8%5

Input  : a  = 4, c = 11, m = 5
Output : 4
Note that (4*4)%5 is same as 11%5

    
 x % m = (c/a) % m
    
**Can we always do modular division?**

The answer is “NO”. First of all, like ordinary arithmetic, division by 0 is not defined.
  
For example, 4/0 is not allowed. In modular arithmetic, 4%0 is not allowed

**When is modular division defined?**

Modular division is defined when modular inverse of the divisor exists.
  
(The inverse of an integer ‘x’ is a another integer ‘y’ such that (x * y) % m = 1 where m is the modulus

When does inverse exist? inverse a number ‘a’ exists under modulo ‘m’ if ‘a’ and ‘m’ are co-prime )

**How to find modular division?**

The task is to compute c/a under modulo m.
  
1) First check if inverse of a under modulo m exists or not. 
   
a) If inverse doesn't exists (GCD of a and m is not 1), print "Division not defined"

b) Else return  "(inverse * c) % m" 

```cpp
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
```
Now consider the case where a and m are not coprime (gcd(a,m)≠1). Then the solution will not exist (for example 2⋅x=1 (mod 4) has no solution).

Let g=gcd(a,m), i.e. the greatest common divisor of a and m (which in this case is greater than one).

Then, if c is not divisible by g, there is no solution. In fact, for any x the left side of the equation a⋅x(mod m) , is always divisible by g, while the right-hand side is not divisible by it, hence it follows that there are no solutions.

If g divides c, then by dividing both sides of the equation by g (i.e. dividing a, c and m by g), we receive a new equation:

a′⋅x=c′(mod m′)

in which a′ and m′ are already relatively prime, and we have already learned how to handle such an equation. We get x′ as solution for x.

It is clear that this x′ will also be a solution of the original equation. However it will not be the only solution. It can be shown that the original equation has exactly g solutions, and they will look like this:

Xi = (x′+i⋅m′) (mod m)for i = 0 .... g−1

Summarizing, we can say that the number of solutions of the linear congruence equation is equal to either g = gcd(a,n) or to zero.

### Solution with the Extended Euclidean Algorithm

We can rewrite the linear congruence to the following Diophantine equation:

a⋅x + m⋅k = b, where x and k are unknown integers.

The method of solving this equation is described in the corresponding article Linear Diophantine equations and it consists of applying the Extended Euclidean Algorithm.
