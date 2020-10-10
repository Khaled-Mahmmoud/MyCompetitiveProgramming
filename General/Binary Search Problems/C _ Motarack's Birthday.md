# Motarack's Birthday

[Problem Link](https://codeforces.com/contest/1301/problem/B)

```cpp
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n, a[100005], tmp[100005];
int solve(int x)
{
	int mx = 0;
	for (int i = 0; i < n; i++)
	{
		tmp[i] = (~a[i] ? a[i] : x);
		if (i) mx = max(mx, abs(tmp[i] - tmp[i-1]));
	}
	return mx;
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    int t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		int low = 0, high = 1e9, mid1, mid2;
		int mx1 = 0, mx2 = 0, ans = INT_MAX, k = 0;
		while (low <= high)
		{
			mid1 = low + (high - low) / 3;
			mid2 = high - (high - low) / 3;
			mx1 = solve(mid1);
			mx2 = solve(mid2);
			if (mx1 < mx2)
				high = mid2 - 1, ans = mx1, k = mid1;
			else
				low = mid1 + 1, ans = mx2, k = mid2;
		}
		cout << ans << ' ' << k << '\n';
	}
    return 0;
}
```
