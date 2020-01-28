/*
totative of a positive integer n is an integer k (0 < k <= n) , such that n and k are coprimes
n = 8 , then k = 3 can be a totative
n = 12 , then k = 5 can be a totative
Euler’s Totient function ?(n) for an input n is count of numbers in {1, 2, 3, …, n} that are relatively prime to n
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
gcd(5, 1) is 1, gcd(5, 2) is 1, 
gcd(5, 3) is 1 and gcd(5, 4) is 1
?(6) = 2
gcd(6, 1) is 1 and gcd(6, 5) is 1
A simple solution is to iterate through all numbers from 1 to n-1 and count numbers with gcd with n as 1
Complexity : O(nlog(n))
Below is a Better Solution. The idea is based on Euler’s product formula which states that value of totient functions 
is below product over all prime factors p of n

 ϕ(n) = n II (1-1/p)
          p|n
          
The formula basically says that the value of ?(n) is equal to n multiplied by product of (1 – 1/p) for all prime factors p of n
For example value of ?(6) = 6 * (1-1/2) * (1 – 1/3) = 2
*/

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
/*
We can avoid floating point calculations in above method
The idea is to count all prime factors and their multiples
and subtract this count from n to get the totient function value
(Prime factors and multiples of prime factors won’t have gcd as 1)
*/
int phi(int n) 
{ 
    int result = n; 
    for (int p = 2; p * p <= n; ++p) 
    { 
          
        if (n % p == 0)
        { 
            while (n % p == 0) 
                n /= p; 
            result -= result / p; 
        } 
    } 
    if (n > 1) 
        result -= result / n; 
    return result; 
} 
/*
Some Interesting Properties of Euler’s Totient Function
1) For prime number p , ?(p) is p-1
For example ?(5) is 4, ?(7) is 6 and ?(13) is 12
This is obvious, gcd of all numbers from 1 to p-1 will be 1 because p is a prime.
2) For two numbers a and b, if gcd(a, b) is 1, then ?(ab) = ?(a) * ?(b)
For example ?(5) is 4 and ?(6) is 2, so ?(30) must be 8 as 5 and 6 are relatively prime.
3) For any two prime numbers p and q, ?(pq) = (p-1)*(q-1). This property is used in RSA algorithm.
4) If p is a prime number, then ?(p^k) = p^k – p^k-1.
5) Sum of values of totient functions of all divisors of n is equal to n.
For example, n = 6, the divisors of n are 1, 2, 3 and 6. According to Gauss, sum of ?(1) + ?(2) + ?(3) + ?(6) should be 6
We can verify the same by putting values, we get (1 + 1 + 2 + 2) = 6
6) The most famous and important feature is expressed in Euler’s theorem :
The theorem states that if n and a are coprime positive integers, then
a^?(n) ? 1 (mod n) 
The RSA cryptosystem is based on this theorem:
In the particular case when m is prime say p
Euler’s theorem turns into the so-called Fermat’s little theorem :
a^(p-1) ? 1 (mod p) 
*/
