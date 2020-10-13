# Competitive Programmer

[Problem Link](https://codeforces.com/contest/1266/problem/A)

[Tutorial Link](https://codeforces.com/contest/1266/problem/A)

```cpp
#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    int t;cin>>t;while(t--)
    {
        string str;
        cin>>str;
        bool fg = false;
        int cnt = 0,sum = 0;
        for(int i=0;i<str.size();i++)
        {
            if(str[i]=='0')
                fg = true;
            if((str[i]-'0')%2==0)
                cnt++;
            sum += str[i] - '0';
        }
        if(sum%3==0&&fg&&cnt>=2)
            cout<<"red\n";
        else
            cout<<"cyan\n";
    }
    return 0;
}
```
