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

// =====================================================================================

// divs[i] : holds a list of all the divisors of integer "i".
vector<int> divs[N];

/**
 * Generates all the divisors of the integers from 1 to "n".
 * After calling this function, "divs[i]" will contains all the divisors of integer "i".
 *
 * Complexity: O(n.log(n))
 */
void generateDivisors(int n) {
    for (int i = 1; i <= n; ++i)
        for (int j = i; j <= n; j += i)
            divs[j].push_back(i);
}

// =====================================================================================
