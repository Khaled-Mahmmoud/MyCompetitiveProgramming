```cpp
// the number of ways we can place n queens to an n × n chessboard so that no two queens attack each other.
void search(int r)
{
    if(r == n)
    {
        cnt++;
        return;
    }
    for(int c = 0; c < n; c++)
    {
        if (col_vis[c] || d1_vis[c+r] || d2_vis[c-r+n-1])
            continue;
        col_vis[c] = d1_vis[c+r] = d2_vis[c-r+n-1] = 1;
        search(r+1);
        col_vis[c] = d1_vis[c+r] = d2_vis[c-r+n-1] = 0;
    }
}
```
