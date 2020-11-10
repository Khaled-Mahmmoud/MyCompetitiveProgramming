# N-th multiple in sorted list of multiples of two numbers

[Problem Link](https://codeforces.com/group/MEqF8b6wBT/contest/277493/problem/M)

**Solution** :

f(a, b, x) :  Count of number that are less than x and multiples of a and b

f(a, b, x) = (x/a) + (x/b) - (x/lcm(a, b)) where 

(x/a) define number of multiples of a

(x/b) define number of multiple of b 

(x/lcm(a, b)) define the number of common multiples  of a and b

```cpp
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll gcd(ll a,ll b)
{
    if(!b)
        return a;
    return gcd(b,a%b);
}
ll lcm(ll a, ll b)
{
    return (a*b)/gcd(a,b);
}
ll x, n;
vector<ll>v;
ll inc_exe(ll m,int idx=0,ll d=1,int sign=-1,int cnt=0)
{
    if (idx==n)
    {
        if (!cnt) return 0;
        return sign*(m/d);
    }
    return inc_exe(m,idx+1,d,sign,cnt)+
           inc_exe(m,idx+1,lcm(d,v[idx]),sign*-1,cnt+1);
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    cin>>x>>n;
    v.resize(n);
    for (int i = 0; i < n; i++)
        cin>>v[i];
    ll l = 0ll, r = (ll)1e18;
    while(l < r)
     {
        ll mid = (l+r)>>1ll;
        ll cnt = inc_exe(mid);
        if (cnt < x)
             l = mid + 1;
        else
             r = mid;
    }
    cout<<r<<endl;
    return 0;
}

```
