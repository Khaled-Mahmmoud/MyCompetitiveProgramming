```cpp
/*
Pascal Triangle
1  
1 1 
1 2 1 
1 3 3 1 
1 4 6 4 1 
1 5 10 10 5 1 
The value of C(n, r) can be recursively calculated using pascal triangle.
C(n, r) = C(n-1, r-1) + C(n-1, r)
C(n, 0) = C(n, n) = 1
*/
int binomial_coeff(int n, int r) 
{
    if(r>n)
        return 0;
    int C[n + 1][r + 1]; 
    int i, j;
    for (i = 0; i <= n; i++) 
    { 
        for (j = 0; j <= min(i, r); j++) 
        { 
            if (j == 0 || j == i) 
                C[i][j] = 1; 
            else
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j]; 
        } 
    } 
    return C[n][r]; 
} 
// Time complexity : O(n * r)


// Combinations nCr % m for Large Numbers where m is prime
#define mod 1000000007
#define N 1009
#define ll unsigned long long  
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
        inv[i] = power(fact[i],mod-2); 
    }
}
ll ncr(ll n,ll r)
{
    if(r>n)
       return 0;
    return ((fact[n]*inv[r])%mod * inv[n-r])%mod;
}
void solve()
{
    init();
    ll n,r;
    cin>>n>>r;
    cout<<ncr(n,r)<<'\n';
}
// Time complexity : O(nlog(mod))
```
