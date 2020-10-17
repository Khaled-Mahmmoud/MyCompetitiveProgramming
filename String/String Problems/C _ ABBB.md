# ABBB

[Problem Link](https://codeforces.com/contest/1428/problem/C)

```cpp
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    int t;cin>>t;while(t--){
        string str;cin>>str;
        vector<pair<char,int>>v;
        char c = str[0];int cnt = 1,ans=0;
        for(int i=1;i<str.size();i++)
            if(str[i]==c)cnt++;
            else{
                v.push_back({c,cnt});
                c = str[i];cnt = 1;
            }
        if(cnt)
        v.push_back({c,cnt});
        pair<char,int> res = v[v.size()-1];
        for(int i=v.size()-2;i>=0;i--)
        {
            if(res.first==v[i].first)
                res.second += v[i].second;
            else{
                if(v[i].first=='A'){
                    int x = min(v[i].second,res.second);
                    ans += 2*x;
                    v[i].second -= x;
                    res.second -= x;
                    if(v[i].second)
                        res = v[i];
                }
                else
                    res = v[i];
            }
        }
        if(res.first=='B')
            ans += res.second - (res.second&1);
        cout<<str.size()-ans<<'\n';
    }
    return 0;
}
```
