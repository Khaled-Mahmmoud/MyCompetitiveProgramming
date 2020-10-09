# Math

[Problem Link](https://codeforces.com/contest/1062/problem/B)

```
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    int n,ans=1,a;
    cin >> n;
    if(n==1)
    {
        cout<<"1 0";
        return 0;
    }
    vector<ll>v;
    for(int i = 2; i<=sqrt(n); i++)
    {
        if(n%i == 0)
        {
            ans*=i,a=0;
            while(n%i == 0)
                n/=i,a++;
            v.push_back(a);
        }
    }
    if(n > 1)
        ans*=n,v.push_back(1);
    sort(v.begin(),v.end());
    int cnt = 0,mx;
    for (mx = 1; mx < v.back(); mx *= 2)
        cnt++;
    for (int i: v)
        if (i != mx)
        {
            cnt++;
            break;
        }
    cout<<ans<<' '<<cnt;
        return 0;
}
```
