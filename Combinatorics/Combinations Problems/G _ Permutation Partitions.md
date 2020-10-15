# Permutation Partitions

[Problem Link](https://codeforces.com/problemset/problem/1326/C)

[Tutorial Link](https://codeforces.com/blog/entry/74961)

```cpp
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    int n,k,x;ll ans = 0;
    cin>>n>>k;
    for(int i=n;i>=n-k+1;i--)
        ans += i;
    vector<int>v;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        if(x<=n&&x>=n-k+1)
            v.push_back(i);

    }
    ll res = 1;
    for(int i=1;i<v.size();i++)
        (res *= v[i] - v[i-1])%=998244353;
    cout<<ans<<' '<<res;
    return 0;
}

```
