# Divisibility

```cpp
# Divisibility 

[Problem Link](https://vjudge.net/problem/UVA-10036)

```cpp
int dp[10009][109];
int n,k;
int a[10009];
int fix(int x)
{
	return (x % k + k) % k;
}
bool solve(int i, int mod)
{
	int &ret = dp[i][mod];
	if (~ret)
		return ret;
	if (i == n)
		return ret = (mod == 0);

	if (solve(i + 1, fix(mod + a[i])) || solve(i + 1, fix(mod - a[i])))
		return ret = 1;
	return ret = 0;
}
int main()
{
    int t;cin>>t;while(t--)
    {
        cin>>n>>k;
        for(int i=0;i<n;i++)
            cin>>a[i];
        memset(dp,-1,sizeof dp);
        if(solve(1,fix(a[0])))
            cout<<"Divisible";
        else
            cout<<"Not divisible";
        cout<<'\n';
    }
    return 0;
}
```
Complexity : O(nk)
