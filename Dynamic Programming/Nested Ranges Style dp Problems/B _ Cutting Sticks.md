
# Cutting Sticks

[Problem Link](https://vjudge.net/problem/UVA-10003)

```
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[59],dp[59][59];
int cut(int s,int e,int is,int ie)
{
    if(s==e||is>ie)
        return 0;
    int &rt = dp[is][ie];
    if(~rt)return rt;
    rt = 1e9;
    for(int i=is;i<=ie;i++)
    {
        int c = a[i];
        rt = min(rt,cut(s,c,is,i-1)+cut(c+1,e,i+1,ie)+(e-s+1));
    }
    return rt;
}
int main()
{
    int i,l,n;
    while(cin>>l&&l)
    {
        memset(dp,-1,sizeof dp);
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        cout<<"The minimum cutting is "<<cut(1,l,1,n)<<".\n";
    }
}
```
Time Complexity : O(n^3)

