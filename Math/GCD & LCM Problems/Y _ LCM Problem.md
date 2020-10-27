# LCM Problem

[Problem Link](https://codeforces.com/problemset/problem/1389/A)

```cpp
void solve()
{
	int l, r;
	cin >> l >> r;
	if (2 * l <= r)
		cout << l << ' ' << l * 2 << endl;
	else
		cout << -1 << ' ' << -1 << endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
```
