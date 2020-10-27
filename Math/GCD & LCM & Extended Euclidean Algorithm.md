# GCD & LCM

GCD (Greatest Common Divisor) or HCF (Highest Common Factor)

GCD of two numbers is the largest number that divides both of them . A simple way to find GCD is to factorize both numbers 
and multiply common factors.

36 = 2 * 2 * 3 * 3

60 = 2 * 2 * 3 * 5

gcd = Multiplication of common factors
    = 2 * 2 * 3
    = 12
    
we express the 2 numbers in form of : m = qn + r 

find gcd of 190 , 34
```
190 = 5 (34) + 20
34 = 1 (20) + 14
20 = 1 (14) + 6
14 = 2 (6) + 2
6 = 3 (2) + 0
```
2 is GCD of 190 , 34
we have another way to find gcd of 2 numbers called successive difference
```
a          b          a-b         b-a
144       166                     22
144       22          122
122       22          100
100       22          78
78        22          56
56        22          34
34        22          12
12        22                      10
12        10          2
2         10                      8
2         8                       6
2         6                       4
2         4                       2
2         2
```
gcd is 2 because a == b

Below is a recursive function to evaluate gcd using Euclidean’s algorithm

O(log min(a,b))
```cpp
#define N 50000000
int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int main()
{
    int a,b;cin>>a>>b;
    cout<<gcd(a,b);
    return 0;
}
```

two integers a and b are said to be relatively prime, mutually prime, or coprime 
if gcd(a,b) = 1

Assume gcd(a,b) = g then `(a+b)%g = 0` and `(a-b)%g = 0` as (a+b)%g = (a%g+b%g)%g = (0+0)%g = 0

this fact could be used as :

gcd(45, 10) = gcd(35, 10) = gcd(25, 10) = gcd(15, 10) = gcd(5, 10) = 5

gcd(10, 5) = gcd(5, 5) = gcd(5, 0) = 5

Wait: We just keep reaming the small from the big, the big number turn to be the smaller, and then do reverse

How to do this switch fast? gcd(45, 10) = gcd(45%10, 10)	-> simply remove the smaller cycles in 1 step

### LCM (Least Common Multiple) 

LCM(a,b) = a * b / GCD(a,b)

```cpp
#define N 50000000
int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int lcm(int a,int b)
{
    return a*b/gcd(a,b);
}
int main()
{
    int a,b;cin>>a>>b;
    cout<<lcm(a,b);
    return 0;
}
```
GCD(f(x,y),f(x,z)) = f(x,GCD(y,z))   where f is fuction

GCD(f(y),f(z)) = f(GCD(y,z))

Examples
            
GCD(LCM(x,y),LCM(x,z)) = LCM(x,GCD(y,z))   

GCD(Fibonacci(x), Fibonacci(z)) = Fibonacci(GCD(x, z))


inbuilt function for finding GCD in c++
```cpp
int main() 
{ 
    cout << "gcd(6, 20) = " << __gcd(6, 20) << endl; 
}
```
inbuilt function for finding LCM in c++
```cpp
#include <boost/math/common_factor.hpp> 
int main() 
{ 
    cout << "LCM(10,20) = " << boost::math::lcm(10,20) << endl; 
    return 0; 
} 
```
```
        GCD & LCM
find GCD and LCM between (504,540)
504 | 2           540 | 2
252 | 2           270 | 2
126 | 2           135 | 3
63  | 3           45  | 3
21  | 3           15  | 3
7   | 7           5   | 5
    | 1               | 1
    
   504 = 2^3 * 3^2 * 5^0 * 7^1
   540 = 2^2 * 3^3 * 5^1 * 7^0
        
GCD(504,540) = 2^2 * 3^2 * 5^0 * 7^0    --> Least power
LCM(504,540) = 2^3 * 3^3 * 5^1 * 7^1    --> highest power
```
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

### Extended Euclidean Algorithm   

Extended Euclidean algorithm also finds integer coefficients x and y such that:

ax + by = gcd(a , b) 
    
Input: a = 30, b = 20

Output: gcd = 10 , x = 1, y = -1

(Note that 30*1 + 20*(-1) = 10)

Input: a = 35, b = 15

Output: gcd = 5 , x = 1, y = -2

(Note that 35*1 + 15*(-2) = 5)
  
The extended Euclidean algorithm updates results of gcd(a, b) using the results calculated 

by recursive call gcd(b%a, a). Let values of x and y calculated by the recursive call be x1 and y1

x and y are updated using the below expressions

x = y1 - ⌊b/a⌋ * x1

y = x1

The above idea still works when a or b or both of them are negative. We only need to change the sign of x and y when necessary.
```cpp
int gcdExtended(int a, int b, int *x, int *y)  
{  
    if (a == 0)  
    {  
        *x = 0;  
        *y = 1;  
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
    int x, y, a = 35, b = 15;  
    int g = gcdExtended(abs(a), abs(b), &x, &y); 
    if (a < 0) x *= -1;
    if (b < 0) y *= -1;
    cout<<g<<' '<<x<<' '<<y;  // 5  1  -2
    return 0;  
}  
```
# How does Extended Algorithm Work?

As seen above, x and y are results for inputs a and b,

a.x + b.y = gcd                      ---- (1)  

And x1 and y1 are results for inputs b%a and a

(b%a).x1 + a.y1 = gcd   
                    
When we put b%a = (b - (⌊b/a⌋).a) in above, we get following.
   
(b - (⌊b/a⌋).a).x1 + a.y1  = gcd
   
Above equation can also be written as below

b.x1 + a.(y1 - (⌊b/a⌋).x1) = gcd      --- (2)
 
After comparing coefficients of 'a' and 'b' in (1) and (2), we get following

x = y1 - ⌊b/a⌋ * x1

y = x1
 
### How is Extended Algorithm Useful?

The extended Euclidean algorithm is particularly useful when a and b are coprime (or gcd is 1)

Since x is the modular multiplicative inverse of “a modulo b”, and y is the modular multiplicative inverse of “b modulo a”

In particular, the computation of the modular multiplicative inverse is an essential step in RSA public-key encryption method.

### Bézout's identity

Assume a > 0 and b > 0

ax + by = gcd(a, b)	=> we know that

Can we generate further solutions?

Is following valid:

- a(x+b) + b(y-a) = g, Yes, we added ab - ab, so same equation

- a(x+b/g) + b(y-a/g) = g

- a(x+kb/g) + b(y-ka/g) = g

With easy math, we can generate!
