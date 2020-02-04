/*

Break a number such that sum of maximum divisors of all parts is minimum
We need to split a number n such that sum of maximum divisors of all the parts is minimum.

Examples :

Input:  n = 27
Output: Minimum sum of maximum
        divisors of parts = 3
Explanation : We can split 27 as 
follows: 27 =  13 + 11 + 3,
Maximum divisor of 13 = 1,
                   11 = 1,
                   3 = 1.
Answer = 3 (1 + 1 + 1).

Input : n = 4
Output: Minimum sum of maximum
        divisors of parts = 2
Explanation : We can write 4 = 2 + 2
Maximum divisor of 2 = 1,
So answer is 1 + 1 = 2

We need to minimize maximum divisors. It is obvious that if N is prime, maximum divisor = 1. If the number is not a prime
then the number should be atleast 2 . According to Goldbach’s Conjecture, every even integer can be expressed as sum
of two prime numbers. For our problem there will be two cases:
1) When the number is even, it can be expressed as the sum of two prime numbers and our answer will be 2
because maximum divisor of a prime number is 1.
2) When the number is odd, it can also be written as sum of prime numbers, n = 2 + (n-2); 
if (n-2) is a prime number(answer = 2), otherwise. 
n = 3 + (n-3); (n-3) is an even number and it is sum of two primes(answer = 3).

*/


bool isPrime(int n) 
{ 
    int i = 2; 
    while (i * i <= n)
    { 
        if (n % i == 0) 
            return false; 
        i++; 
    } 
    return true; 
} 
  
int minimumSum(int n) 
{ 
    if (isPrime(n)) 
        return 1; 
  
    if (n % 2 == 0) 
        return 2; 
  
    if (isPrime(n - 2)) 
        return 2; 
    return 3; 
} 
