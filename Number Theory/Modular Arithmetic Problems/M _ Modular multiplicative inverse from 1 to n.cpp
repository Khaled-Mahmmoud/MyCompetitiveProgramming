/*

Modular multiplicative inverse from 1 to n
Give a positive integer n, find modular multiplicative inverse of all integer
from 1 to n with respect to a big prime number, say, ‘prime’

The modular multiplicative inverse of a is an integer ‘x’ such that.

 a x ≡ 1 (mod prime) 

Input : n = 10, prime = 17
Output : 1 9 6 13 7 3 5 15 2 12
Explanation :
For 1, modular inverse is 1 as (1 * 1)%17 is 1
For 2, modular inverse is 9 as (2 * 9)%17 is 1
For 3, modular inverse is 6 as (3 * 6)%17 is 1
....... 

Input : n = 5, prime = 7
Output : 1 4 5 2 3


An efficient solution is based on extended Euclid algorithm.

Extended Euclidean algorithm finds integer coefficients x and y such that:

  ax + by = gcd(a, b)

Let us put b = prime, we get
  ax + prime * y = gcd(a, prime)

We know gcd(a, prime) = 1 because
on of the numbers is prime. So we
know
  ax + prime * y = 1

Since prime * y is a multiple of prime,
x is modular multiplicative inverse of a.

 ax  ≡ 1 (mod prime) 
 
We can recursively find x using below expression (see extended Euclid algorithm for details).

The extended Euclidean algorithm updates results of gcd(a, b) using the results calculated by recursive call gcd(b%a, a)
Let values of x and y calculated by the recursive call be xprev and yprev. x and y are updated using below expressions.

x = yprev - ⌊prime/a⌋ * xprev
y = xprev
We use above relation to compute inverse using previously computed values.

inverse(a) = (inverse(prime % a) *
              (prime - prime/a)) % prime
We use Dynamic Programming approach that uses above recursive structure.

Dynamic Approach :
dp[1] = 1,
dp[2] = dp[17%2]*(17-17/2)%17 = 9
dp[3] = dp[17%3]*(17-17/3)%17 = 6


*/

void modularInverse(int n, int prime) 
{ 
    int dp[n + 1]; 
    dp[0] = dp[1] = 1; 
    for (int i = 2; i <= n; i++)  
        dp[i] = dp[prime % i] *  
               (prime - prime / i) % prime;     
  
    for (int i = 1; i <= n; i++)  
        cout << dp[i] << ' ';     
} 
int main() 
{ 
    int n = 10, prime = 17; 
    modularInverse(n, prime); 
    return 0; 
} 
/*
Output:
1 9 6 13 7 3 5 15 2 12
Time Complexity : O(n)
Auxiliary Space : O(n)
