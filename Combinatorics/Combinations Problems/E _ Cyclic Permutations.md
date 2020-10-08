# Cyclic Permutations

**Solution** : n! - 2^(n-1)

We only need to involve the cases where there is at least one number which is surrounded by larger number on both sides. e.g. 4,2,5 or 2,1,3. So all those cases need to be removed where we don't have any number like that. That is possible if we fix the largest number and then choose some numbers and put it in its left in ascending order and put others in its right in descending order. That is, lets say we have 1,2,3,4,5,6. We will fix 6. Now we will choose some numbers, say 2 and 5 and make permutation like this: 2,5, 6,4,3,1. That way we can't have any number surrounded by larger number on both sides. In this case we chose two numbers 2 and 5 but we could choose any, even 0. which would result into 6,5,4,3,2,1 So we choose any number of numbers from these 5 numbers. In general, C(n-1, 0) + C(n-1, 1) + C(n-1, 2) +...+ C(n-1, n-1) = 2^(n-1).

```cpp
#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
using ll = long long;
ll fact(int n)
{
	ll ret = 1;
	for (int i = 1; i <= n; i++)
		(ret *= i)%=mod;
	return ret;
}
ll power(ll a, ll b)
{
	ll ret = 1;
	a %= mod;
	while (b)
    {
		if (b & 1)
			(ret *= a)%=mod;
		(a *= a)%=mod;
		b >>= 1;
	}
	return ret;
}
int main()
{
    int n;
	cin >> n;
	cout << (fact(n)-power(2,n-1)+mod)%mod;
    return 0;
}


```
