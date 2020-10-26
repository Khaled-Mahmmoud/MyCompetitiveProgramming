# Beaver

[Problem Link](https://codeforces.com/contest/79/problem/C)

**Solution**

We can regard a substring that is equal to one of boring strings as an interval. The number of such intervals are at most |s|· n, and the required time to determine
whether each of them is a boring string is |bi|, so all intervals can be calculated in O(|s|· n· |bi|) runtime, by naive way. (Yes, no special string algorithm is 
required here.). The original problem can be rewritten as follows: you are given at most 10^6 intervals on [0, 10^5], determine the longest interval that does not contain any given interval.

```cpp
#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<int>getprefix(string pat)
{
    int m=pat.size();
    vector<int>prefix(m);
    for(int i=1,len=0; i<m; i++)
    {
        while(len>0&&pat[i]!=pat[len])
            len=prefix[len-1];
        if(pat[i]==pat[len])
            prefix[i]=++len;
        else
            prefix[i]=len;
    }
    return prefix;
}
bool pred(const pair<int,int>&a,const pair<int,int>&b)
{
    if(a.first!=b.first)
        return a.first < b.first;
    else
        return a.second > a.second;
}
int main()
{
    string str,pat;
    cin>>str;
    int t;
    cin>>t;
    vector<pair<int,int>>v;
    while(t--)
    {
        cin>>pat;
        int n=str.size(),m=pat.size();
        vector<int>prefix=getprefix(pat);
        for(int i=0,len=0; i<n; i++)
        {
            while(len>0&&str[i]!=pat[len])
                len=prefix[len-1];
            if(str[i]==pat[len])
                len++;
            if(len==m)
            {
                v.push_back({i-m+1,i-m+1+pat.size()-1});
                len=prefix[len-1];
            }
        }
    }
    v.push_back({-1,1e9});
    sort(v.begin(),v.end(),pred);
    vector<int>dp(v.size());
    dp.push_back(str.size());
    int mx = 0, indx = 0;
	for (int i = v.size() - 1; i >= 0; i--)
    {
		dp[i] = min(dp[i + 1], v[i].second);
		int ans = dp[i + 1] - v[i].first - 1;
		if (ans > mx)
		{
			mx = ans;
			indx = v[i].first + 1;
		}
	}
	cout<<mx<<" "<<indx;
    return 0;
}
```
