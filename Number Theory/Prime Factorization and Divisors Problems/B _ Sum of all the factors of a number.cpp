/*
Sum of all the factors of a number
Given a number n, the task is to find the sum of all the divisors.

Examples :

Input : n = 30
Output : 72
Dividers sum 1 + 2 + 3 + 5 + 6 + 
             10 + 15 + 30 = 72 

Input :  n = 15
Output : 24
Dividers sum 1 + 3 + 5 + 15 = 24

A simple solution is to traverse through all divisors and add them

*/

int divSum(int n) 
{ 
    int result = 0;
    for (int i = 2; i <= sqrt(n); i++) 
    { 
        if (n % i)
        continue;
        result += i;
        if(i*i == n)
        continue;
        result += n/i;
    } 
    return result ; 
} 
// Time Complexity : O(sqrt(n))
/*
An efficient solution is to use below formula
Let p1, p2, … pk be prime factors of n. Let a1, a2, .. ak be highest powers of p1, p2, .. pk respectively 
that divide n, i.e., we can write n as n = (p1^a1)*(p2^a2)* … (pk^ak).

Sum of divisors = (1 + p1 + p1^2 ... p1^a1) * 
                  (1 + p2 + p2^2 ... p2^a2) *
                  .............................................
                  (1 + pk + pk^2 ... pk^ak) 

We can notice that individual terms of above formula are Geometric Progressions (GP)
We can rewrite the formula as.

Sum of divisors = (p1^(a1+1) - 1)/(p1 -1) * 
                  (p2^(a2+1) - 1)/(p2 -1) *
                  .........................
                  (pk^(ak+1) - 1)/(pk -1)
                  
                  
How does above formula work?
Consider the number 18
Sum of factors = 1 + 2 + 3 + 6 + 9 + 18
Writing divisors as powers of prime factors.
Sum of factors = (2^0)(3^0) + (2^1)(3^0) + (2^0)(3^1) +
                 (2^1)(3^1) + (2^0)(3^2) + (2^1)(3^2)
               = (2^0)(3^0) + (2^0)(3^1) + (2^0)(3^2) +
                 (2^1)(3^0) + (2^1)(3^1) + (2^1)(3^2)
               = (2^0)(3^0 + 3^1 + 3^2) + 
                 (2^1)(3^0 + 3^1 + 3^2)
               = (2^0 + 2^1)(3^0 + 3^1 + 3^2)
If we take a closer look, we can notice that the above expression is in the form.
(1 + p1) * (1 + p2 + p2^2)
Where p1 = 2 and p2 = 3 and 18 = 2^1  3^2
So the task reduces to finding all prime factors and their powers

*/


int sumofFactors(int n) 
{ 
    int res = 1; 
    for (int i = 2; i <= sqrt(n); i++) 
    { 
        int curr_sum = 1; 
        int curr_term = 1; 
        while (n % i == 0)
        {  
            n = n / i; 
            curr_term *= i; 
            curr_sum += curr_term; 
        } 
  
        res *= curr_sum; 
    } 
    if (n >= 2) 
        res *= (1 + n); 
  
    return res; 
} 
// Time Complexity : O(sqrt(n)*log(n))
/*
Further Optimization.
If there are multiple queries, we can use Sieve to find prime factors and their powers  log(n)
*/
