/*
Find sum of even factors of a number
Given a number n, the task is to find the even factor sum of a number.

Input : 30
Output : 48
Even dividers sum 2 + 6 + 10 + 30 = 48

Input : 18
Output : 26
Even dividers sum 2 + 6 + 18 = 26

sum of factors of a number 
Let p1, p2, … pk be prime factors of n. Let a1, a2, .. ak be highest powers of p1, p2, .. pk
respectively that divide n, i.e., we can write n as n = (p1^a1)*(p2^a2)* … (pk^ak).

Sum of divisors = (1 + p1 + p1^2 ... p1^a1) * 
                  (1 + p2 + p2^2 ... p2^a2) *
                  ...........................
                  (1 + pk + pk^2 ... pk^ak) 
If number is odd, then there are no even factors, so we simply return 0.

If number is even, we use above formula. We only need to ignore 2^0
All other terms multiply to produce even factor sum
For example, consider n = 18. It can be written as 2^1 3^2 and sum of all factors is (2^0 + 2^1)*(3^0 + 3^1 + 3^2)
if we remove 2^0 then we get the Sum of even factors (2)*(1+3+3^2) = 26

To remove odd number in even factor, we ignore then 2^0 whaich is 1. After this step, we only get even factors
Note that 2 is the only even prime.

*/

int sumofFactors(int n) 
{ 
    if (n % 2 != 0) 
       return 0;  
    int res = 1; 
    for (int i = 2; i <= sqrt(n); i++) 
    { 
        int count = 0, curr_sum = 1, curr_term = 1; 
        while (n % i == 0) 
        { 
            count++; 
            n = n / i; 
            if (i == 2 && count == 1) 
                curr_sum = 0; 
            curr_term *= i; 
            curr_sum += curr_term; 
        } 
  
        res *= curr_sum; 
    } 
    if (n >= 2) 
        res *= (1 + n); 
    return res; 
} 
