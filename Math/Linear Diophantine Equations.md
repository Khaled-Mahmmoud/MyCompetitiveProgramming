# Linear Diophantine Equations

A Diophantine equation is a polynomial equation, usually in two or more unknowns, such that only the integral solutions are required.
An Integral solution is a solution such that all the unknown variables take only integer values.

Given three integers a, b, c representing a linear equation of the form : ax + by = c. 
Determine if the equation has a solution such that x and y are both integral values.

Input : a = 3, b = 6, c = 9

Output: Possible

Explanation : The Equation turns out to be, 
3x + 6y = 9 one integral solution would be 
x = 1 , y = 1

Input : a = 3, b = 6, c = 8

Output : Not Possible

Explanation : integral values of x and y not
exists that can satisfy the equation 3x + 6y = 8

**Solution**

For linear Diophantine equation equations, integral solutions exist if and only if, the GCD of coefficients of the two variables divides the constant term perfectly. 
In other words the integral solution exists if, GCD(a ,b) divides c.

- Find GCD of a and b
- Check if c % GCD(a ,b) == 0
- If yes then print Possible
 - Else print Not Possible
```cpp
int gcd(int a, int b) 
{ 
    if(b==0)
       return a;
    return gcd(b,a%b); 
} 
bool isPossible(int a, int b, int c) 
{ 
    return (c % gcd(a,b) == 0); 
} 
```
**How does this work?**

Let GCD of ‘a’ and ‘b’ be ‘g’. g divides a and b. This implies g also divides (ax + by) (if x and y are integers).
This implies gcd also divides ‘c’ using the relation that ax + by = c. 
