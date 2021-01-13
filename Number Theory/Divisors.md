```cpp
template<class T>
vector<T> get_div(T n) 
{
    vector<T> divs;
    for (T i = 1; i * i <= n; ++i) 
    {
        if (n % i) 
           continue;
        divs.push_back(i);
        if (i * i == n) 
           continue;
        divs.push_back(n / i);
    }
    return divs;
}// O(sqrt(n))

// Count all the divisors of the integers from 1 to "n"
vector<int> divs[N];
void cnt_div(int n) 
{
    for (int i = 1; i <= n; ++i)
        for (int j = i; j <= n; j += i)
            divs[j]++;
}// O(n.log(n))

// generate divisors for all number from 1 to n
// O(n*log(n)) // max-> 1e6
const int N = 1e6;
vector<int> divs[N + 1];
void generate_div() 
{
	for (int i = 1; i <= N; i++)
		for (int j = i; j <= N; j += i)
			divs[j].push_back(i);
}

// Count all perfect divisors of a number from 1 to n
int perfectDiv[MAX]; 
void cnt_per_div() 
{ 
    for (int i=1; i*i < MAX; ++i) 
        for (int j=i*i; j < MAX; j += i*i) 
              perfectDiv[j]++; 
} 

// only perfect square numbers have odd number of divisors
// Check if count of divisors is even or odd
void check(int n) 
{ 
    int root_n = sqrt(n); 
    if (root_n * root_n == n) 
        printf("Odd\n"); 
    else
        printf("Even\n"); 
} 

/*
Check whether a number has exactly three distinct factors or not?
If the square root of given number(say x^2) is prime then it must have exactly three distinct factors
1) A number 1 of course.
2) Square root of a number i.e., x(prime number).
3) Number itself i.e., x^2.
*/

/*
 for any p prime number, p^n has n+1 divisors,Ex 2^4 has 5 divisors 2^0, 2^1...2^4
 what about not prime number n = p1^a * p1^b  , it's (a+1) * (b+1)
 
 what about Factorizing n^power
 Simply if n     =  p1^a  *	p2^b   * p3^c
 Then n^z        = p1^az  *	p2^bz  * p3^cz
 Divisors of n   = (a+1)  * (b+1)  * (c+1)
 Divisors of n^z = (az+1) * (bz+1) * (cz+1)
 */
 
 /*

// return sum of divisors for all number from 1 to n
//O(n) // max -> 1e8
ll get_sum_div(int n) 
{
	ll ans = 0;
	for (int x = 1; x <= n; x++)
		ans += (n / x) * x;
	return ans;
}

// return sum of divisors for all number from 1 to n
// max -> 1e9
ll get_sum_div(ll x)
{
    ll ans = 0, left = 1, right;
    for (; left <= x; left = right + 1)
    {
        right = x / (x / left);
        ans += (x / left) * (left + right) * (right - left + 1) / 2;
    }
    return ans;
}

// Sum of divisors of a number	
Given a number n, the task is to find the sum of all the divisors.
A simple solution is to traverse through all divisors and add them. O(sqrt(n))
An efficient solution is to use below formula
Let p1, p2, … pk be prime factors of n. Let a1, a2, .. ak be highest powers of p1, p2, .. pk respectively 
that divide n, i.e., we can write n as n = (p1^a1) * (p2^a2)  *  … (pk^ak).

Sum of divisors = (1 + p1 + p1^2 ... p1^a1) * 
                  (1 + p2 + p2^2 ... p2^a2) *
                  ...........................
                  (1 + pk + pk^2 ... pk^ak) 
                  
We can notice that individual terms of above 
formula are Geometric Progressions (GP). We can rewrite the formula as.

Sum of divisors = (p1^(a1+1) - 1) / (p1 -1) * 
                  (p2^(a2+1) - 1) / (p2 -1) *
                  .........................
                  (pk^(ak+1) - 1) / (pk -1)
                  
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
If we take a closer look, we can notice that the above expression is in the form. (1 + p1) * (1 + p2 + p2^2)
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
    if (n > 1) 
        res *= (1 + n); 
  
    return res; 
} 
// O(sqrt(n))
// Optimization: If there are multiple queries, we can use Sieve  log(n)
/*
// Sum of divisors of factorial of a number	
Given a number n, we need to calculate the sum of divisors of factorial of the number	

A Simple Solution is to first compute factorial of given number, then count sum divisors of the factorial	
This solution is not efficient and may cause overflow due to factorial computation	

An efficient solution** is based on Legendre’s formula
Find all prime numbers less than or equal to n. We can use Sieve Algorithm for this. Let n be 6	
All prime numbers less than 6 are {2, 3, 5}.	
For each prime number p find the largest power of it that divides n!. We use below Legendre’s formula for this purpose	
The value of largest power that divides p is floor value of each term `n/p + n/(p^2) + n/(p^3) + ……`	
Let these values be exp1, exp2, exp3, .. Using the above formula, we get below values for n = 6.	

The largest power of 2 that divides 6!, exp1 = 4.	
The largest power of 3 that divides 6!, exp2 = 2.	
The largest power of 5 that divides 6!, exp3 = 1.	
6! = 2^4 * 3^2 * 5^1`
The sum of divisors of 6! = (2^0 + 2^1 + 2^2 + 2^3 + 2^4) * (3^0 + 3^1 + 3^2) * (5^0 + 5^1)
*/
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
// O(n log log n)
/*
Find sum of even factors of a number
Given a number n, the task is to find the even factor sum of a number.
Sum of factors of a number :  
Let p1, p2, … pk be prime factors of n. Let a1, a2, .. ak be highest powers of p1, p2, .. pk
respectively that divide n, i.e., we can write n as n = (p1^a1)*(p2^a2)* … (pk^ak).
Sum of divisors = (1 + p1 + p1^2 ... p1^a1) * 
                  (1 + p2 + p2^2 ... p2^a2) *
                  ...........................
                  (1 + pk + pk^2 ... pk^ak) 
If number is odd, then there are no even factors, so we simply return 0.
If number is even, we use above formula. We only need to ignore 2^0
All other terms multiply to produce even factor sum.
For example, consider n = 18. It can be written as 2^1 3^2 and sum of all factors is (2^0 + 2^1) * (3^0 + 3^1 + 3^2)
if we remove 2^0 then we get the Sum of even factors (2)* (1+3+3^2) = 26
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
/*
Find sum of odd factors of a number
Given a number n, the task is to find the odd factor sum.
To find sum of odd factors, we simply need to ignore even factors and their powers. For example, consider n = 18
It can be written as 2^1 3^2 and sum of all factors is (2^0 + 2^1)*(3^0 + 3^1 + 3^2). Sum of odd factors (3^0+3^1+3^2) = 13.
To remove all even factors, we repeatedly divide n while it is divisible by 2
After this step, we only get odd factors. Note that 2 is the only even prime
*/
int sumofoddFactors(int n) 
{ 
    int res = 1; 
    while (n % 2 == 0) 
        n = n / 2; 
    for (int i = 3; i <= sqrt(n); i++)  
    { 
        int curr_sum = 1 , curr_term = 1; 
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
/*
assume we have 60 = 2^2 * 3 * 5 = 2^p * 3^q * 5^r
factors of 60 = 1 2 3 4 5 6 10 12 20 15 30 60
count number of factors = (p+1) * (q+1) * (r+1)
count number of odd factors = (q+1) * (r+1) = 2 * 2 = 4 (we ignore higest power of 2)
count number of even factors = (p+1) * (q+r) * (r+1) - (q+r) * (r+1) = (p) * (q+r) * (r+1) = 8  
count sum of odd factors = (3^0 + 3^1) * (5^0 + 5^1) = 24 (we ignore 2^0 + 2^1 + 2^2 )
count sum of even factors = (2^1 + 2^2) * (3^0 + 3^1) * (5^0 + 5^1) = 144  (we ignore 2^0)
*/
 ```
