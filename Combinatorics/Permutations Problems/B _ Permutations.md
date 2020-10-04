# Permutations

[Problem Link](https://codeforces.com/contest/124/problem/B)

```cpp
#define ll long long
int main()
{
    int n,k;
    cin>>n>>k;
    int a[n][k],p[k];
    for (int i = 0; i < n; i++)
    for (int j = 0; j < k; j++)
    {
        char c;
        cin>>c;
        a[i][j] = c - '0';
    }
    for (int i = 0; i < k; i++)
        p[i] = i;
    int ans = INT_MAX;
    do
    {
        int mn = INT_MAX, mx = -INT_MAX;
        for (int i = 0; i < n; i++)
        {
            int x = 0;
            for (int j = 0; j < k; j++)
                (x *= 10) += a[i][p[j]];
            mx = max(mx, x);
            mn = min(mn, x);
        }
        ans = min(ans, mx - mn);
    } while (next_permutation(p, p + k));
    cout<<ans;
    return 0;
}
```
