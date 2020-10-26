# Divide it!

[Problem Link](https://codeforces.com/contest/1176/problem/A)

```cpp
#include<bits/stdc++.h>
using namespace std;
long long f(long long n)
{
    if(n%5==0)
        return ((n/5)*4);
    if(n%3==0)
        return ((n/3)*2);
    if(n%2==0)
        return (n/2);
    return 0;
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        long long n,cnt=0;
        cin>>n;
        while(n>1)
        {
            n=f(n);
            if(n)
                cnt++;
            else
            {
                cnt=-1;
                break;
            }

        }
        cout<<cnt<<'\n';
    }
}
```
