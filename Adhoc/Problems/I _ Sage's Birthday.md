# Sage's Birthday

[Problem Link](https://codeforces.com/contest/1419/problem/D2)

```cpp
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &it : v)
        cin >> it;
    sort(v.rbegin(), v.rend());
    vector<int> out(n);
    for (int i = 1; i < n; i += 2)
    {
        out[i] = v.back();
        v.pop_back();
    }
    for (int i = 0; i < n; i += 2)
    {
        out[i] = v.back();
        v.pop_back();
    }
    int cnt = 0;
    for (int i = 1; i < n - 1 ; i++)
        cnt += (out[i - 1] > out[i] && out[i] < out[i + 1]);
    cout << cnt << endl;
    for (auto &it : out)
        cout << it << ' ';
    return 0;
}
```
