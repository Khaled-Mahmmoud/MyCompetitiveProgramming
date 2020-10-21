# Omkar and Infinity Clock

[Problem Link](https://codeforces.com/problemset/problem/1392/B)

[Tutorial Link](https://codeforces.com/blog/entry/81565)


```cpp
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        ll k;
        cin>>n>>k;
        int a[n];
        for(int i=0; i<n; i++)
            cin>>a[i];
        int x = *max_element(a,a+n);
        for(int i=0; i<n; i++)
            a[i] = x - a[i];
        k--;
        x = *max_element(a,a+n);
        if(k&1)
            for(int i=0; i<n; i++)
                a[i] = x - a[i];
        for(int i=0; i<n; i++)
            cout<<a[i]<<' ';
        cout<<'\n';
    }
    return 0;
}
```
