# Fly

[Problem Link](https://codeforces.com/contest/1011/problem/C)

```cpp
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m;
    cin>>n>>m;
    int a[n],b[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
        cin>>b[i];
    double l = 1,r = 1e9+1,mid,ans = -1;
    while(abs(r-l)>1e-7)
    {
        mid = (l+r)/2;
        double q = m + mid;
        q -= q / a[0];
        for(int j = 1;j<n;j++)
            q-= q/b[j],q-=q/a[j];
        q-= q/b[0];
        if(q>=m)
            r = mid,ans = mid;
        else
            l = mid;
    }
    if(ans==-1)
        return cout<<-1,0;
    cout<<fixed<<setprecision(9)<<ans;
    return 0;
}
```
