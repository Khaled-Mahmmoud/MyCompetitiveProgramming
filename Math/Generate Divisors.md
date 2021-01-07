
```cpp
// Generate Divisors
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
// Generates all the divisors of the integers from 1 to "n"
vector<int> divs[N];
void generateDivisors(int n) 
{
    for (int i = 1; i <= n; ++i)
        for (int j = i; j <= n; j += i)
            divs[j].push_back(i);
}
// After calling this function, "divs[i]" will contains all the divisors of integer "i".
// Complexity: O(n.log(n))   
/*
for this code only: 
n=10^4 -->> 0.8s,
n=10^5 -->> 2s,
n=10^6 -->> 19s    
*/

// Given an array of integers and you have to find the index of the number which has the maximum number of divisors, 
// if there many answers print the smallest index.
#define N  1000000
vector<int>d(N);
int main()
{
    for (int i = 1; i < N; ++i)
        for (int j = i; j < N; j += i)
            d[j]++;
    int n,x,idx=0,mx=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        if(mx<d[x]){mx=d[x];idx=i;}
    }
    cout<<idx;
    return 0;
}
// Count all perfect divisors of a number
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
we should know that **only perfect square numbers have odd number of divisors** 

4 (1, 2, 4) has 3 divisors

9 (1, 3, 9) has 3 divisors

25 (1, 5, 25) has 3 divisors

49 (1, 7 and 49)  has 3 divisors

36 (1, 2, 3, 4, 6, 9, 12, 18, 36) has 9 divisors

100 (1, 2, 4, 5, 10, 20, 25, 50, 100) has 9 divisors
 */
// Check if count of divisors is even or odd
void countDivisors(int n) 
{ 
    int root_n = sqrt(n); 
    
    if (root_n * root_n == n) 
        printf("Odd\n"); 
    else
        printf("Even\n"); 
} 
```
 
### Check whether a number has exactly three distinct factors or not?
    
According to property of perfect square, “Every perfect square(x^2) always have only odd numbers of factors“
If the square root of given number(say x^2) is prime then it must have exactly three distinct factors i.e,

1) A number 1 of course.
2) Square root of a number i.e., x(prime number).
3) Number itself i.e., x^2.

 ### Counting tne number of the divisors of number
 
 2^4 has 5 divisors 2^0, 2^1...2^4
 
 p^n has n+1 divisors for any p prime number
 
 what about p1^a  p1^b  , it's (a+1) * (b+1)
 
 E.g. 12 2^2  3^1	has 3 * 2 divisors.
 
 12 = 2^0  3^0
 
 12 = 2^0  3^1
 
 12 = 2^1  3^0
 
 12 = 2^1  3^1
 
 12 = 2^2  3^0
 
 12 = 2^2  3^1
 
 
 **what about Factorizing n^power**
 
 Simply if 	n   =  p1^a 	*	 p2^b 	*	 p3^c
 
 Then      	n^z = p1^az *	 p2^bz  *	 p3^cz

 Divisors of 	n   = (a+1) 	* (b+1) 	* (c+1)
 
 Divisors of 	n^z = (az+1) 	* (bz+1) 	* (cz+1)
 
 
