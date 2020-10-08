# a-Good String

[Problem Link](https://codeforces.com/contest/1385/problem/D)

```cpp
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
int check(string s,int idx)
{
    if(s.size()==1)
        if(s[0]==(idx+'a'))
            return 0;
        else
            return 1;
    string F,S;
    for(int i=0; i<s.size()/2; i++)
        F+=s[i];
    for(int i=s.size()/2; i<s.size(); i++)
        S+=s[i];
    return min((S.size()-count(S.begin(),S.end(),'a'+idx))+check(F,idx+1),
               (F.size()-count(F.begin(),F.end(),'a'+idx))+check(S,idx+1));
}
int32_t main()
{
    iostream::sync_with_stdio(0),cin.tie(0);
    int testcases,n;
    cin>>testcases;
    while(testcases--)
    {
        cin>>n;
        string s;
        cin>>s;
        cout<<check(s,0)<<endl;
    }
    return 0;
}
```
