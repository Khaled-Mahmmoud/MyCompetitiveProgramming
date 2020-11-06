# Journey

[Problem Link](https://codeforces.com/problemset/problem/839/C)

**Solution**

Let the cities be vertices and roads be edges of a tree and vertex 1 be the root of the tree.

Let ans[i] be the answer for the i-th vertex (the expected value if they start their journey from that vertex and the horse doesn't go to it's parent). Now we can calculate ans[i] by knowing the answer for it’s children. Let v1, v2, …., vk be the children of i-th vertex , then 

`ans[i] = (ans[v1]+ans[v2]+ans[v3]+.....+ans[vk])/k` but if i is leave then ans[i] = distance between root and i.


So if we know the answer of some vertex’s children, we can calculate its expected value and we can do it by a simple DFS.



```cpp
#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<vector<int>>adj;
double solve(int u,int len,int par)
{
    int k = adj[u].size();
    if(u!=1)k--;
    if(!k)return len;
    double p = 1.0/k,ans = 0;
    for(auto v:adj[u])
        if(v!=par)
        ans += solve(v,len+1,u) * p;
    return ans;
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
