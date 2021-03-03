```cpp
// Sieve of Eratosthenes: O(n.log(log(n))) and Space: O(n)
// Segmented Sieve: O(n.log(log(n))) and Space: O(sqrt(n))
class SEGSIEVE
{
public:
    void simpleSieve(int L, vector<int> &prime)
    {
        vector<bool>mark(L,true);
        for (int i=2; i*i<L; i++)
            if (mark[i])
                for (int j=i*2; j<L; j+=i)
                    mark[j] = false;
        for (int i=2; i<L; i++)
            if (mark[i])
                prime.push_back(i);
    }
    // get all prime numbers less than n
    void segmentedSieve(int n)
    {
        int L = sqrt(n)+1;
        vector<int> prime;
        simpleSieve(L, prime);
        for(int i=0;i<sz(prime);i++)
            cout<<prime[i]<<' ';
        int low = L;
        int high = 2*L;
        while (low < n)
        {
            if (high >= n)
                high = n;
            bool mark[L+1];
            memset(mark, true, sizeof(mark));
            for (int i = 0; i < sz(prime); i++)
            {
                int loLim = (low/prime[i]) * prime[i];
                if (loLim < low)
                    loLim += prime[i];
                if(loLim == prime[i])
                    loLim += prime[i];
                for (int j=loLim; j<high; j+=prime[i])
                    mark[j-low] = false;
            }
            for (int i = low; i<high; i++)
                if (mark[i - low] == true)
                    cout<<i<<' ';
            low = low + L;
            high = high + L;
        }
    }
    // get all prime numbers between low and high <= 1e9 and high - low <= 1e6
    void segmentedSieve(int low,int high)
    {
        int L = sqrt(high)+1;
        vector<int> prime;
        simpleSieve(L, prime);
        bool mark[(high-low+1)+1];
        memset(mark, true, sizeof(mark));
        for (int i = 0; i < sz(prime); i++)
        {
            int loLim = (low/prime[i]) * prime[i];
            if (loLim < low)
                loLim += prime[i];
            if(loLim == prime[i])
                loLim += prime[i];
            for (int j=loLim; j<=high; j+=prime[i])
                mark[j-low] = false;
        }
        for (int i = low; i<=high; i++)
            if (mark[i - low] == true&&i!=1)
                cout<<i<<' ';
    }
};
```
