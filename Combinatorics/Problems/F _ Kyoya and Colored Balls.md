# Kyoya and Colored Balls

[Problem Link](https://codeforces.com/contest/553/problem/A)

```cpp
#define mod 1000000007
#define N 1009
#define ll unsigned long long
ll fact[N],inv[N],a[N],ans = 1;
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
ll nCr(ll n,ll r)
{
    if(r>n)
       return 0;
    return ((fact[n]*inv[r])%mod * inv[n-r])%mod;
}
int main()
{
    init();
    int n;
    cin >> n;
    for(int i =1;i<=n;i++)
        cin >> a[i],a[i] += a[i-1];
    for(int i = 1;i<=n;i++)
        ans=(ans*nCr(a[i]-1,a[i]-a[i-1]-1))%mod;
    cout << ans;
    return 0;
}
```
