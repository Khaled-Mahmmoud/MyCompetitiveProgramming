
```cpp
ll prefix_sum_2d(vector<int>v,int l,int r)
{
    int n = v.size();
    vector<ll>pr(n+1);

    for(int i=1;i<=n;i++)
        pr[i] = pr[i-1]+v[i-1];

    return pr[r]-pr[l-1];
}
ll prefix_sum_3d(vector<vector<int>>v,int r1,int c1,int r2,int c2)
{
    int n = v.size(),m = v[0].size();
    vector<vector<int>>pr(n+1,vector<int>(m+1));

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            pr[i][j] = v[i-1][j-1] + pr[i][j-1] + pr[i-1][j] - pr[i-1][j-1];

    return pr[r2][c2]-pr[r2][c1-1]-pr[r1-1][c2]+pr[r1-1][c1-1];
}
```
