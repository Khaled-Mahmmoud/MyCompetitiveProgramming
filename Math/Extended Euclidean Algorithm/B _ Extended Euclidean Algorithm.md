
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
ll x,y;
ll exgcd(ll a,ll b,ll &x,ll &y)
{
    if (!b)
    {
        x=1;
        y=0;
        return a;
    }
    ll d=exgcd(b,a%b,y,x);
    y-=(a/b)*x;
    return d;
}
int main()  
{  
    ll a = 35, b = 15;  
    ll g = exgcd(abs(a), abs(b), &x, &y); 
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
