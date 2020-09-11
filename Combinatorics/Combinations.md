# Combinations

Program to calculate value of nCk.
    
Given two numbers n and k, find value of nCk.

Input :  n = 5, r = 2
Output : 30
The value of 5C2 is 10

Input : n = 3, r = 1
Output : 3

The idea is simply based on formula`nCr = (n!) / ((n-k)! * k!)`

```cpp
int fact(int n) 
{ 
    int res = 1; 
    for (int i = 2; i <= n; i++) 
        res = res * i; 
    return res; 
} 
int nCr(int n, int r) 
{ 
    return fact(n) / (fact(r) * fact(n - r)); 
} 
```

# binomial coefficient

A binomial coefficient C(n, k) also gives the number of ways, disregarding order
that k objects can be chosen from among n objects; more formally,
the number of k-element subsets (or k-combinations) of an n-element set

The Problem : Write a function that takes two parameters n and k and returns the value of Binomial Coefficient C(n, k)
    
For example, your function should return 6 for n = 4 and k = 2, and it should return 10 for n = 5 and k = 2.

**Optimal Substructure**

The value of C(n, k) can be recursively calculated using following standard formula for Binomial Coefficients.

```
   C(n, k) = C(n-1, k-1) + C(n-1, k)
   C(n, 0) = C(n, n) = 1
```
```CPP
int binomialCoeff(int n, int k)  
{  
    if (k == 0 || k == n)  
        return 1;  
    return binomialCoeff(n - 1, k - 1) + binomialCoeff(n - 1, k);  
}  
```
**Overlapping Subproblems**

It should be noted that the above function computes the same subproblems again and again.
    
See the following recursion tree for n = 5 an k = 2. The function C(3, 1) is called two times.
    
For large values of n, there will be many common subproblems.
```
                             C(5, 2)
                    /                      \
           C(4, 1)                           C(4, 2)
            /   \                          /           \
       C(3, 0)   C(3, 1)             C(3, 1)               C(3, 2)
                /    \               /     \               /     \
         C(2, 0)    C(2, 1)      C(2, 0) C(2, 1)          C(2, 1)  C(2, 2)
                   /        \              /   \            /    \
               C(1, 0)  C(1, 1)      C(1, 0)  C(1, 1)   C(1, 0)  C(1, 1)
```
Since same suproblems are called again, this problem has Overlapping Subproblems property.
So the Binomial Coefficient problem solve with use of a dynamic programming.
Like other typical Dynamic Programming(DP) problems, re-computations of same subproblems can be avoided by 
constructing a temporary array C[][] in bottom up manner. Following is Dynamic Programming based implementation.
```cpp
int binomialCoeff(int n, int k) 
{ 
    int C[n + 1][k + 1]; 
    int i, j;
    for (i = 0; i <= n; i++) 
    { 
        for (j = 0; j <= min(i, k); j++) 
        { 
            if (j == 0 || j == i) 
                C[i][j] = 1; 
            else
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j])%MOD; 
        } 
    } 
  
    return C[n][k]; 
} 
```
Time Complexity: O(n * k)

Auxiliary Space: O(n * k)

### Another Solution

Note that C(n, k) = C(n, n - k).

So call the function with nCk(n, min(k, n-k)) for better performance.
 
```cpp 
int nCr(int n, int k) 
{
    if (n < k)
        return 0;

    if (k == 0)
        return 1;

    return n * nCr(n - 1, r - 1) / k;
}
```
Complexity: O(k)

### Combinations nCk % m for Large Numbers where m is prime

```cpp
#define mod 1000000007
#define N 1009
#define ll unsigned long long  // notice it should be unsigned long long, there wrong answer with long long
ll fact[N],inv[N];
ll power(ll x,ll y)
{
    x = x % mod;
    ll ans = 1;
    while(y)
    {
        if(y&1)
            ans = (ans * x)%mod;
        x = (x * x)%mod;
        y>>=1;
    }
    return ans;
}
void init()
{
    fact[0] = inv[0] = 1;
    for(int i=1;i<N;i++)
    {
        fact[i] = (i * fact[i-1])%mod;
        inv[i] = power(fact[i],mod-2); // notice it should be fact[i], there was wrong answer with i
    }
}
ll nCk(ll n,ll k)
{
    if(k>n)
       return 0;
    return ((fact[n]*inv[k])%mod * inv[n-k])%mod;
}
int main()
{
    init();
    int t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>r;
        cout<<nCk(n,k)<<'\n';
    }
    return 0;
}
```
Time complexity : O(nlog(mod))
