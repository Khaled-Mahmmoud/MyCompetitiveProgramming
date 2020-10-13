# 24 Game

[Problem Link](https://codeforces.com/problemset/problem/468/A)

[Tutorial Link](https://codeforces.com/blog/entry/138960)

```cpp
#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    if(n<4)
        cout<<"NO";
    else
    {
        cout<<"YES\n";
        int fg = 0;
        while(fg||(n!=4&&n!=5))
        {
            if(fg)
            {
                cout<<n<<" * "<<1<<" = "<<n<<'\n';
                fg = 0;
            }
            else
            {
                cout<<n<<" - "<<n-1<<" = 1\n";
                n -= 2;
                fg = 1;
            }
        }
        if(n==4)
        {
            cout<<"4 * 3 = 12\n";
            cout<<"12 * 2 = 24\n";
            cout<<"24 * 1 = 24";
        }
        else
        {
            cout<<"5 - 3 = 2\n";
            cout<<"2 + 1 = 3\n";
            cout<<"4 * 3 = 12\n";
            cout<<"12 * 2 = 24\n";
        }
    }
    return 0;
}
```
