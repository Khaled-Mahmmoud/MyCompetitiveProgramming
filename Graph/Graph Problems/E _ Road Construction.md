# Road Construction

[Problem Link](https://codeforces.com/problemset/problem/330/b?locale=en)

**Solution**

The constraints can be satisfied if and only if the graph is a [star graph](https://github.com/Khaled-Mahmmoud/MyCompetitiveProgramming/blob/master/img/Graph/Star%20graph.png), Since m < n/2, there exists at least one node that is not incident to any edge of m edges.

```cpp
int main()
{
    int n,m;
    cin>>n>>m;
    int a[n+1]= {};
    int x,y;
    while(m--)
    {
        cin>>x>>y;
        a[x] = 1;
        a[y] = 1;
    }
    for(int i=1; i<=n; i++)
        if(!a[i])
        {
            x = i;
            break;
        }
    cout<<n-1<<'\n';
    for(int i=1; i<=n; i++)
        if(x!=i)
            cout<<x<<' '<<i<<'\n';
    return 0;
}
```
