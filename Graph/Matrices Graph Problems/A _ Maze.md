# Maze

[Problem Link](https://codeforces.com/contest/377/problem/A)

Start BFS or DFS from any free cell. As the maze is connected, this search will visit all s free cells. But we can stop the search when it visits s - k free cells. It's obvious that these s - k cells are connected to each other. Remaining k cells can be transformed into the walls.

```cpp
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
vector<string> adj(1000);
int n,m,k;
bool visit[1010][1000]={false};
void dfs(int x, int y)
{
     if(x>=n||x<0||y>=m||y<0||adj[x][y]=='#'||visit[x][y])
        return;
     visit[x][y]=true;
     for(int i=0;i<4;i++)
     dfs(x+dx[i],y+dy[i]);
     if(k)
     {
         adj[x][y]='X';
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
