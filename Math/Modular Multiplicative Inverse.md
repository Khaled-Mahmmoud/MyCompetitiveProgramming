```cpp
/*
1/a or a^−1 => a * (1/a) = 1
a * x = 1, then x = 1 / a = a^-1
The modular multiplicative inverse is an integer ‘x’ such that.  `a * x ≡ 1 (mod m)`
The multiplicative inverse of “a modulo m” exists if a and m are relatively prime 

Solution by Extended Euclidean ax + by = gcd(a, b)
we put b = m  then ax + my = 1 
take %m then ax ≡ 1 (mod m)
*/
int gcd(int a, int b, int *x, int *y)
{
    if (a == 0)  
    {  
        *x = 0;  
        *y = 1;  
        return b;  
    }  
    int x1, y1;  
    int g = gcd(b%a, a, &x1, &y1);   
    *x = y1 - (b/a) * x1;  
    *y = x1;  
    return g; 
}
void modInverse(int a, int m) 
{ 
    int x, y; 
    int g = gcdExtended(abs(a), abs(m), &x, &y); 
    if (a < 0) x *= -1;
    if (m < 0) y *= -1;
    if (g != 1) 
        cout << "Inverse doesn't exist"; 
    else
    { 
        int res = (x%m + m) % m; 
        cout << "Modular multiplicative inverse is " << res; 
    } 
} // O(log min(a,m))
/*
Solution by Euler's theorem
if gcd(a, m) = 1 => a^φ(m) ≡ 1 (mod m)
divide both sides by a then a^(φ(m)-1) ≡ a^-1 (mod m)
if m is prime a^(m-2) ≡ a^-1 (mod m)
*/
ll power(ll a,ll b,ll mod)
{
    ll ans = 1ll;
    a %= mod;
    while(b)
    {
        if(b&1ll)
            ans = (ans*a)%mod;
        b>>=1ll;
        a = (a * a)%mod;
    }
    return ans;
}
ll mod_inverse(ll a,ll m)
{
    if(isprime(m))
        return power(a,m-2,m);
    return power(a,phi(m)-1,m);
}
/*
Compute ((1/a)^m)% p where p is prime
Same as ((1/a)% p)^m % p = (a^(p-2) % p)^m % p use inverse modular a^m(p-2) % p
- What about using **fermat's last theorm** to reduce the power of a^m(p-2) % p? using note that gcd(a,p) = 1. 
- a^((m(p-2)) % (p-1)) % p or a^((m%(p-1) * (p-2)%(p-1)) % (p-1)) % p
*/
ll modinvers(ll a,ll m,ll p)
{
    return power(a,(m%(p-1) * (p-2)%(p-1))%(p-1),p);
}
/*
- (p-2) % (p-1) = -1 [use -ve mode]
- It now turns to be: a^(-m%(p-1)) % p … recall:
- a^((-m%(p-1) + (p-1)) % (p-1)) % p 
What about a^x % n where gcd(a, n) = 1?
- 7^222 % 10 ==>> gcd(7, 10) = 1 and φ(10) = 4
- From Euler's theorem 7^4 ≡ 1 (% 10)
- 7^222 ≡ 7^(4 × 55 + 2) ≡ (7^4)^55 × 7^2 ≡ 1^55 × 7^2 ≡ 49 ≡ 9 (mod 10)
- Or shortly, 7^222 ≡ 7^(222 % 4) ≡ 7^2 = 9 (mod 10)
What about a^x % n where gcd(a, n) > 1?
- Let’s factorize a to p1 * p2 * p3...pk. e.g. 12 = 2 * 2 * 3 
- Then answer = (p1^x % n * p2^x % n .... )%n
- Our problem = new sub-problems: p^x % n. p is a prime number,then gcd(p, n) = 1.

Modular multiplicative inverse from 1 to n 
Give a positive integer n, find modular multiplicative inverse of all integer from 1 to n with respect to a prime number
The modular multiplicative inverse of a is an integer ‘x’ such that.
a.x ≡ 1 (mod prime) 
Input : n = 10, prime = 17
Output : 1 9 6 13 7 3 5 15 2 12
For 1, modular inverse is 1 as (1 * 1)%17 is 1
For 2, modular inverse is 9 as (2 * 9)%17 is 1
For 3, modular inverse is 6 as (3 * 6)%17 is 1
The problem is the following: we want to compute the modular inverse for every number in the range [1,n].
Applying the algorithms described in the previous sections, we can obtain a solution with complexity O(nlogn).
Here we present a better algorithm with complexity O(n). 
However for this specific algorithm we require that the modulus m is prime.
We denote by inv[i] the modular inverse of i. Then for i>1 the following equation is valid:
inv[i]= −⌊m/i⌋⋅inv[m mod i] mod m
*/
void modularInverse(int n, int m) 
{ 
    int inv[n+1];
    inv[1] = 1;
 
    for(int i=2 ; i<=n ; ++i)
        inv[i] = (m - (m/i) * inv[m%i] % m) % m;
 
    for (int i = 1; i <= n; i++)  
        cout << inv[i] << ' ';     
} 
/*
We have: m % i = m − ⌊m/i⌋ ⋅ i
Taking both sides modulo m yields:
m % i ≡ − ⌊m/i⌋ * i  (mod m)
Now, divide by i * (m % i)
1 / i ≡ − ⌊m/i⌋ / (m % i) (mod m)
which simplifies to:
i^−1 ≡ − ⌊m/i⌋ * (m % i)^−1 (mod m)
Add m to convert to +ve
inv[i] = m - ⌊m/i⌋ * inv[m % i] (mod m)
*/
```
