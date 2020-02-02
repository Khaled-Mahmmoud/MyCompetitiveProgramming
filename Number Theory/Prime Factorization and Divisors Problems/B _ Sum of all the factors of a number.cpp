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

/*
An efficient solution is to use below formula
Let p1, p2, … pk be prime factors of n. Let a1, a2, .. ak be highest powers of p1, p2, .. pk respectively 
that divide n, i.e., we can write n as n = (p1a1)*(p2a2)* … (pkak).

Sum of divisors = (1 + p1 + p12 ... p1a1) * 
                  (1 + p2 + p22 ... p2a2) *
                  .............................................
                  (1 + pk + pk2 ... pkak) 

We can notice that individual terms of above 
formula are Geometric Progressions (GP). We
can rewrite the formula as.

Sum of divisors = (p1a1+1 - 1)/(p1 -1) * 
                  (p2a2+1 - 1)/(p2 -1) *
                  ..................................
                  (pkak+1 - 1)/(pk -1)
How does above formula work?

Consider the number 18.  

Sum of factors = 1 + 2 + 3 + 6 + 9 + 18

Writing divisors as powers of prime factors.
Sum of factors = (20)(30) + (21)(30) + (2^0)(31) +
                 (21)(31) + (20)(3^2) + (2^1)(32)
               = (20)(30) + (2^0)(31) + (2^0)(32) +
                 (21)(3^0) + (21)(31) + (21)(32)
               = (20)(30 + 31 + 32) + 
                 (21)(30 + 31 + 32)
               = (20 + 21)(30 + 31 + 32)
If we take a closer look, we can notice that the
above expression is in the form.
(1 + p1) * (1 + p2 + p22)
Where p1 = 2 and p2 = 3 and 18 = 2132
So the task reduces to finding all prime factors and their powers.
filter_none
edit
play_arrow

brightness_4
// Formula based CPP program to 
// find sum of all  divisors of n. 
#include <bits/stdc++.h> 
using namespace std; 
  
// Returns sum of all factors of n. 
int sumofFactors(int n) 
{ 
    // Traversing through all prime factors. 
    int res = 1; 
    for (int i = 2; i <= sqrt(n); i++) 
    { 
  
          
        int curr_sum = 1; 
        int curr_term = 1; 
        while (n % i == 0) { 
  
            // THE BELOW STATEMENT MAKES 
            // IT BETTER THAN ABOVE METHOD  
            //  AS WE REDUCE VALUE OF n. 
            n = n / i; 
  
            curr_term *= i; 
            curr_sum += curr_term; 
        } 
  
        res *= curr_sum; 
    } 
  
    // This condition is to handle  
    // the case when n is a prime 
    // number greater than 2. 
    if (n >= 2) 
        res *= (1 + n); 
  
    return res; 
} 
  
// Driver code 
int main() 
{ 
    int n = 30; 
    cout << sumofFactors(n); 
    return 0; 
} 
*/

