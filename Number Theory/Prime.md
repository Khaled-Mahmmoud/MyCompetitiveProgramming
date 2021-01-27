```cpp
class PRIME
{
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
    }// O(sqrt(n))
    
    void primeFactors(ll n)
    {
        for(ll i=2; i*i<=n; i++)
        {
            while(!(n%i))
            {
                cout<<i<<" ";
                n/=i;
            }
        }
        if (n>1)
            cout<<n<<" ";
    }// O(sqrt(n))
};
```
