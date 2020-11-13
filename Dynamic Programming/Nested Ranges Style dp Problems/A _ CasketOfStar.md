# CasketOfStar 

[Problem Link](https://vjudge.net/problem/TopCoder-11781)

```
#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<int>weight;
int dp[109][109];
int solve(int i,int j)
{
    if(j-i+1<=2)
        return 0;
    if(j-i+1==3)
        return weight[i] * weight[j];
    int &rt = dp[i][j];
    if(~rt)
        return rt;
    rt = 0;
    for(int k=i+1;k<j;k++)
        rt = max(rt,solve(i,k)+solve(k,j)+weight[i]*weight[j]);
    return rt;
}
class CasketOfStar
{
public:
    int maxEnergy(vector<int>v)
    {
        weight = v;memset(dp,-1,sizeof dp);
        return solve(0,v.size()-1);
    }
};
```
Time Complexity : O(n^3)
