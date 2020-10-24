
# Finding power of prime number p in n!

Given a number ‘n’ and a prime number ‘p’. We need to find out the power of ‘p’ in the prime factorization of n!
         
|Input|Output|
|---|---|
|n = 4, p = 2|3|
         
Power of 2 in the prime factorization of 2 in 4! = 24 is 3

**Naive approach**
The naive approach is to find the power of p in each number from 1 to n and add them
Because we know that during multiplication power are added

**Efficient Approach**
Before discussing efficient approach lets discuss a question given two numbers n, m how many numbers are there from 1 to n
that are divisible by m the answer is `floor(n/m)`. Now coming back to our original question to find the power of p in n!
what we do is count the number of numbers from 1 to n that are divisible by p then by p^2 then by p^3 till p^k > n and add them
This will be our required answer
   `Powerofp(n!) = floor(n/p) + floor(n/p^2) + floor(n/p^3)........`
   
```cpp
int PowerOFPINnfactorial(int n, int p) 
{ 
    int ans = 0; 
    int temp = p; 
    while (temp <= n)
    { 
        ans += n / temp; 
        temp = temp * p; 
    } 
    return ans; 
} 

```
Time Complexity :O(log_p(n))

### what is max x such that m^x divides n!?

Again, think in prime representation.

Assume g = n!

let's simplify, such that m^x divides g?

Let m =  2^3 * 5^4

Let g =  2^10 * 5^8 * 11^3

the prime factor of m that are 2 and 5

10/3 = 3, then max for p1=2 is (2^3)^3 = 2^9

8/4 = 2, so max is (5^4)^2 = 5^8

Then let x = min(3, 2) = 2 ... so m^2 divides g

what if m = 2^3 * 5^4 * 7^2 ? then it doesn't divide g, and x = 0
