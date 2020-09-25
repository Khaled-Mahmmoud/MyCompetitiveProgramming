# Pokemon Army

[Problem Link](https://codeforces.com/contest/1420/problem/C1)

```cpp
#define ll long long
ll dp[300005][2];
int n;int a[300005];
ll solve(int idx,int c)
{
    if(idx==n)
        return 0;
    ll &rt = dp[idx][c];
    if(~rt)
        return rt;
        int x;
    return rt = max(solve(idx+1,c),max(0ll,solve(idx+1,1-c)+a[idx]*(c?-1:1)));
}
int main()
{
    int t;cin>>t;while(t--)
    {
        int q;
        cin>>n>>q;
        for(int i=0;i<n;i++)
            cin>>a[i],dp[i][0]=dp[i][1]=-1;
        cout<<solve(0,0)<<'\n';;
    }
    return 0;
}
```
