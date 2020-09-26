# Maximal Intersection

[Problem Link](https://codeforces.com/contest/1029/problem/C)

[Tutorial Link](https://codeforces.com/blog/entry/61439)

```cpp
#define ll long long
int main()
{
    int n;
    cin>>n;
    int l[n],r[n],prl[n+1], prr[n+1], sul[n+1], sur[n+1];
    for(int i=0;i<n;i++)
        cin>>l[i]>>r[i];

    prl[0] = sul[n] = 0;
    prr[0] = sur[n] = INT_MAX;

    for(int i=0;i<n;i++)
    {
        prl[i + 1] = max(prl[i], l[i]);
        prr[i + 1] = min(prr[i], r[i]);
    }

    for (int i = n - 1; i >= 0; --i)
    {
        sul[i] = max(sul[i + 1], l[i]);
        sur[i] = min(sur[i + 1], r[i]);
    }

    int ans = 0;
    for(int i=0;i<n;i++)
    ans = max(ans, min(prr[i], sur[i + 1]) - max(prl[i], sul[i + 1]));
    cout<<ans;
    return 0;
}
```
