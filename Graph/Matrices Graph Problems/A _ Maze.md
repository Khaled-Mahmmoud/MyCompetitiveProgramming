# Maze

[Problem Link](https://codeforces.com/contest/377/problem/A)

[Tutorial Link](https://codeforces.com/blog/entry/10157)

```cpp
#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector< string > adj(1000);
int n,m,k;
bool visit[1010][1000]={false};
void dfs(int i , int j)
{
     if(i>=n || i<0 || j>=m || j<0 || adj[i][j] == '#' || visit[i][j])
        return;
     visit[i][j]=true;
     dfs(i+1 , j);
     dfs(i-1,j);
     dfs(i,j+1);
     dfs(i,j-1);
     if(k)
     {
         adj[i][j]='X';
         k--;
     }
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>m>>k;
   for(int i = 0 ; i<n ; i++)
       cin>> adj[i];
   for(int i = 0 ; i<n ; i++)
    for(int j = 0 ; j<m ; j++)
     dfs(i,j);
   for(int i = 0 ; i<n ; i++)
    cout<<adj[i]<<endl;
    return 0;
}
```
