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
Given an array of integers and you have to find the index of the number which has the maximum number of divisors, 
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
/*
Count all perfect divisors of a number
Given a number n, count total perfect divisors of n.
Perfect divisors are those divisors which are square of some integer
For example a perfect divisor of 8 is 4.
Examples:

Input  : n = 16 
Output : 3
Explanation : There are only 5 divisor of 16:
1, 2, 4, 8, 16. Only three of them are perfect 
squares: 1, 4, 16. Therefore the answer is 3
*/
int perfectDiv[MAX]; 
void precomputeCounts() 
{ 
    for (int i=1; i*i < MAX; ++i) 
    { 
        for (int j=i*i; j < MAX; j += i*i) 
              perfectDiv[j]++; 
    } 
} 
  
/*
we should know that only perfect square numbers have odd number of divisors 
 4 (1, 2, 4) has 3 divisors
 9 (1, 3, 9) has 3 divisors
 25 (1, 5, 25) has 3 divisors
 49 (1, 7 and 49)  has 3 divisors
 36 (1, 2, 3, 4, 6, 9, 12, 18, 36) has 9 divisors
 100 (1, 2, 4, 5, 10, 20, 25, 50, 100) has 9 divisors
 
Check whether a number has exactly three distinct factors or not
According to property of perfect square, “Every perfect square(x^2) always have only odd numbers of factors“.
If the square root of given number(say x^2) is prime then it must have exactly three distinct factors 

A number 1 of course.
Square root of a number i.e., x(prime number).
Number itself i.e., x^2.

*/
