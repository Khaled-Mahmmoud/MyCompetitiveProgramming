```cpp
This page contains a step by step explanation of simple but fast C++ implementation of segmented sieve 
of Eratosthenes that generates the primes below n using O(n log log n) operations and O(sqrt(n)) space
It runs significantly faster than  a traditional sieve of Eratosthenes implementation due to its more 
efficient CPU cache usage 
Problems with Simple Sieve:
The Sieve of Eratosthenes looks good, but consider the situation
when n is large the Simple Sieve faces following issues
An array of size Θ(n) may not fit in memory
The simple Sieve is not cache friendly even for slightly bigger n
The algorithm traverses the array without locality of reference Segmented Sieve
The idea of segmented sieve is to divide the range [0..n-1] in different segments 
and compute primes in all segments one by one
This algorithm first uses Simple Sieve to find primes smaller than or equal to √(n)
*/
void simpleSieve(int limit, vector<int> &prime)
{
    bool mark[limit+1];
    memset(mark, true, sizeof(mark));

    for (int i=2; i*i<limit; i++)
        if (mark[i])
            for (int j=i*2; j<limit; j+=i)
                mark[j] = false;

    for (int i=2; i<limit; i++)
        if (mark[i])
        {
            prime.push_back(i);
            cout << i << " ";
        }
}
void segmentedSieve(int n)
{
    int limit = sqrt(n)+1;
    vector<int> prime;
    simpleSieve(limit, prime);
    int low = limit;
    int high = 2*limit;
    while (low < n)
    {
        if (high >= n)
            high = n;
        bool mark[limit+1];
        memset(mark, true, sizeof(mark));
        for (int i = 0; i < prime.size(); i++)
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
                cout << i << " ";
        low = low + limit;
        high = high + limit;
    }
}
```
