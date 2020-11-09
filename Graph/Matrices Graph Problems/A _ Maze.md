# Maze

[Problem Link](https://codeforces.com/contest/377/problem/A)

[Tutorial Link](https://codeforces.com/blog/entry/10157)

```cpp
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
vector< string > adj(1000);
int n,m,k;
bool visit[1010][1000]={false};
void dfs(int i , int j)
{
     if(i>=n || i<0 || j>=m || j<0 || adj[i][j] == '#' || visit[i][j])
        return;
     visit[i][j]=true;
     for(int i=0;i<4;i++)
     dfs(i+dx[i],j+dy[i]);
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
