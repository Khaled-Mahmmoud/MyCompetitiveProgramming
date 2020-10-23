# Singhal and Equality

[Problem Link](https://codeforces.com/group/5jpDueUEHd/contest/300302/problem/D)

```cpp
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int solve(int n, const vector<int> &frq, int cnt)
{
    if (n % cnt != 0)
        return n;
    int rt = 0, tmp = n / cnt;
    for (int i = 0; i < 26; i++)
    {
        if (i < cnt)
            rt += max(frq[i] - tmp, 0);
        else
            rt += frq[i];
    }
    return rt;
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        vector<int> frq(26);
        for (auto ch : s)
            frq[ch - 'a']++;
        sort(frq.rbegin(), frq.rend());
        int rt = s.size();
        for (int i = 1; i <= 26; i++)
            rt = min(rt, solve(s.size(), frq, i));
        cout << rt << '\n';
    }
    return 0;
}
```
