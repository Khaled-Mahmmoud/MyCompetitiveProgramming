```cpp
/*
Multiplicative inverse (reciprocal)
- Of number a: 1/a or a^−1 => then a * (1/a) = 1
- Then for any a * b = 1, then b = 1 / a = a^-1
Given two integers ‘a’ and ‘m’, find modular multiplicative inverse of ‘a’ under modulo ‘m’.
The modular multiplicative inverse is an integer ‘x’ such that.
 `a * x ≡ 1 (mod m)`
The value of x should be in {0, 1, 2, … m-1}, i.e., in the range of integer modulo m.
The multiplicative inverse of “a modulo m” exists if and only if a and m are relatively prime (i.e., if gcd(a, m) = 1).
Input:  a = 3, m = 11, Output: 4
Since (4 * 3) mod 11 = 1, 4 is modulo inverse of 3
One might think, 15 also as a valid output as "(15 * 3) mod 11" is also 1
but 15 is not in range {0, 1, 2, ... 10}, so not valid

Solution by Extended Euclidean (Works when m and a are coprime)
The idea is to use Extended Euclidean algorithms that takes two integers ‘a’ and ‘b’,
find their gcd and also find ‘x’ and ‘y’ such that 
ax + by = gcd(a, b)
To find multiplicative inverse of ‘a’ under ‘m’, we put b = m in above formula
Since we know that a and m are relatively prime, we can put value of gcd as 1.
ax + my = 1 
If we take modulo m on both sides, we get
ax ≡ 1 (mod m)
We can remove the second term on left side as ‘my (mod m)’ would always be 0 for an integer y.
ax  ≡ 1 (mod m) 
So the ‘x’ that we can find using Extended Euclidean Algorithm is multiplicative inverse of ‘a’
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
     // Notice that we modify x. The resulting x from the extended Euclidean algorithm may be negative
     // so x % m might also be negative and we first have to add m to make it positive
        cout << "Modular multiplicative inverse is " << res; 
    } 
} 
// O(log min(a,m))
/*
Solution by Euler's theorem
- if gcd(a, m) = 1 => a^φ(m) ≡ 1 (mod m)
- As a result (divide both sides by a)
- a^(φ(m)-1) ≡ a^-1 (mod m)
- if m is prime a^-1 ≡ a^(m-2) (mod m)
*/
int power(int a,int b,int mod)
{
    int ans = 1;
    a %= mod;
    while(b)
    {
        if(b%1)
            ans = (ans*a)%mod;
        b>>=1;
        a = (a * a)%mod;
    }
    return ans;
}
int mod_inverse(int a,int m)
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

<Congruence Equations>
a ≡ b (mod n)
called a and b congruent modulo n
- It means a%n = b%n = x,
- this means (a-b)%n = 0 and (b-a)%n = 0
- a = b+qn for some q integer (a-b = qn)
Note that a ≡ 0 (mod m) if and only if m | a. 
Thus, modular arithmetic gives you another way of dealing with divisibility relations.
Another way of saying this is:  any multiple of m Mod m is 0.
- If ax ≡ ay (mod n) and gcd(a,n) = d, then the congruence is equivalent x ≡ y (mod n/d)
- If ax ≡ ay (mod n) SAME as x ≡ y (mod n) THEN d = 1, Reverse doesn’t need this condition.
- IF a ≡ b (mod m) then a^n ≡ b^n (mod m) for all  n >= 1
- If p is prime , (x+y)^p ≡ x^p + y^p (mod p)
- If a ≡ b (mod m) and b ≡ c (mod m), then a ≡ c (mod m)
proof : there are two integers j and k such that
a - b = jm , b - c = km 
add two equations a - c = jm + km 
this implies that a ≡ c (mod m)
- If a ≡ b (mod m) and c ≡ d (mod m), then a + c ≡ b + d (mod m) OR a - c ≡ b - d (mod m)
proof : m | a - b and m | c - d
then m | (a-b) + (c-d) = m | (a+c) - (b+d)
tis implies a+c ≡ b+d (mod m)
- If a ≡ b (mod m) and c ≡ d (mod m), then ac ≡ bd (mod m) 
proof : there are two integers j and k such that
a ≡ b+jm   and   c ≡ d+km
Multiplying these two equations, I obtain
ac ≡ (b+jm) * (d+km)
ac ≡ bd + bkm + jmd + jmkm
ac - bd ≡ m (bk + jd + jkm)
m | ac - bd 
this implies ac ≡ bd (mod m)
- IF a ≡ b (mod m)  a + c ≡ b + c (mod m) 
- IF a ≡ b (mod m)  ac ≡ bc (mod m) 
- From last one, ax ≡ b (mod n) same as x ≡ ba^-1 (mod n) 

Find answer of 3^5555 % 80
Hint: Think how to reduce the large power?!
Hint: 3^4 ≡ 1 (% 80) and 5555 = 4 * 1388 + 3
Then, 3^5555 % 80 = 3^3 % 80 = 27

Find answer of (3^1000 + 3) % 28
Hint: 3^3 = 27 = -1 (% 28) and 1000 = 3*333+1
Then equation = [(-1 * 3) + 3] (% 28) = 0
for this 27 ≡ -1 (% 28) then n ≡ n - m (% m)
a % (a-b) = b % (a-b)
*/
```
