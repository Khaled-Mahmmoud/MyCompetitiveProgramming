# Dividing coins

[Problem Link](https://vjudge.net/problem/UVA-562)

```cpp
int n;
int a[105];
int total;
int dp[105][50005];
int solve(int idx, int sum)
 {
	if (idx == n)
        return abs(sum - (total - sum));
	int &ret = dp[idx][sum];
	if (ret != -1)
	   return ret;
	ret = min(solve(idx + 1, sum), solve(idx + 1, sum + a[idx]));
	return ret;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
	  total = 0;
	  memset(dp, -1, sizeof dp);
	  cin >> n;
	  for (int i = 0; i < n; i++)
          {
		cin >> a[i];
		total += a[i];
	  }
	  cout << solve(0, 0) << endl;
    }
    return 0;
}
```
