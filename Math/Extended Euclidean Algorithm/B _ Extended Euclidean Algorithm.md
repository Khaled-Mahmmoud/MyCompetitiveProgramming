
### Extended Euclidean Algorithm   

Extended Euclidean algorithm finds integer coefficients x and y such that: ax + by = gcd(a , b) 
  
The extended Euclidean algorithm updates results of gcd(a, b) using the results calculated by recursive call gcd(b%a, a).

Let values of x and y calculated by the recursive call be x1 and y1. x and y are updated using the below expressions

x = y1 

y = x1 - y1 * (a / b);

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
```
# How does Extended Algorithm Work?

As seen above, x and y are results for inputs a and b: a.x + b.y = gcd ---- (1)  

And x1 and y1 are results for inputs b%a and a: b.x1 + a%b.y1 = gcd   
                    
When we put a%b = (a - (⌊a/b⌋).b) in above, we get the following : b.x1 + (a - (⌊a/b⌋).b).y1  = gcd
   
Above equation can also be written as below a.y1 + b(x1-(⌊a/b⌋).y1) = gcd      --- (2)
 
After comparing coefficients of 'a' and 'b' in (1) and (2), we get following

x = y1

y = x1 - y1 * (a / b)
    
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
