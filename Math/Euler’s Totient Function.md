```cpp
/*
totative of a positive integer n is an integer k (0 < k <= n) , such that n and k are coprimes.
n = 8 , then k = 3 can be a totative.
Euler’s Totient function ?(n) for an input n is count of numbers in {1, 2, 3, …, n} that are relatively prime to n.
i.e., the numbers whose GCD (Greatest Common Divisor) with n is 1
 φ(n) = 1, 1, 2, 2, 4, 2, 6, 4, 6, 4, 10, 4, 12, 6, 8,
8, 16, 6, 18, 8, 12, 10, 22, 8, 20, 12, 18, 12, 28,
8, 30, 16, 20, 16, 24, 12
- φ(n^k) = n^(k-1) * φ(n)

 Some Interesting Properties of Euler’s Totient Function
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
Euler’s theorem turns into the so-called **Fermat’s little theorem** : a^(p-1) ≡ 1 (mod p)

A Simple Solution is to iterate through all numbers from 1 to n-1 and count numbers with gcd with n as 1.
A Better Solution is as we know that If a, b, c are pairwise coprimes, then φ(a * b * c) = φ(a) * φ(b) * φ(c)
We know that all prime factors of a number is pairwise coprimes.
then φ(n) = φ(p1^h1 * p2^h2 * p3^h3) =  φ(p1^h1) * φ(p2^h2) * φ(p3^h3) where p1, p2 and p3 are prime factors of n.
We know that If p is a prime number, then ?(p^k) = p^(k-1) * (p-1).
 */
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
// O(sqrt(n))

// Phi Factorial Code
// φ(n!) = (n is prime ? n-1 : n) * φ((n-1)!)
ll phi_fact(int n)
{
    ll ret = 1;
    for(int i=2;i<=n;i++)
       ret = ret * (isprime(i)?i-1:i);
    return ret;
}
```
