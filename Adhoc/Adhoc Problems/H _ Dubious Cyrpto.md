# Dubious Cyrpto

[Problem Link](https://codeforces.com/contest/1379/problem/B)

```cpp
#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve()
{
	int l, r;
	ll m;
	cin >> l >> r >> m;
	for (int a = l; a <= r; a++)
    {
		ll ans = (r - l + m) / a;
		ll dif = m - 1LL * ans * a;
		if (ans > 0)
		{
			if (l - r <= dif && dif <= r - l)
			{
				if (dif <= 0)
					cout << a << ' ' << l << ' ' << l - dif << endl;
				else
					cout << a << ' ' << r << ' ' << r - dif << endl;
				return;
			}
		}
	}
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    int T;
   	cin >> T;
	  while (T--)
    {
		   solve();
	  }
    return 0;
}
```
