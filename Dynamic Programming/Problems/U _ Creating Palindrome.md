# Creating Palindrome

[Problem link](https://vjudge.net/problem/UVA-11753)

```cpp
int n,k,a[10009],dp[10009][29][29];
int solve(int i,int k1,int k2)
{
	int j=(n-1)-i-k1+k2;
	if(i>=j)return 0;
	if(~dp[i][k1][k2])
        return dp[i][k1][k2];
	if(k1+k2>k)
		return 30;
	if(a[i]==a[j])
	    return dp[i][k1][k2]=solve(i+1,k1,k2);
	return dp[i][k1][k2]=1+min(solve(i+1,k1,k2+1),solve(i,k1+1,k2));
}
int main()
{
    int t;cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n>>k;
        for(int j=0;j<n;j++)
            cin>>a[j];
        memset(dp,-1,sizeof dp);
        int ans = solve(0,0,0);
        cout<<"Case "<<i<<": ";
        if(!ans)
            cout<<"Too easy";
        else if(ans>k)
            cout<<"Too difficult";
        else
            cout<<ans;
        cout<<'\n';
    }
    return 0;
}
```
