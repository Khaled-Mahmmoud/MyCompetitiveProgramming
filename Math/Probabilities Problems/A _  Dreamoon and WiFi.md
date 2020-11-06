#  Dreamoon and WiFi

[Problem Link](https://codeforces.com/problemset/problem/476/B)


Probabilities = valid states / all states "pow(2,no of ?)"

The order of moves won't change the final position, so we can move all '?'s to the end of the string.

We have the following information:

1) the correct final position
2) the position that Dreamoon will be before all '?'s
3) the number of '?'s

```cpp
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int i,c=0,d=0,e=0,ans=0;
    string s1,s2;
    cin>>s1>>s2;
    for(i=0; s1[i]!='\0'; i++)
        s1[i] == '+' ? c++ : c--;
    for(i=0; s2[i]!='\0'; i++)
    {
        if(s2[i]=='+')
            d++;
        else if(s2[i]=='-')
            d--;
        else
            e++;
    }
    int x = (1<<e);double y=0;
    int to = __builtin_popcount(x-1);
    for(i=x-1;i>=0;i--)
    {
        int pos = __builtin_popcount(i);
        if(c==d+pos-(to-pos))
            y++;
    }
    cout<<fixed<<setprecision(9)<<y/x;
    return 0;
}
```
