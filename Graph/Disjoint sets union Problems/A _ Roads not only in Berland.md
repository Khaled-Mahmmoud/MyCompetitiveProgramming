# Roads not only in Berland

```cpp
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1009;
int p[N];
int find(int u)
{
    if(p[u]==u)
        return u;
    return p[u] = find(p[u]);
}
int main()
{
    ios::sync_with_stdio(false);
    vector<pair<int,int>>ans1,ans2;
    int n,a,b;cin>>n;int cnt = n;
    for(int i=1;i<=n;i++)p[i] = i;
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        a = find(u);
        b = find(v);
        if(a==b)
        ans1.push_back({u,v});
        else
            p[a] = b;
    }
    for(int i=2;i<=n;i++)
    {
        a = find(1);
        b = find(i);
        if(a!=b)
        {
            ans2.push_back({a,b});
            p[a] = b;
        }
    }
    cout<<ans1.size()<<'\n';
    for(int i=0;i<ans1.size();i++)
        cout<<ans1[i].first<<' '<<ans1[i].second<<' '<<ans2[i].first<<' '<<ans2[i].second<<'\n';
    return 0;
}
```
