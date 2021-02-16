```cpp
// Better Solution
ll power(ll a, ll b, ll mod)
{
    ll ans = 1;
    a %= mod;

    while (b)
    {
        if (b & 1ll) ans = (ans * a) % mod;
        b >>= 1ll;
        a = (a * a) % mod;
    }

    return ans;
}
// O(log(y))
/*
Calc a^1 + a^2 + a^3 + ..... + a^k
(a^1+a^2+a^3+a^4+a^5+a^6)  =  (a^1+a^2+a^3)+a^3*(a^1+a^2+a^3) = (a^1+a^2+a^3)*(1+a^3)
what about odd n (a^1+a^2+a^3+a^4+a^5+a^6+a^7) = a(1+(a^1+a^2+a^3+a^4+a^5+a^6))
*/
ll sumPower(ll a, int k)
{
    if (!k) return 0;
    if (k&1) return a * (1 + sumPower(a, k - 1));
    return sumPower(a, k>>1) * (1 + power(a,k>>1));
}
// Time Complexity : O(log(k)) 
```
