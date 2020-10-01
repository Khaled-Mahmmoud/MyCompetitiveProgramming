# Rat in a Maze Problem

Consider a rat placed at (0, 0) in a square matrix m[][] of order n and has to reach the destination at (n-1, n-1)
Your task is to complete the function printPath() which returns a sorted array of strings denoting all the possible directions 
which the rat can take to reach the destination at (n-1, n-1). Value 0 at a cell in the matrix represents that it is blocked and cannot be crossed while value 1 at a cell in the matrix represents that it can be travelled through.
The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right).

Constraints:

1 <= T <= 10
    
2 <= n <= 10
    
0 <= m[][] <= 1

Input:

2
    
4
    
1 0 0 0 1 1 0 1 0 1 0 0 0 1 1 1
    
4
    
1 0 0 0 1 1 0 1 1 1 0 0 0 1 1 1

Output:

DRDDRR

DDRDRR DRDDRR

```cpp
void solve(int x,int y,string s,vector<string>&res,int n,int m[MAX][MAX])
{
    if(!m[x][y]||x>=n||y>=n||x<0||y<0||m[x][y]==100)
        return ;
    if(x==n-1&&y==n-1)
        res.push_back(s);
    m[x][y] = 100;
    solve(x+1,y,s+'D',res,n,m);
    solve(x,y+1,s+'R',res,n,m);
    solve(x-1,y,s+'U',res,n,m);
    solve(x,y-1,s+'L',res,n,m);
    m[x][y] = 1;
}
vector<string> printPath(int m[MAX][MAX], int n)
{
    vector<string>res;
    solve(0,0,"",res, n,m);
    sort(res.begin(),res.end());
    return res;
}
```
