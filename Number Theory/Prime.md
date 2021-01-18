```cpp
 // prime numbers : numbers which are only divisible by themselves and one
bool isprime(ll n)
{
     if (n < 2)
        return 0;
     if (!(n&1))
        return (n == 2);
     for (ll i = 3; i * i <= n; i += 2)
        if (!(n%i))
            return 0;
     return 1;
}
// O(sqrt(n))

// Prime factor is the factor of the given number which is a prime number.
void primeFactors(ll n)  
{  
    for(ll i=2;i*i<=n;i++)  
    {  
        while(!(n%i))  
        {  
            cout<<i<<" ";  
            n/=i;  
        }  
    }    
    if (n>1)  
        cout<<n<<" ";  
} 
// O(sqrt(n))

// Facts
// int primelst[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97}; // [1-100]
// (2^31)-1 is a prime number with value 2147483647
// (2^61)-1 is a prime number with value 2305843009213693951
// primesRangeCnt 10^i (4, 25, 168, 1229, 9592, 78498, 664579, 5761455) [e.g. 4 primes <= 10^1] ~= n / log(n)
// 257, 263, 269, 271 -> 4 primes their multiplication > 2^32
// Wilson's theorem: (p-1)!%p = p-1 IFF p is prime
```
