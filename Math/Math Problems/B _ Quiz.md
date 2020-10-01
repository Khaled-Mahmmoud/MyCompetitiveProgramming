# Quiz

[Problem Link](https://codeforces.com/contest/337/problem/C)

```cpp
#define ll long long
const int mod = 1e9+9;
ll power(ll x,ll y)
{
    ll ans = 1;
    x %= mod;
    while(y)
    {
        if(y&1)
            ans = (ans * x)%mod;
        y >>= 1;
        x = (x * x)%mod;
    }
    return ans;
}
int main()
{
  int n, m, k;
	cin >> n >> m >> k;
	int cnt = n / k;
	int wr = n - m;
	if (cnt <= wr)
		return cout<<m,0;
	ll tmp = wr * (k - 1);
	m -= tmp;
	cnt = m / k;
	ll ans = (k * (power(2, cnt+1) - 2 + mod)) % mod;
	ans += tmp + (m % k);
	ans %= mod;
	cout << ans;
    return 0;
}

```
