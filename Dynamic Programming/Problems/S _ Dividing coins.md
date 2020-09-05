# Dividing coins

Given a bag with a maximum of 100 coins, determine the most fair division between two persons.
This means that the difference between the amount each person obtains should be minimised. The
value of a coin varies from 1 cent to 500 cents. It’s not allowed to split a single coin.

Input :
A line with the number of problems n, followed by n times:
• a line with a non negative integer m (m ≤ 100) indicating the number of coins in the bag
• a line with m numbers separated by one space, each number indicates the value of a coin.

Output :
The output consists of n lines. Each line contains the minimal positive difference between the amount
the two persons obtain when they divide the coins from the corresponding bag.

Input

2

3

2 3 5

4

1 2 4 6

Output

0

1

```cpp
#include<bits/stdc++.h>
using namespace std;
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
    ios::sync_with_stdio(false);
    cin.tie(0);
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
