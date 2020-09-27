# k-Amazing Numbers

[Problem Link](https://codeforces.com/contest/1417/problem/C)

```cpp
#define ll long long
#define N 300005
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int a[n+1], gap[n+1], last[n+1], ans[n+1];
        for (int i=0; i<=n; i++)
            last[i] = gap[i] = 0, ans[i] = n+1;
        for (int i=1; i<=n; i++)
        {
            cin>>a[i];
            gap[a[i]] = max(gap[a[i]], i-last[a[i]]);
            last[a[i]] = i;
        }
        for (int i=1; i<=n; i++)
        {
            gap[i] = max(gap[i], n+1-last[i]);
            if (gap[i] != n+1)
                ans[gap[i]] = min(ans[gap[i]], i);
        }
        for (int i=1; i<=n; i++)
        {
            ans[i] = min(ans[i], ans[i-1]);
            if (ans[i] == n+1)
                cout<<-1<<' ';
            else
                cout<<ans[i]<<' ';
        }
        cout<<'\n';
    }
}
```
