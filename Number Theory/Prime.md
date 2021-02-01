```cpp
class PRIME
{
public:
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

    vector<int> primeFactors(ll n)
    {
        vector<int>res;
        for(ll i=2; i*i<=n; i++)
        {
            while(!(n%i))
            {
                res.push_back(i);
                n/=i;
            }
        }
        if(n>1)
            res.push_back(n);
        return res;
    }// O(sqrt(n))
};
```
