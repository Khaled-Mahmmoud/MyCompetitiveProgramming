# The Number of negative, positive and zero product subarray

[Problem Link](https://codeforces.com/contest/1215/problem/B)

```cpp
#define ll long long
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int pos = -1;
    ll ans0 = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
            pos = i;
        if (pos != -1)
            ans0 += pos + 1;
    }
    int cnt1 = 0, cnt2 = 0, bal = 0;
    ll ansP = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            cnt1 = 0, cnt2 = 0, bal = 0;
            continue;
        }
        if (bal % 2 == 0)
            cnt1++;
        else
            cnt2++;

        if (a[i] < 0)
            bal++;

        if (bal % 2 == 0)
            ansP += cnt1;
        else
            ansP += cnt2;

    }
    cout << 1ll * n * (n + 1) / 2 - ans0 - ansP << ' ' << ansP;
    return 0;
}
```
