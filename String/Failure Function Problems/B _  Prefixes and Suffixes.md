# Prefixes and Suffixes

[Problem Link](https://codeforces.com/contest/432/problem/D)

```cpp
#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> getprefix(string pat)
{
    int m = pat.size();
    vector<int>prefix(m);
    for(int i=1,len=0;i<m;i++)
    {
        while(len>0&&pat[i]!=pat[len])
            len = prefix[len-1];
        if(pat[i]==pat[len])
            prefix[i] = ++len;
        else
            prefix[i] = len;
    }
    return prefix;
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);

    string str;cin>>str;
    int n = str.size();
    vector<int>prefix = getprefix(str);
    vector<int>freq(n+1);
    for(int i=0;i<n;i++)
        freq[prefix[i]]++;
    for(int i=n-1;i>0;i--)
        freq[prefix[i-1]]+=freq[i];
    freq.erase(freq.begin());
    for(int i=0;i<n;i++)
        freq[i]++;
    vector<pair<int,int>>ans;
    while(prefix[n-1])
    {
        ans.push_back({prefix[n-1],freq[prefix[n-1]-1]});
        n = prefix[n-1];
    }
    ans.push_back({str.size(),1});
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<'\n';
    for(int i=0;i<ans.size();i++)
     cout<<ans[i].first<<' '<<ans[i].second<<'\n';
    return 0;
}
```

