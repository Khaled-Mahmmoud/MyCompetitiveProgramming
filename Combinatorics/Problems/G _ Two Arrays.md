# Two Arrays

Let's consider the following sequence:

A1, A2, ..., Am, Bm, Bm−1, ....., b1.

It's sequence of length 2m sorted in non-descending order, where each element of each sequence is an integer between 1 and n.

We can find the number of such sequences by simple combinatorics — it's combination with repetitions. So the answer is (n+2m−1,2m)=(n+2m−1)!/(2m)!(n−1)!.

[Problem Link](https://codeforces.com/contest/1288/problem/C)

```cpp
#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;
#define mod 1000000007
#define N 1099
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
ll nck(ll n,ll k)
{
    if(k>n)
       return 0;
    return ((fact[n]*inv[k])%mod * inv[n-k])%mod;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,m;init();
    cin>>n>>m;
    cout<<nck(n+2*m-1, 2*m);
    return 0;
}
```
