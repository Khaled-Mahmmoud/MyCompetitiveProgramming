# Distance in Tree

[Problem Link](https://codeforces.com/contest/161/problem/D)

```cpp
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 50005;
const int K = 505;
int dp[N][K];
int n , k;
ll ans;
vector<int> adj[N];
void dfs(int u = 1 , int par = -1)
{
    for(int v : adj[u])
        if(v != par)
        {
            dfs(v , u);
            for(int i = 1 ; i < k ; i++)
            {
                ans += 1LL * dp[u][i] * dp[v][k-i-1];
                dp[u][i] += dp[v][i-1];
            }
            dp[u][k] += dp[v][k-1];
        }
}
int main()
{
    cin>>n>>k;
    for(int i = 1 ; i < n ; i++)
    {
        int a , b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i = 1 ; i <= n ; i++)dp[i][0] = 1;
    dfs();
    for(int i = 1 ; i <= n ; i++)ans += dp[i][k];
    
    cout << ans;
    return 0;
}
```

resolve it using [Centroid Decomposition](https://codeforces.com/blog/entry/52492)
