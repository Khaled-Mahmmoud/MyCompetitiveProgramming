# Combinations

Program to calculate value of nCr.
    
Given two numbers n and r, find value of nCr.

Input :  n = 5, r = 2

Output : 30

The value of 5C2 is 10

Input : n = 3, r = 1

Output : 3

The idea is simply based on formula`nCr = (n!) / ((n-r)! * r!)`

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

A binomial coefficient C(n, r) also gives the number of ways, disregarding order
that r objects can be chosen from among n objects; more formally,
the number of r-element subsets (or r-combinations) of an n-element set.

The Problem : Write a function that takes two parameters n and r and returns the value of Binomial Coefficient C(n, r)
    
For example, your function should return 6 for n = 4 and r = 2, and it should return 10 for n = 5 and r = 2.

**Optimal Substructure**

The value of C(n, r) can be recursively calculated using following standard formula for Binomial Coefficients.

```
   C(n, r) = C(n-1, r-1) + C(n-1, r)
   C(n, 0) = C(n, n) = 1
```
```CPP
int binomialCoeff(int n, int r)  
{  
    if (r == 0 || r == n)  
        return 1;  
    return binomialCoeff(n - 1, r - 1) + binomialCoeff(n - 1, r);  
}  
```
**Overlapping Subproblems**

It should be noted that the above function computes the same subproblems again and again.
    
See the following recursion tree for n = 5 an r = 2. The function C(3, 1) is called two times.
    
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
int binomialCoeff(int n, int r) 
{ 
    int C[n + 1][r + 1]; 
    int i, j;
    for (i = 0; i <= n; i++) 
    { 
        for (j = 0; j <= min(i, r); j++) 
        { 
            if (j == 0 || j == i) 
                C[i][j] = 1; 
            else
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j])%MOD; 
        } 
    } 
  
    return C[n][r]; 
} 
```
Time Complexity: O(n * r)

Auxiliary Space: O(n * r)

### Another Solution

Note that C(n, r) = C(n, n - r).

So call the function with nCr(n, min(r, n-r)) for better performance.
 
```cpp 
int nCr(int n, int r) 
{
    if (n < r)
        return 0;

    if (r == 0)
        return 1;

    return n * nCr(n - 1, r - 1) / r;
}
```
Complexity: O(r)

### Combinations nCr % m for Large Numbers where m is prime

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
ll nCr(ll n,ll r)
{
    if(r>n)
       return 0;
    return ((fact[n]*inv[r])%mod * inv[n-r])%mod;
}
int main()
{
    init();
    int t;
    cin>>t;
    while(t--)
    {
        ll n,r;
        cin>>n>>r;
        cout<<nCk(n,r)<<'\n';
    }
    return 0;
}
```
Time complexity : O(nlog(mod))
