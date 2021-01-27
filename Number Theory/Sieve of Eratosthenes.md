```cpp
class SIEVE
{
    const int N = 1e7;
    vector<int>spf;
public:
    SIEVE()
    {
        spf.resize(N);
        for(int i=2; i*i<N; i++)
            if(!spf[i])
                for(int j=i*2; j<N; j+=i)
                    if(!spf[j])
                        spf[j] = i;
        for(int i=2; i<N; i++)
            if(!spf[i])
                spf[i] = i;
    }// O(n.log(log(n)))

    vector<int> primeFactors(int x)
    {
        vector<int> res;
        while (x != 1)
        {
            res.push_back(spf[x]);
            x = x / spf[x];
        }
        return res;
    }// O(log(n))

    bool isprime(int x)
    {
        return (x == spf[x]);
    }

    // Store all prime numbers less than 10^7 in vector
    vector<int> getPrimes(int n)
    {
        vector<int> ans;
        for(int i = 1; i <= n; ++i)
            if(i==spf[i])
                ans.push_back(i);
        return ans;
    }// O(n)

    // Generate prime divisors for all number from 1 to n
    vector<vector<int>> primeDivisors(int n)
    {
        vector<vector<int>> ans(n+1);
        for(int i = 1; i <= n; ++i)
                ans[i] = primeFactors(i);
        return ans;
    }// O(n*log(n)) // max -> 1e6
};
```
