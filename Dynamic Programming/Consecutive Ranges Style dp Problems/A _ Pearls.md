# Pearls 

[Problem Link](https://vjudge.net/problem/POJ-1260)

```cpp
#include<iostream>
#include<cstring>
#define ll long long
using namespace std;
const int MAX = 109;
int dp[MAX], cnt[MAX], pr[MAX];
int n;
int solve(int i=0)	// push parameter J to loop. O(NM) time, O(N) memory
{
	if(i == n)
		return 0;
	int &ret = dp[i];
	if(~ret)
        return ret;
	ret = 1e9;
	int sum = 0;
	for (int j = i; j < n; ++j) {	// what if i allowed only maximum subsegment to match 5?
		sum += cnt[j];              // it will for (int j = i; j < i+5; ++j)
		ret = min(ret, (sum+10)*pr[j] + solve(j+1) );
	}
	return ret;

}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int t;cin>>t;
	while(t--)
    {
		cin>>n;
        for(int i=0;i<n;i++)
            cin>>cnt[i]>>pr[i];
		memset(dp, -1, sizeof dp);
		cout<<solve()<<'\n';
	}
	return 0;
}
```
