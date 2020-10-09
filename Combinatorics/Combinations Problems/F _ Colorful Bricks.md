# Colorful Bricks

[Problem Link](https://codeforces.com/contest/1081/problem/C)

```cpp
#include <bits/stdc++.h>
#define ll unsigned long long
#define mod 998244353
using namespace std;
ll fact[2003],inv[2003];
ll power(ll x,ll y)
{
    x %= mod;
    ll ans = 1;
    while(y)
    {
        if(y&1)
            ans = (ans*x)%mod;
        y>>=1;
        x = (x*x)%mod;
    }
    return ans;
}
void init()
{
    fact[0] = inv[0] = 1;
    for(int i=1;i<2003;i++)
    {
        fact[i] = (i*fact[i-1])%mod;
        inv[i] = power(fact[i],mod-2);
    }
}
ll ncr(ll n,ll r)
{
    if(r>n)
        return 0;
    return ((fact[n]*inv[n-r])%mod * inv[r])%mod;
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    init();
    int n,m,k;
    cin>>n>>m>>k;
    ll ans = ncr(n-1,k);
    ans = (ans * m)%mod;
    ans = (ans*power(m-1,k))%mod;
    cout<<ans;
    return 0;
}

```
