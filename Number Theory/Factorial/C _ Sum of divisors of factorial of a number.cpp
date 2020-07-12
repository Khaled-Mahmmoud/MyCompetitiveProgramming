/*

Given a number n, we need to calculate the sum of divisors of factorial of the number

Input : 4
Output : 60
Factorial of 4 is 24. Divisors of 24 are
1 2 3 4 6 8 12 24, sum of these is 60.

A Simple Solution is to first compute factorial of given number, then count sum divisors of the factorial
This solution is not efficient and may cause overflow due to factorial computation

An efficient solution is based on Legendre’s formula. Below are the steps.

Find all prime numbers less than or equal to n (input number). We can use Sieve Algorithm for this. Let n be 6
All prime numbers less than 6 are {2, 3, 5}.
For each prime number p find the largest power of it that divides n!. We use below Legendre’s formula formula for this purpose
The value of largest power that divides p is floor value of each term n/p + n/(p^2) + n/(p^3) + ……
Let these values be exp1, exp2, exp3, .. Using the above formula, we get below values for n = 6.

The largest power of 2 that divides 6!, exp1 = 4.
The largest power of 3 that divides 6!, exp2 = 2.
The largest power of 5 that divides 6!, exp3 = 1.
6! = 2^4 * 3^2 * 5^1
The result = (2^0 + 2^1 + 2^2 + 2^3 + 2^4) * (3^0 + 3^1 + 3^2) * (5^0 + 5^1)

*/

#include<bits/stdc++.h> 
#include<math.h> 
using namespace std; 
vector<int> allPrimes; 
void sieve(int n) 
{ 
    vector<bool> prime(n+1, true); 
    for (int p = 2; p*p <= n; p++) 
    { 
        if (prime[p] == true) 
        { 
            for (int i = p*2; i <= n; i += p) 
                prime[i] = false; 
        } 
    } 
    for (int p = 2; p <= n; p++) 
        if (prime[p]) 
            allPrimes.push_back(p); 
} 
int factorialDivisors(int n) 
{ 
    sieve(n);
    int result = 1; 
    for (int i = 0; i < allPrimes.size(); i++) 
    { 
        int p = allPrimes[i]; 
        int exp = 0; 
        while (p <= n) 
        { 
            exp = exp + (n/p); 
            p = p*allPrimes[i]; 
        } 
  
        // Using the divisor function to calculate 
        // go to MyCompetitiveProgramming/Number Theory/Prime Factorization and Divisors Problems/B _ Sum of all the factors of a number.cpp
        result = result*(pow(allPrimes[i], exp+1)-1)/(allPrimes[i]-1); 
    } 
    return result; 
} 
int main() 
{ 
    cout << factorialDivisors(4); 
    return 0; 
} 
