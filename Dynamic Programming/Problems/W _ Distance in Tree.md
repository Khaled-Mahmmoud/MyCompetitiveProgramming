# Distance in Tree

[Problem Link](https://codeforces.com/contest/161/problem/D)

```cpp
const int N = 50005;
const int K = 505;
int dp[N][K];
int n , k;
long long ans;
vector<int> adj[N];
 
void dfs(int u = 1 , int par = -1)
{
    for(int nxt : adj[u])
        if(nxt != par)
        {
            dfs(nxt , u);
            for(int i = 1 ; i < k ; i++)
            {
                ans += 1LL * dp[u][i] * dp[nxt][k-i-1];
                dp[u][i] += dp[nxt][i-1];
            }
            dp[u][k] += dp[nxt][k-1];
        }
}
 
 
 
int main()
{
    scanf("%d%d",&n,&k);
    for(int i = 1 ; i < n ; i++){
        int a , b;
        scanf("%d%d",&a,&b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
 
    for(int i = 1 ; i <= n ; i++)dp[i][0] = 1;
    dfs();
    for(int i = 1 ; i <= n ; i++)ans += dp[i][k];
    cout << ans << endl;
 
    return 0;
}
```
