# Color the Fence

[Problem Link](https://codeforces.com/contest/349/problem/B)

```cpp
long long v,len,rem,arr[10],low=1e6,num;
int main()
{
    cin >> v;
    for(int i = 1;i<=9;i++)
    {
        cin >> arr[i];
        if(arr[i]<low)
            low = arr[i],num = i;
    }
    len = v/low,rem = v%low;
    if(!len)
        return cout << -1,0;
    vector<long long>ans;
    while(len--)
        ans.push_back(num);
    for(auto &i:ans)
        for(int j = 9;j>num;j--)
            if(arr[j]-arr[i]<=rem)
            {
                rem-=(arr[j]-arr[i]),i = j;
                break;
            }
    for(auto i:ans)
        cout << i;
    return 0;
}
```
### dp Solution

```cpp
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n, i, a[9], dp[15][1000005];
int solve(int j, int r)
{
    if(j < 0)
        return 0;
    if(~dp[j][r])
        return dp[j][r];
    return dp[j][r] = max(r >= a[j] ? solve(j, r - a[j]) + 1 : 0, solve(j - 1, r));
}
void print(int j, int r)
{
    if(j < 0)
        return;
    r >= a[j] && solve(j, r - a[j]) + 1 >= solve(j - 1, r) ? 
    (cout << j + 1, print(j, r - a[j])) : print(j - 1, r);
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    memset(dp, -1, sizeof dp);
    cin >> n;
    while(i < 9)
        cin >> a[i++];
    if(solve(8, n))
        print(8, n);
    else
        cout << -1;
    return 0;
}
```
