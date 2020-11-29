### Combination nCr

Program to calculate value of nCr.
    
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

#### Binomial Coefficient

The Problem : Write a function that takes two parameters n and r and returns the value of Binomial Coefficient C(n, r)
    
**Pascal Triangle**
```
1  
1 1 
1 2 1 
1 3 3 1 
1 4 6 4 1 
1 5 10 10 5 1 
```
**Optimal Substructure**

The value of C(n, r) can be recursively calculated using pascal triangle.

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

```cpp
int binomialCoeff(int n, int r) 
{
    if(r>n)return 0;
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
    if (r>n)
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
        cout<<nCr(n,r)<<'\n';
    }
    return 0;
}
```
Time complexity : O(nlog(mod))

### Some Rules of Binomial coefficients

```nC0 + nC1 + nC2 + ……. + nCn-1 + nCn = 2^n```

Proof : We know, (1 + x)^n = nC0 x^0 + nC1 x^1 + nC2 x^2 + ..... + nCn x^n. we put x = 1

(1 + 1)^n = nC0 + nC1 + nC2 + ..... + nCn

2^n = nC0 + nC1 + nC2 + ..... + nCn

```nC0^2 + nC1^2 + nC2^2 + .... + nCn-1^2 + nCn^2 = 2nCn```

Proof : We know, (1 + x)^n = nC0 x^0 + nC1 x^1 + nC2 x^2 + ......... + nCn-1 x^n-1 + nCn x^n

Also, (x + 1)^n = nC0 x^n + nC1 x^n-1 + nC2 x^n-2 + ......... + nCn-1 x + nCn

Multiplying above two equations, (1 + x)^2n =

[nC0 + nC1 x + nC2 x^2 + ......... + nCn-1 x^n-1 + nCn x^n] X

[nC0 x^n + nC1 x^n-1 + nC2 x^n-2 + ......... + nCn-1 x + nCn]

Equating coefficients of x^n on both sides, we get 2nCn = nC0^2 + nC1^2 + nC2^2 + nC3^2 + ......... + nCn-2^2 + nCn-1^2 + nCn^2

Hence, sum of the squares of coefficients = 2nCn = (2n)!/(n! * (2n-n)!)

```nC0 + nC2 + nC4 + nC6 + nC8 + ……… = 2^(n-1)```

Proof : We know, (1 + x)^n = nC0 x^0 + nC1 x^1 + nC2 x^2 + ..... + nCn x^n

Now put x = -x, we get (1 - x)^n = nC0 x^0 - nC1 x^1 + nC2 x2 + ..... + (-1)^n nCn x^n

Now, adding both the above equation, we get, (1 + x)^n + (1 - x)^n = 2 * [nC0 + nC2 x2 + nC4 x4 + .....]

Put x = 1

(1 + 1)^n + (1 - 1)^n = 2 * [nC0 + nC2 + nC4 + .......]

2^n / 2 = nC0 + nC2 + nC4 + nC6 + .......

2^(n-1) = nC0 + nC2 + nC4 + nC6 +.......

2^n = nC0 + nC1 + nC2 + nC3 + ...... + nCn
