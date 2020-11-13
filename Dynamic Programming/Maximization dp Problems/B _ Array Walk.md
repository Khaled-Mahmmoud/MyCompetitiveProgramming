#  Array Walk

[Problem Link](https://codeforces.com/problemset/problem/1389/B)

```
#define N  200009
int n,arr[N],dp[N][6][2];
// where k is inferenced variable
int solve(int idx,int k,int z,bool flag)
{
    int &rt = dp[idx][z][flag];
    if(~rt)
       return rt;

    int ans1 = 0,ans2=0;

    if(idx>0&&flag&&z&&k)
        ans1 = solve(idx-1,k-1,z-1,false);

    if(idx<n-1&&k)
        ans2 = solve(idx+1,k-1,z,true);

   return rt = max(ans1,ans2) + arr[idx];

}
int main()
{
    int t;cin>>t;while(t--)
    {
        int k,z;
        cin>>n>>k>>z;
        for(int i=0;i<n;i++)
            cin>>arr[i];

        for(int i=0;i<n;i++)
            for(int j=0;j<=z;j++)
              dp[i][j][0] = -1,dp[i][j][1] = -1;

        cout<<solve(0,k,z,true)<<'\n';
    }
    return 0;
}
```
