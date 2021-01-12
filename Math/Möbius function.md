/*
Square-free integer
Is any integer not divisible by perfect square (except 1)
- perfect square: sqrt(n) = is integer. sqrt(16) = 4
- In other words, no prime factor occurs more
than once: e.g. n = 2 * 5 * 11 is square free,
but n = 2 * 3 * 3 * 3 * 7 is not (divisible by 9 = 3x3)
- I-th square free: 1, 2, 3, 5, 6, 7, 10, 11, 13, 14, 15, 17, 19, 21, 22, 23

- μ(1) = 1
- μ(n) = 1 if n is a square-free positive integer with an even number of prime factors.
- E.g. μ(2 * 3 * 5 * 7) = 1
- μ(n) = −1 if n is a square-free positive integer with an odd number of prime factors.
- E.g. μ(2 * 3 * 5) = -1
- μ(n) = 0 if n has a squared prime factor.
- E.g. μ(2 * 3 * 3 * 7) = 0
μ(n) = 1, -1, -1, 0, -1, 1, -1, 0, 0, 1, -1, 0, -1, 1
μ(n) + 1 = 2, 0, 0, 1, 0, 2, 0, 1, 1, 2, 0, 1, 0, 2
*/
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
/*
Möbius and Inclusion Exclusion
Recall, in Inclusion Exclusion we compute all subsets, and add odd subsets and substract even subsets.
- Assume generating all subsets of primes but in implicit way, Möbius can tell you if number is odd subset or even.
- Typically, ignoring numbers with repeated prime factors is target. Then Möbius(n) plays perfect role.
- **Given n square free number, find its index?**
- E.g. F_reverse(n = 19) = 13
- Reverse thinking: Can we remove non SFree?
- In range n, remove who divides by 2x2, 3x3, 4x4, 5x5, 6x6...etc.
- 4x4 and 6x6 already computed by previous ones.
- Ignore duplicate primes (4x4)...use Inclusion Exclusion for others F(2)+F(3)+F(5)-F(6)
*/
ll val = 19 , idx = val;
for(ll i=2;i*i<=val;i++)
    idx += mobius[i] * (val/(i*i));
/*
Count the triples (a,b,c) such a, b, c <= n and gcd(a, b, c) = 1
- Reverse thinking, total - (number of triples gcd > 1)
- How many triples with gcd multiple of 2: (n/2)^3
- How many triples with gcd multiple of 3: (n/3)^3
- and 4? Ignore any numbers of internal duplicate primes.
- and 6? already computed in 2, 3. Remove it: -(n/6)^3
- This is Inclusion Exclusion.
*/
ll sum = n*n*n;
for(ll i=2;i<=n;i++)
    sum -= mobius[i] * (n/i) * (n/i) * (n/i);
