```cpp
/*
Linear Diophantine Equations
A Linear Diophantine Equation (in two variables) is an equation of the general form: `ax + by = c`
where a, b, c are given integers, and x, y are unknown integers.
**A Diophantine equation** is a polynomial equation, usually in two or more unknowns variables,
such that only the integral solutions are required.
**An Integral solution** is a solution such that all the unknown variables take only integer values.
Given three integers a, b, c representing a linear equation of the form : ax + by = c. 
Determine if the equation has a solution such that x and y are both integral values.
**Solution** For linear Diophantine equation equations, integral solutions exist if and only if,
the GCD of coefficients of the two variables divides the constant term perfectly. 
In other words the integral solution exists if, GCD(a ,b) divides c.
*/ 
bool isPossible(int a, int b, int c) 
{ 
    return (c % gcd(a,b) == 0); 
} 
/*
How does this work?
Let GCD of ‘a’ and ‘b’ be ‘g’. g divides a and b. This implies g also divides (ax + by) (if x and y are integers).
This implies gcd also divides ‘c’ using the relation that ax + by = c. 
Finding a solution of equation ax + by = c
To find one solution of the Diophantine equation with 2 unknowns, you can use the Extended Euclidean algorithm. 
First, assume that a and b are non-negative. When we apply Extended Euclidean algorithm for a and b,
we can find their greatest common divisor g and 2 numbers xg and yg such that: a.xg + b.yg = g
Now supposed that c is divisible by g, then we multiply the equation by c/g:
a.xg.c/g + b.yg.c/g = c
Therefore one of the solutions of the Diophantine equation is:
x = xg.c/g
y = yg.c/g
The above idea still works when a or b or both of them are negative. We only need to change the sign of x and y when necessary.
*/
ll phan(ll a, ll b, ll c)
{
    ll g = exgcd(abs(a), abs(b), x, y);
    
    if (c % g)
        return -1;
    
    x = x * c / g;
    y = y * c / g;
    
    if (a < 0) x *= -1;
    if (b < 0) y *= -1;
    
    return x;
}
/*
Getting all solutions of equation ax + by = c using Bézout's identity
From one solution (x,y), we can obtain all the solutions of the given equation.
Let g=gcd(a,b) and let x,y be integers which satisfy the following: a⋅x + b⋅y = c
Now, we should see that adding b/m to x, and at the same time subtracting a/m from y will not break the equality:
a * (x+b/m) + b * (y-a/m) = c
Obviously, this process can be repeated again, so all the numbers of the form:
x = x + k * (b/m)
y = y - k * (a/m)
are solutions of the given Diophantine equation.
Moreover, this is the set of all possible solutions of the given Diophantine equation.
*/
```
