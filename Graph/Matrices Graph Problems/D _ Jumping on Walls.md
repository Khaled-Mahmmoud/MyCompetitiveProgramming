# Jumping on Walls

[Problem Link](https://codeforces.com/contest/199/problem/D)

**Solution**

You should construct graph where vertices are areas of walls and edges are actions of ninja. Then you should run BFS with one modification: 
is you reach vertex later then water, you shouldn't do moves from this vertex.

It is solution in O(n).

```cpp
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
struct node
{
    int r,x,cnt;
    node(int a,int b,int c)
    {
        r=a;x=b;cnt=c;
    }
};
queue<node>q;
int n,k,vis[2][N];
char arr[2][N];
int bfs()
{
    node tmp(0,0,0);
    q.push(tmp);
    while(!q.empty())
    {
        tmp=q.front();q.pop();
        int r=tmp.r,x=tmp.x,cnt=tmp.cnt;
        if(x>n)
            return 1;
        if(vis[r][x])
            continue;
        if(cnt>x)
            continue;
        vis[r][x]=1;
        tmp.cnt=cnt+1;
        tmp.x=x-1;
        if(x-1>=0&&arr[r][x-1]!='X') q.push(tmp);
        tmp.x=x+1;
        if(arr[r][x+1]!='X') q.push(tmp);
        tmp.x=x+k;
        tmp.r=r^1;
        if(arr[tmp.r][tmp.x]!='X') q.push(tmp);
    }
    return 0;
}int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    cin>>n>>k;
    for(int i=0;i<2;i++)
        for(int j=0;j<n;j++)
            cin>>arr[i][j];
    if(bfs())
        cout<<"YES"<<endl;
    else
    cout<<"NO"<<endl;
}
```
