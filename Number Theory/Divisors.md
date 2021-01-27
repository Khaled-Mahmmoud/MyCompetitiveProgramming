```cpp
class DIV
{
    void get_div(ll n)
    {
        vector<ll> divs;
        for (ll i = 1; i * i <= n; ++i)
        {
            if (n % i)
                continue;
            divs.push_back(i);
            if (i * i == n)
                continue;
            divs.push_back(n / i);
        }
    }// O(sqrt(n))
    // generate divisors for all number from 1 to n
    void generate_div(int n)
    {
        vector<int>divs(n+1);
        for (int i = 1; i <= n; i++)
            for (int j = i; j <= n; j += i)
                divs[j].push_back(i);
    }// O(n*log(n)) // max-> 1e6
    // Count all the divisors of the integers from 1 to "n"
    void cnt_div(int n)
    {
        vector<int>divs(n+1);
        for (int i = 1; i <= n; ++i)
            for (int j = i; j <= n; j += i)
                divs[j]++;
    }// O(n.log(n)) // max-> 1e7
    // Count all perfect divisors of a number from 1 to n
    void cnt_per_div(int n)
    {
        vector<int>perfectDiv(n+1);
        for (int i=1; i*i <= n; ++i)
            for (int j=i*i; j <= n; j += i*i)
                perfectDiv[j]++;
    }// O(sqrt(n).log(n))
    // only perfect square numbers have odd number of divisors
    // Check if count of divisors is even or odd
    void check(ll n)
    {
        ll root_n = sqrt(n);
        if (root_n * root_n == n)
            cout<<"Odd\n";
        else
            cout<<"Even\n";
    }
    // return sum of divisors for all number from 1 to n
    ll get_sum_div(int n)
    {
        ll ans = 0;
        for (int x = 1; x <= n; x++)
            ans += (n / x) * x;
        return ans;
    }// O(n) 
};

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
// Sum of divisors of a number	
n = (p1^a1) * (p2^a2)  *  … (pk^ak).
Sum of divisors = (1 + p1 + p1^2 ... p1^a1) * 
                  (1 + p2 + p2^2 ... p2^a2) *
                  ...........................
                  (1 + pk + pk^2 ... pk^ak) 
using  Geometric Progressions (GP)
Sum of divisors = (p1^(a1+1) - 1) / (p1 -1) * 
                  (p2^(a2+1) - 1) / (p2 -1) *
                  .........................
                  (pk^(ak+1) - 1) / (pk -1)
How does above formula work?
Consider the number 18, Sum of factors = 1 + 2 + 3 + 6 + 9 + 18
Writing divisors as powers of prime factors.
Sum of factors = (2^0)(3^0) + (2^1)(3^0) + (2^0)(3^1) +
                 (2^1)(3^1) + (2^0)(3^2) + (2^1)(3^2)
               = (2^0)(3^0) + (2^0)(3^1) + (2^0)(3^2) +
                 (2^1)(3^0) + (2^1)(3^1) + (2^1)(3^2)
               = (2^0)(3^0 + 3^1 + 3^2) + 
                 (2^1)(3^0 + 3^1 + 3^2)
               = (2^0 + 2^1)(3^0 + 3^1 + 3^2)
If we take a closer look, we can notice that the above expression is in the form. (1 + p1) * (1 + p2 + p2^2)
So the task reduces to finding all prime factors and their powers
*/

/*
// Sum of divisors of factorial of a number	
An efficient solution is based on Legendre’s formula Find all prime numbers less than or equal to n. 
Let n be 6, All prime numbers less than 6 are {2, 3, 5}.
The largest power of 2 that divides 6!, exp1 = 4.	
The largest power of 3 that divides 6!, exp2 = 2.	
The largest power of 5 that divides 6!, exp3 = 1.	
6! = 2^4 * 3^2 * 5^1
The sum of divisors of 6! = (2^0 + 2^1 + 2^2 + 2^3 + 2^4) * (3^0 + 3^1 + 3^2) * (5^0 + 5^1)
*/

/*
60 = 2^2 * 3 * 5 = 2^p * 3^q * 5^r
count number of factors = (p+1) * (q+1) * (r+1)
count number of odd factors = (q+1) * (r+1) = 2 * 2 = 4 (we ignore higest power of p)
count number of even factors = (p+1) * (q+r) * (r+1) - (q+r) * (r+1) = (p) * (q+r) * (r+1) = 8  (we ignore p^0)
count sum of odd factors = (3^0 + 3^1) * (5^0 + 5^1) = 24 (we ignore 2^0 + 2^1 + 2^2 )
count sum of even factors = (2^1 + 2^2) * (3^0 + 3^1) * (5^0 + 5^1) = 144  (we ignore 2^0)
*/
 ```
