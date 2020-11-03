# Exploring Pyramids

[Problem Link](https://vjudge.net/problem/UVA-1362)

```cpp
const int MOD = 1e9;
int dp[305][305];
string str;
int solve(int l, int r)
{
	if (l == r) return 1;
	if (str[l] != str[r]) return 0;
	int &ret = dp[l][r];
	if (~ret) return ret;
	ret = 0;
	for (int k = l + 2; k <= r; k++)
		if (str[l] == str[k])
			ret = (ret + ((1ll) * solve(l + 1, k - 1) * solve(k, r))%MOD) % MOD;
	return ret;
}
int main()
{
    while (cin >> str)
    {
	memset(dp, -1, sizeof dp);
	cout << solve(0, str.size() - 1) << endl;
    }
    return 0;
}

```
