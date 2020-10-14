# Cracking the Code

[Problem Link](https://codeforces.com/problemset/problem/630/L)

**Solution**

The first catch is that the fifth power of five-digit number cannot be represented by a 64-bit integer. But we need not the fifth power, we need the fifth power modulo 10^5.

The second catch is that you need to output five digits, not the fifth power modulo 10^5. The difference is when fifth digit from the end is zero

```cpp
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int power(ll x,int y)
{
    ll ans = 1;
    x %= 100000;
    while(y)
    {
        if(y&1)
            ans = (ans*x)%100000;
        y >>= 1;
        x = (x*x) % 100000;
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    string str;
    cin>>str;
    int n = str[0]-'0';
    n *= 10;
    n += str[2] - '0';
    n *= 10;
    n += str[4] - '0';
    n *= 10;
    n += str[3] - '0';
    n *= 10;
    n += str[1] - '0';
    string s = to_string(power(n,5));
    for(int i=0;i<5-s.size();i++)
        cout<<'0';
    cout<<s;
    return 0;
}

```
