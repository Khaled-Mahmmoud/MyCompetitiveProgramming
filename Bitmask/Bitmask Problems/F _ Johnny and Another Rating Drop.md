# Johnny and Another Rating Drop

[Problem Link](https://codeforces.com/problemset/problem/1362/C)

```
00000
00001
00010
00011
00100
00101
00110
00111
01000
01001
01010
01011
01100
01101
01110
01111
10000
```
**Solution**

Let us start by calculating the result for n = 2^k. It can be quickly done by calculating the results for each bit separately and summing these up. 

For i-th bit, the result is equal to 2^k/2^i as this bit is different in d−1 and d if d is a multiple of 2^i. Summing these up we get that the result.

```cpp
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    int t;cin>>t;while(t--)
    {
        ll n,ans = 0;
        cin>>n;
        while(n)
        {
            ans += n;
            n >>= 1;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
```
