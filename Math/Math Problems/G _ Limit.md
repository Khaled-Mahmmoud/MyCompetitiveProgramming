# Limit

[Problem Link](https://codeforces.com/problemset/problem/197/B)

[Tutorial Link](https://codeforces.com/blog/entry/4717)

```cpp
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    n++,m++;
    int a[n],b[m];
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<m;i++)
        cin>>b[i];
    if(m>n)
        cout<<"0/1";
    else if(n>m)
    {
        if(a[0]*b[0]>0)
            cout<<"Infinity";
        else
            cout<<"-Infinity";
    }
    else
    {
        int sign;
        if(a[0] * b[0]<0)
            cout<<'-';
        cout<<abs(a[0]/__gcd(a[0],b[0]))<<'/'<<abs(b[0]/__gcd(a[0],b[0]));
    }
    return 0;
}
```
