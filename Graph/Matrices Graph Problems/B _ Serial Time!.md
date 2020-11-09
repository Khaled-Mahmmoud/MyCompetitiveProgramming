

```cpp
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int k,r,c;
bool vis[10][10][10];
char g[10][10][11];
int res = 0;
int dx[6] = {-1, 0, 0, 0, 0, 1 };
int dy[6] = { 0, 1, 0,-1, 0, 0 };
int dz[6] = { 0, 0, 1, 0,-1, 0 };
void dfs(int x, int y, int z)
{
    if(x<0||x==k||y<0||y==r||z<0||z==c||vis[x][y][z]||g[x][y][z]!='.')
        return;
    ++res;
    vis[x][y][z] = true;
    for (int i=0;i<6;i++)
        dfs(x+dx[i],y+dy[i],z+dz[i]);
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>k>>r>>c;
    for(int i=0;i<k;i++)
        for(int j=0;j<r;j++)
           cin>>g[i][j];
    int x,y;cin>>x>>y;x--,y--;
    dfs(0,x,y);cout<<res;
    return 0;
}
```
