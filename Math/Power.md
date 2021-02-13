```cpp
// 10^8 = (10^2)^4 = (10^4)^2
// 10^9 = 10 * 10^8
int power(int x, unsigned int y) 
{ 
    if (y == 0) 
        return 1; 
    else if (y % 2 == 0) 
        return power(x, y / 2) * power(x, y / 2); 
    else
        return x * power(x, y / 2) * power(x, y / 2); 
} 
// O(4^log y)
    
// Above function can be optimized to O(log y) by calculating power(x, y/2) only once and storing it
int power(int x, unsigned int y) 
{ 
    int temp; 
    if( y == 0) 
        return 1; 
    temp = power(x, y/2); 
    if (y & 1) 
        return x*temp*temp;
    else
        return temp*temp;
} 
// O(log y)
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
