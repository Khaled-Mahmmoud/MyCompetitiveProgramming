### Sum of all the factors of a number

Given a number n, the task is to find the sum of all the divisors.

A simple solution is to traverse through all divisors and add them. O(sqrt(n))

An efficient solution is to use below formula

Let p1, p2, … pk be prime factors of n. Let a1, a2, .. ak be highest powers of p1, p2, .. pk respectively 
that divide n, i.e., we can write n as n = (p1^a1) * (p2^a2)  *  … (pk^ak).
```
Sum of divisors = (1 + p1 + p1^2 ... p1^a1) * 
                  (1 + p2 + p2^2 ... p2^a2) *
                  .............................................
                  (1 + pk + pk^2 ... pk^ak) 
```

How does above formula work?
Consider the number 18
Sum of factors = 1 + 2 + 3 + 6 + 9 + 18
Writing divisors as powers of prime factors.
````
Sum of factors = (2^0)(3^0) + (2^1)(3^0) + (2^0)(3^1) +
                 (2^1)(3^1) + (2^0)(3^2) + (2^1)(3^2)
               = (2^0)(3^0) + (2^0)(3^1) + (2^0)(3^2) +
                 (2^1)(3^0) + (2^1)(3^1) + (2^1)(3^2)
               = (2^0)(3^0 + 3^1 + 3^2) + 
                 (2^1)(3^0 + 3^1 + 3^2)
               = (2^0 + 2^1)(3^0 + 3^1 + 3^2)
````
If we take a closer look, we can notice that the above expression is in the form. (1 + p1) * (1 + p2 + p2^2)
Where p1 = 2 and p2 = 3 and 18 = 2^1  3^2
So the task reduces to finding all prime factors and their powers
```cpp
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
    if (n > 1) 
        res *= (1 + n); 
  
    return res; 
} 
```
Time Complexity : O(sqrt(n))

Further Optimization: If there are multiple queries, we can use Sieve to find prime factors and their powers  log(n)



### Sum of divisors of factorial of a number	
Given a number n, we need to calculate the sum of divisors of factorial of the number	

|Input|Output| 	
|---|---|	
|4|60|	
|6|2418|	

Factorial of 4 is 24. Divisors of 24 are	
1 2 3 4 6 8 12 24, sum of these is 60.	

A **Simple Solution** is to first compute factorial of given number, then count sum divisors of the factorial	
This solution is not efficient and may cause overflow due to factorial computation	

An **efficient solution** is based on **Legendre’s formula**.

Find all prime numbers less than or equal to n. We can use Sieve Algorithm for this. Let n be 6	
All prime numbers less than 6 are {2, 3, 5}.	
For each prime number p find the largest power of it that divides n!. We use below Legendre’s formula for this purpose	
The value of largest power that divides p is floor value of each term `n/p + n/(p^2) + n/(p^3) + ……`	
Let these values be exp1, exp2, exp3, .. Using the above formula, we get below values for n = 6.	


The largest power of 2 that divides 6!, exp1 = 4.	

The largest power of 3 that divides 6!, exp2 = 2.	

The largest power of 5 that divides 6!, exp3 = 1.	

`6! = 2^4 * 3^2 * 5^1`	

the sum of divisors of `6! = (2^0 + 2^1 + 2^2 + 2^3 + 2^4) * (3^0 + 3^1 + 3^2) * (5^0 + 5^1)`	

```cpp	
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
        result = result*(pow(allPrimes[i], exp+1)-1)/(allPrimes[i]-1); 	
    } 	
    return result; 	
} 	
int main() 	
{ 	
    cout << factorialDivisors(4); 	
    return 0; 	
} 	
```	
Time Complexity : O(n log log n)

