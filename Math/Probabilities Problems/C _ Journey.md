# Journey

[Problem Link](https://codeforces.com/problemset/problem/839/C)

[Tutorial Link](https://codeforces.com/blog/entry/53815)

```cpp
#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<vector<int>>adj;
double solve(int u,int len,int par)
{
    int sum = adj[u].size();
    if(u!=1)sum--;
    if(!sum)return len;
    double p = 1.0/sum,x = 0;
    for(auto v:adj[u])
        if(v!=par)
        x += solve(v,len+1,u) * p;
    return x;
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    int n;cin>>n;adj.resize(n+1);
    while(--n)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout<<fixed<<setprecision(9);
    cout<<solve(1,0,0);
    return 0;
}
```
