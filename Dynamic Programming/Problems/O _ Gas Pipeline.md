# Gas Pipeline

[Problem Link](https://codeforces.com/contest/1207/problem/C)

```cpp
#define ll long long
int n,a,b;string str;
ll dp[200009][2];
ll solve(int idx,bool cur)
{
    ll &rt = dp[idx][cur];
    if(idx == n)
    {
        if(cur == 1)
            return 1e18;
        return b;
    }
    if (str[idx] == '1' && cur == 0)
        return 1e18;
    if(~rt)
        return rt;
    rt = 1e18;
    if (str[idx] == '0')
    {
	rt = min(rt, a + solve(idx + 1, cur));
	rt = min(rt, 2 * a + solve(idx + 1, !cur));
    }
    else
	rt = min(rt, a + solve(idx + 1, cur));
	return rt += (1 + cur) * b;

}
int main()
{
    int t;cin>>t;while(t--)
    {
        cin>>n>>a>>b;
        cin>>str;
        memset(dp,-1,sizeof dp);
        cout<<solve(0,0)<<'\n';
    }
    return 0;
}
```
