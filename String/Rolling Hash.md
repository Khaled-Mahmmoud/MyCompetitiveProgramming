# Rolling Hash

[Tutorial](https://github.com/Khaled-Mahmmoud/MyCompetitiveProgramming/blob/master/img/String/Rolling_Hash.pdf)

```cpp
#include <bits/stdc++.h>
#define ll long long
#define mod 2123456789ll
#define base 53ll
using namespace std;
ll power(ll a,ll b)
{
    ll ans = 1;
    num %= mod;
    while(b)
    {
        if(b&1)
            ans = (ans * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }
    return ans;
} 
ll remove(ll code,ll idx,ll val)
{
    return (code - (val * power(base,idx))%mod + mod) % mod;
}
ll insert(ll code,ll idx,ll val)
{
    return (code + (val * power(base,idx))%mod + mod) % mod;
}
ll shiftleft(ll code)
{
    return (base * code) % mod;
}
ll rolling_hash(string pat)
{
    ll patcode = 0;
    for(int i=0;i<pat.size();i++)
    {
        patcode = shiftleft(patcode);
        patcode = insert(patcode,0,pat[i]);
    }
    return patcode;
}
void pattern_search(string str,string pat)
{
    int n = pat.size();
    ll patcode = rolling_hash(pat);
    
    ll subcode = 0;
    
    for(int i=0;i<str.size();i++)
    {
        if(i-n>=0)
            subcode = remove(subcode,n-1,str[i-n]);
            
        subcode = shiftleft(subcode);
        subcode = insert(subcode,0,str[i]);
        
        if(patcode == subcode)
            cout<< (i+1) - pat.size() + 1 <<'\n';
    }
}
```
Time Complexity : O(n log m) where n is length of string str, m is length of string pat
