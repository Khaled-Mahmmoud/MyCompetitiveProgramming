# Trouble Sort

[Problem Link](https://codeforces.com/problemset/problem/1365/B)

[Tutorial Link](https://codeforces.com/blog/entry/78504)

```cpp
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    int t;cin>>t;while(t--)
    {
        int n,x;cin>>n;
        int a[n];bool one = 0 , zero = 0;
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<n;i++)
        {
            cin>>x;
            if(x)
                one = 1;
            else
                zero = 1;
        }
        if(one&&zero)
            cout<<"Yes\n";
        else
        {
            bool fg = true;
            for(int i=1;i<n;i++)
                if(a[i]<a[i-1])
                  fg = false;
            cout<<(fg?"Yes\n":"No\n");
        }
    }
    return 0;
}

```
