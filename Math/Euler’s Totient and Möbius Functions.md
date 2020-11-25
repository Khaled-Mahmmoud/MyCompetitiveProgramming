### Euler’s Totient Function

totative of a positive integer n is an integer k (0 < k <= n) , such that n and k are coprimes.
 
n = 8 , then k = 3 can be a totative.

Euler’s Totient function ?(n) for an input n is count of numbers in {1, 2, 3, …, n} that are relatively prime to n.
 
i.e., the numbers whose GCD (Greatest Common Divisor) with n is 1
 
 
 φ(n) = 1, 1, 2, 2, 4, 2, 6, 4, 6, 4, 10, 4, 12, 6, 8,
8, 16, 6, 18, 8, 12, 10, 22, 8, 20, 12, 18, 12, 28,
8, 30, 16, 20, 16, 24, 12, 36, 18, 24, 16, 40, 12

- φ(n) is even for n > 2

- sqrt(n) <= φ(n) <= n - sqrt(n): Except 2, 6

- φ(n^k) = n^(k-1) * φ(n)
 
 **Some Interesting Properties of Euler’s Totient Function**

1) For prime number p , ?(p) is p-1
For example ?(5) is 4, ?(7) is 6 and ?(13) is 12
This is obvious, gcd of all numbers from 1 to p-1 will be 1 because p is a prime.

2) For two numbers a and b, if gcd(a, b) is 1, then ?(ab) = ?(a) * ?(b)
For example ?(5) is 4 and ?(6) is 2, so ?(30) must be 8 as 5 and 6 are relatively prime.

3) If a, b, c are pairwise coprimes, then φ(a * b * c) = φ(a) * φ(b) * φ(c)

4) For any two prime numbers p and q, ?(pq) = (p-1) * (q-1). 

5) If p is a prime number, then ?(p^k) = p^(k-1) * (p-1).

6) Sum of values of totient functions of all divisors of n is equal to n.
For example, n = 6, the divisors of n are 1, 2, 3 and 6. According to Gauss, sum of ?(1) + ?(2) + ?(3) + ?(6) should be 6
We can verify the same by putting values, we get (1 + 1 + 2 + 2) = 6

7) The most famous feature is expressed in **Euler’s theorem** :
The theorem states that if n and a are coprime,`a^φ(n) ≡ 1 (mod n)`. In the particular case when n is prime say p
Euler’s theorem turns into the so-called **Fermat’s little theorem** :
`a^(p-1) ≡ 1 (mod p)`

A **simple Solution** is to iterate through all numbers from 1 to n-1 and count numbers with gcd with n as 1.
 
 A **Better Solution** is as we know that If a, b, c are pairwise coprimes, then φ(a * b * c) = φ(a) * φ(b) * φ(c)
 
We know that all prime factors of a number is pairwise coprimes.

then φ(n) = φ(p1^h1) * φ(p2^h2) * φ(p3^h3) where p1, p2 and p3 are prime factors of n.

We know that If p is a prime number, then ?(p^k) = p^(k-1) * (p-1).
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
------------------------------------------------------------------------------------------------------------------------------------------------------

### Möbius function

**Square-free integer**

Is any integer not divisible by perfect square (except 1)

- perfect square: sqrt(n) = is integer. sqrt(16) = 4

- SQ: e.g. not divisible by 16=4x4...or 49=7x7...etc

- In other words, no prime number occurs more
than once: e.g. n = 2 * 5 * 11 is square free, but n
= 2 * 3 * 3 * 3 * 7 is not (divisible by 9 = 3x3)

- I-th square free: 1, 2, 3, 5, 6, 7, 10, 11, 13, 14,
15, 17, 19, 21, 22, 23, 26, 29, 30, 31, 33, 34

### Möbius function

- μ(1) = 1

- μ(n) = 1 if n is a square-free positive integer
with an even number of prime factors.

- E.g. μ(2 * 3 * 5 * 7) = 1

- μ(n) = −1 if n is a square-free positive integer
with an odd number of prime factors.

- E.g. μ(2 * 3 * 5) = -1

- μ(n) = 0 if n has a squared prime factor.

- E.g. μ(2 * 3 * 3 * 7) = 0

μ(n) = 1, -1, -1, 0, -1, 1, -1, 0, 0, 1, -1, 0, -1, 1

μ(n) + 1 = 2, 0, 0, 1, 0, 2, 0, 1, 1, 2, 0, 1, 0, 2

```cpp
int mobius(int n)
{
    int mobval = 1;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            if(n%(i*i)==0)
                return 0;
            n /= i;
            mobval = -mobval;
        }
    }
    if(n>1)
        mobval = -mobval;
    return mobval;
}
```

### Möbius and [Inclusion Exclusion](https://github.com/Khaled-Mahmmoud/MyCompetitiveProgramming/blob/master/Combinatorics/Counting%20Principle.md)

Recall, in Inclusion Exclusion we compute all subsets, and add odd subsets and substract even subsets.

- Assume generating all subsets of primes but in implicit way (e.g. iterate on numbers), Möbius can tell you if number is odd subset or even.

- Typically, ignoring numbers with repeated prime factors is target. Then Möbius(n) plays perfect role.

- **Given n square free number, find its index?**

- E.g. F_reverse(n = 19) = 13

- Reverse thinking: Can we remove non SFree?

- In range n, remove who divides by 2x2, 3x3, 4x4, 5x5, 6x6...etc.

- 4x4 and 6x6 already computed by previous ones.

- Ignore duplicate primes (4x4)...use Inclusion Exclusion for others F(2)+F(3)+F(5)-F(6)

```cpp
ll val = 19 , idx = val;
for(ll i=2;i*i<=val;i++)
    idx -= mobius[i] * (val/(i*i));
```

**Count the triples (a,b,c) such a, b, c <= n and gcd(a, b, c) = 1**

- Reverse thinking, total - (number of triples gcd > 1)

- How many triples with gcd multiple of 2: (n/2)^3

- How many triples with gcd multiple of 3: (n/3)^3

- and 4? Ignore any numbers of internal duplicate primes.

- and 6? already computed in 2, 3. Remove it: -(n/6)^3

- This is Inclusion Exclusion.

```cpp
ll sum = n*n*n;
for(ll i=2;i<=n;i++)
    sum -= mobius[i] * (n/i) * (n/i) * (n/i);
```
