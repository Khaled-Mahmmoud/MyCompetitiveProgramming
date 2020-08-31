# Möbius function

### Square-free integer

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
