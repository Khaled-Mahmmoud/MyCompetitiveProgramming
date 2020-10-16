# Most socially-distanced subsequence

[Problem Link](https://codeforces.com/problemset/problem/1364/B)

[Tutorial Link](https://codeforces.com/blog/entry/78781)

```cpp
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    int t;cin>>t;while(t--)
    {
        int n;cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        vector<int>ans;
        for(int i=0;i<n;i++)
            if(!i||i==n-1||(a[i-1]<a[i])!=(a[i]<a[i+1]))
                ans.push_back(a[i]);
        cout<<ans.size()<<'\n';
        for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<' ';
        cout<<'\n';
    }
    return 0;
}

```
