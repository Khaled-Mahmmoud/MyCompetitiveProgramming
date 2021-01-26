```cpp
// Ford-Fulkerson
const int MAXN = 100;
int cap[MAXN][MAXN],path[MAXN],path_length;
bool vis[MAXN];
int n;
int get_path(int src,int tar,int len,int max_cap)
{
    path[len] = src;
    if(src==tar)
    {
        path_length = len + 1;
        return max_cap;
    }
    int ret = 0;
    vis[src] = 1;
    for(int i=0;i<n;i++)
    {
        if(vis[i]||cap[src][i]<=0)
            continue;
        ret = get_path(i,tar,len+1,min(max_cap,cap[src][i]));
        if(ret>0)
            break;
    }
    return ret;
}
int max_flow(int src,int tar)
{
    int total_flow = 0;
    while(true)
    {
        memset(vis,0,sizeof vis);
        int new_flow = get_path(src,tar,0,INT_MAX);
        if(!new_flow)
            break;
        for(int i=1;i<path_length;i++)
        {
            int m = path[i-1], n = path[i];
            cap[m][n] -= new_flow;
            cap[n][m] += new_flow;
        }
        total_flow += new_flow;
    }
    return total_flow;
}// O(VE^2)
```
