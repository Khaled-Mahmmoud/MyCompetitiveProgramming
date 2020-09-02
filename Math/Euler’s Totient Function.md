# Euler’s Totient Function

totative of a positive integer n is an integer k (0 < k <= n) , such that n and k are coprimes.
 
n = 8 , then k = 3 can be a totative.

Euler’s Totient function ?(n) for an input n is count of numbers in {1, 2, 3, …, n} that are relatively prime to n.
 
i.e., the numbers whose GCD (Greatest Common Divisor) with n is 1
 
?(1) = 1  
 
gcd(1, 1) is 1
 
?(2) = 1
 
gcd(2, 1) is 1, but gcd(2, 2) is 2.
 
?(3) = 2
 
gcd(3, 1) is 1 and gcd(3, 2) is 1
 
?(4) = 2
 
gcd(4, 1) is 1 and gcd(4, 3) is 1
 
?(5) = 4
 
gcd(5, 1) is 1, gcd(5, 2) is 1, gcd(5, 3) is 1 and gcd(5, 4) is 1
 
?(6) = 2
 
gcd(6, 1) is 1 and gcd(6, 5) is 1
 
 φ(n) = 1, 1, 2, 2, 4, 2, 6, 4, 6, 4, 10, 4, 12, 6, 8,
8, 16, 6, 18, 8, 12, 10, 22, 8, 20, 12, 18, 12, 28,
8, 30, 16, 20, 16, 24, 12, 36, 18, 24, 16, 40, 12

- φ(n) is even for n > 2

- sqrt(n) <= φ(n) <= n - sqrt(n): Except 2, 6

- φ(n^k) = n^k-1 * φ(n)
 
 **Some Interesting Properties of Euler’s Totient Function**

1) For prime number p , ?(p) is p-1
For example ?(5) is 4, ?(7) is 6 and ?(13) is 12
This is obvious, gcd of all numbers from 1 to p-1 will be 1 because p is a prime.
2) For two numbers a and b, if gcd(a, b) is 1, then ?(ab) = ?(a) * ?(b)
For example ?(5) is 4 and ?(6) is 2, so ?(30) must be 8 as 5 and 6 are relatively prime.
3) If a, b, c are pairwise coprimes, then φ(a * b * c) = φ(a) * φ(b) * φ(c)
4) For any two prime numbers p and q, ?(pq) = (p-1) * (q-1). This property is used in RSA algorithm.
5) If p is a prime number, then ?(p^k) = p^k – p^(k-1) = p^k-1 * (p-1).
6) Sum of values of totient functions of all divisors of n is equal to n.
For example, n = 6, the divisors of n are 1, 2, 3 and 6. According to Gauss, sum of ?(1) + ?(2) + ?(3) + ?(6) should be 6
We can verify the same by putting values, we get (1 + 1 + 2 + 2) = 6
7) The most famous and important feature is expressed in **Euler’s theorem** :
The theorem states that if n and a are coprime, then

`a^φ(n) ≡ 1 (mod n)`.
The RSA cryptosystem is based on this theorem.

In the particular case when m is prime say p
Euler’s theorem turns into the so-called Fermat’s little theorem :
`a^(p-1) ≡ 1 (mod p)`

A **simple Solution** is to iterate through all numbers from 1 to n-1 and count numbers with gcd with n as 1.
 
 A **Better Solution** is as we know that If a, b, c are pairwise coprimes, then φ(a * b * c) = φ(a) * φ(b) * φ(c)
 
We know that all prime factors of a number is pairwise comprimes.

then φ(n) = φ(p1^h1) * φ(p2^h2) * φ(p3^h3) where p1, p2 and p3 are prime factors of n.

We know that If p is a prime number, then ?(p^k) = p^k-1 * (p-1).
 ```cpp
 int phi(int n)
{
    int p,ans = 1;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            p = 1;
            while(n%i==0)
            {
                p *= i;
                n /= i;
            }
            ans *= (p/i) * (i-1);
        }
    }
    if(n!=1)
        ans *= (n-1);
    return ans;
}
 ```
 Complexity : O(sqrt(n))

**Another Solution**. The idea is based on Euler’s product formula which states that value of totient functions 
is below product over all prime factors p of n
```
 ϕ(n) = n II (1-1/p)
          p|n
```       
The formula basically says that the value of ?(n) is equal to n multiplied by product of (1 – 1/p) for all prime factors p of n

For example value of ?(6) = 6 * (1-1/2) * (1 – 1/3) = 2
```cpp
int phi(int n) 
{ 
    double result = n;
    for (int p = 2; p * p <= n; ++p) 
    { 
        if (n % p == 0) 
        { 
            while (n % p == 0) 
                n /= p; 
            result *= (1 - (1 / (double)p)); 
        } 
    } 
    if (n > 1) 
        result *= (1 - (1 / (double)n)); 
  
    return (int)result; 
} 
```
We can avoid floating point calculations in above method
The idea is to count all prime factors and their multiples
and subtract this count from n to get the totient function value
(Prime factors and multiples of prime factors won’t have gcd as 1)
```cpp
int phi(int n) 
{ 
    int result = n; 
    for (int p = 2; p * p <= n; ++p) 
    { 
          
        if (n % p == 0)
        { 
            while (n % p == 0) 
                n /= p; 
            result = result - result / p; 
        } 
    } 
    if (n > 1) 
        result = result - result / n; 
    return result; 
}
```
Complexity : O(sqrt(n)) 

**Phi Factorial Code**

φ(n!) = (n is prime ? n-1 : n) * φ((n-1)!)

```cpp
ll phi_fact(int n)
{
    ll ret = 1;
    for(int i=2;i<=n;i++)
       ret = ret * (isprime(i)?i-1:i);
    return ret;
}
```
