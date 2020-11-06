# Again Palindrome


[Problem Link](https://vjudge.net/problem/UVA-10617)

```cpp
#include<bits/stdc++.h>
#define ll long long
using namespace std;
string str; // abca = {a,b,c,a,aa,aba,aca}
ll dp[69][69];
ll solve(int i,int j)
{
    if(i==j)
        return 1;
    if(i+1==j)
        return 2 + (str[i]==str[j]);

    ll &rt = dp[i][j];
    if(~rt)
        return rt;

    rt = 0;
    if(str[i]==str[j])
       rt += solve(i+1,j-1) + 1;  // {aba,aca,aa}

        rt += solve(i+1, j);   // bca = {b,c,a}
	rt += solve(i, j-1);   // abc = {a,b,c}
	rt -= solve(i+1, j-1); // bc  = {b,c}

	return rt;
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int t;cin>>t;while(t--)
    {
        cin>>str;memset(dp,-1,sizeof dp);
        cout<<solve(0,str.size()-1)<<'\n';
    }
    return 0;
}
```
