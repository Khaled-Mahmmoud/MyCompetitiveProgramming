
# Minimax Problem

[Problem Link](https://codeforces.com/contest/1288/problem/D)

```cpp
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,a[300005][10];
pair<int,int>check(int x)
{
	int dp[1<<m];
	memset(dp,-1,sizeof dp);
	for(int i=0;i<n;i++)
	{
		int y = 0;
		for(int j=0;j<m;j++)
			if(a[i][j]>=x)
				y |=(1<<j);
		dp[y] = i;
	}
	for(int i=0;i<(1<<m);i++)
		if(~dp[i])
			for(int j=0;j<(1<<m);j++)
				if(~dp[j]&&((i|j)==(1<<m)-1))
					return {dp[i] + 1 , dp[j] + 1};
	return {-1 , -1};
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> n >> m;
	for(int i = 0;i < n;i++)
		for(int j = 0;j < m;j++)
			cin >> a[i][j];
    pair<int,int> ans,x;
    int low=0,high = 1e9,mid;
	while(low<=high)
	{
		mid = (low+high)/2;
        x = check(mid);
		if(~x.first)
			ans = x , low = mid + 1;
		else
			high = mid - 1;
	}
	cout<<ans.first<<" "<<ans.second;
    return 0;
}

```
