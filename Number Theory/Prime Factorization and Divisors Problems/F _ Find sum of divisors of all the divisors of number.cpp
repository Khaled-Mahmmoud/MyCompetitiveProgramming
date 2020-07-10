/*
Given a natural number n, the task is to find sum of divisors of all the divisors of n.

Input : n = 54
Output : 232
Divisors of 54 = 1, 2, 3, 6, 9, 18, 27, 54.
Sum of divisors of 1, 2, 3, 6, 9, 18, 27, 54 
are 1, 3, 4, 12, 13, 39, 40, 120 respectively.
Sum of divisors of all the divisors of 54 = 
1 + 3 + 4 + 12 + 13 + 39 + 40 + 120 = 232.

Input : n = 10
Output : 28
Divisors of 10 are 1, 2, 5, 10
Sums of divisors of divisors are 
1, 3, 6, 18.
Overall sum = 1 + 3 + 6 + 18 = 28

Using the fact that any number n can be expressed as product of prime factors, n = p1^k1 x p2^k2 x …
where p1, p2, … are prime numbers.
All the divisors of n can be expressed as p1^a x p2^b x …, where 0 <= a <= k1 and 0 <= b <= k2.
Now sum of divisors will be sum of all power of p1 ( p1^0, p1^1,…., p1^k1 ) multiplied by all power of p2 (p2^0, p2^1,…., p2^k1)

Sum of Divisor of n
= (p1^0 x p2^0) + (p1^1 x p2^0) +…..+ (p1^k1 x p2^0) +….+ (p1^0 x p2^1) + (p1^1 x p2^1) +…..+ (p1^k1 x p2^1) +……..+
   (p1^0 x p2^k2) + (p1^1 x p2^k2) +……+ (p1^k1 x p2^k2).
= (p1^0 + p1^1 +…+ p1^k1) x p2^0 + (p1^0 + p1^1 +…+ p1^k1) x p2^1 +…….+ (p1^0 + p1^1 +…+ p1^k1) x p2^k2.
= (p1^0 + p1^1 +…+ p1^k1) x (p2^0 + p2^1 +…+ p2^k2).

Divisors of 30 is 1 2 3 5 6 10 15 30
30 = 2^1 * 3^1 * 5^1

2^0 * 3^0 * 5^0 = 1
2^1 * 3^0 * 5^0 = 2
2^0 * 3^1 * 5^0 = 3
2^0 * 3^0 * 5^1 = 5
2^1 * 3^1 * 5^0 = 6
2^1 * 3^0 * 5^1 = 10
2^0 * 3^1 * 5^1 = 15
2^1 * 3^1 * 5^1 = 30

Now, the divisors of any p^a, for p as prime, are p^0, p^1,……, p^a
And sum of diviors will be (p^(a+1) – 1)/(p -1), let it define by f(p).
So, sum of divisors of all divisor will be,
= [f(p1^0) + f(p1^1) +…+ f(p1^k1)] x [f(p2^0) + f(p2^1) +…+ f(p2^k2)]
So, given a number n, by prime factorization we can find the sum of divisors of all the divisors.

*/

int sumFactorsofFactors(int n) 
{ 
    long long res = 1; 
    for (int i = 2; i <= sqrt(n); i++) 
    { 
        int curr_sum = 1,pre=1; 
        int curr_term = 1; 
        while (n % i == 0)
        {  
            n = n / i; 
            curr_term *= i;
            curr_sum += curr_term + pre; 
            pre = curr_term + pre;
        } 
        res *= curr_sum; 
    } 
    if (n >= 2) 
       res *= (1 + (1+n));
  
    return res; 
} 
