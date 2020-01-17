// Computes all the divisors of a positive integer.

template<class T>
vector<T> getDivisors(T n) 
{
    vector<T> divs;
    for (T i = 1; i * i <= n; ++i) 
    {
        if (n % i) continue;
        divs.push_back(i);
        if (i * i == n) continue;
        divs.push_back(n / i);
    }
    return divs;
}

// Complexity : O(sqrt(n))
