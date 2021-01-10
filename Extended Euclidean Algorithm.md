```cpp
/*
GCD (Greatest Common Divisor) or HCF (Highest Common Factor)
we express the 2 numbers in form of : m = qn + r 
*/
int gcd(int a,int b)
{
    if(!b)
        return a;
    return gcd(b,a%b);
}
/*
two integers a and b are said to be relatively prime, mutually prime, or coprime if gcd(a,b) = 1
Assume gcd(a,b) = g then `(a+b)%g = 0` and `(a-b)%g = 0` as (a+b)%g = (a%g+b%g)%g = (0+0)%g = 0
this fact could be used as : gcd(45, 10) = gcd(35, 10) = gcd(25, 10) = gcd(15, 10) = gcd(5, 10) = 5
gcd(10, 5) = gcd(5, 5) = gcd(5, 0) = 5
Wait: We just keep reaming the small from the big, the big number turn to be the smaller, and then do reverse
How to do this switch fast? gcd(45, 10) = gcd(45%10, 10)	-> simply remove the smaller cycles in 1 step
LCM (Least Common Multiple) 
LCM(a,b) = a * b / GCD(a,b)
*/
int gcd(int a,int b)
{
    if(!b)
        return a;
    return gcd(b,a%b);
}
int lcm(int a,int b)
{
    return a*b/gcd(a,b);
}
/*
GCD is distributive over the LCM, and vice versa: gcd(a, lcm(b, c)) = lcm(gcd(a, b), gcd(a, c)) 
and lcm(a, gcd(b, c)) = gcd(lcm(a, b), lcm(a, c))

        GCD & LCM
Find GCD and LCM between (504,540)
   504 = 2^3 * 3^2 * 5^0 * 7^1
   540 = 2^2 * 3^3 * 5^1 * 7^0       
GCD(504,540) = 2^2 * 3^2 * 5^0 * 7^0    --> Least power
LCM(504,540) = 2^3 * 3^3 * 5^1 * 7^1    --> highest power
Note : to get GCD of two numbers , we take the least power 
to get LCM of two numbers , we take the highest power
let's do some prime representation for numbers a, b
a = 2^3 * 7^6
b = 2^5 * 7^2
gcd = 2^min(3, 5) * 7^min(6, 2)
what about lcm ? we need max
lcm = 2^max(3, 5) * 7^max(6, 2)
given a * b, and gcd(a, b) how to get lcm(a, b)
what know a * b = 2^8 7^8, and we know gcd = 2^3 7^2
so by division we substrct powers and get lcm = 2^5 7^6
*/

/*
Extended Euclidean algorithm finds integer coefficients x and y such that: ax + by = gcd(a , b) 
The extended Euclidean algorithm updates results of gcd(a, b) using the results calculated by recursive call gcd(b%a, a).
Let values of x and y calculated by the recursive call be x1 and y1. x and y are updated using the below expressions
x = y1, y = x1 - y1 * (a / b);
The above idea still works when a or b or both of them are negative. We only need to change the sign of x and y when necessary.
*/
ll x,y;
ll exgcd(ll a,ll b,ll &x,ll &y)
{
    if (!b)
    {
        x=1;
        y=0;
        return a;
    }
    ll x1, y1;
    ll d = exgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
int main()  
{  
    ll g = exgcd(abs(a), abs(b), x, y); 
    if (a < 0) x *= -1;
    if (b < 0) y *= -1;
    cout<<g<<' '<<x<<' '<<y;  
}  
/*
How does Extended Algorithm Work?
As seen above, x and y are results for inputs a and b: a.x + b.y = gcd ---- (1)  
And x1 and y1 are results for inputs b and a%b: b.x1 + a%b.y1 = gcd   
When we put a%b = (a - (⌊a/b⌋).b) in above, we get the following : b.x1 + (a - (⌊a/b⌋).b).y1  = gcd
Above equation can also be written as below a.y1 + b(x1-(⌊a/b⌋).y1) = gcd      --- (2)
After comparing coefficients of 'a' and 'b' in (1) and (2), we get following
x = y1, y = x1 - y1 * (a / b)
Bézout's identity
Assume a > 0 and b > 0, Can we generate further solutions?
a(x+b) + b(y-a) = g, Yes, we added ab - ab, so same equation
a(x+kb/m) + b(y-ka/m) = g
*/
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
