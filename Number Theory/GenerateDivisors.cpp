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
 for this code only
 n=10^5 -->> 2s
 n=10^6 -->> 19s
 */
void generateDivisors(int n) {
    for (int i = 1; i <= n; ++i)
        for (int j = i; j <= n; j += i)
            divs[j].push_back(i);
}

// =====================================================================================
/*
Given an array of integers and you have to find the index of the number witch has the maximum number of divisors, 
if there many answers print the smallest index
N <= 10^6
a[i] <= 10^6
*/

#define N  1000000
vector<int>d(N);
int main()
{
    for (int i = 1; i < N; ++i)
        for (int j = i; j < N; j += i)
            d[j]++;
    int n,x,idx=0,mx=0;cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        if(mx<d[x]){mx=d[x];idx=i;}
    }
    cout<<idx;
    return 0;
}
