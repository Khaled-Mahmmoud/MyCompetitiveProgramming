#### Edit Distance

Given two strings str1 and str2 and below operations that can performed on str1. 
    
Find minimum number of edits (operations) required to convert ‘str1’ into ‘str2’

1) Insert
2) Remove
3) Replace

**Solution** : 
The idea is process all characters one by one staring from either from left or right sides of both strings.
Let us traverse from right corner, there are two possibilities for every pair of character being traversed.
    
m: Length of str1 (first string)
    
n: Length of str2 (second string)
    

1) Insert: Recur for m and n-1
2) Remove: Recur for m-1 and n
3) Replace: Recur for m-1 and n-1

```cpp
int dp[1009][1009];
string str1,str2;
int solve(int m,int n)
{
    if(m==0)return n;
    if(n==0)return m;

    int &rt = dp[m][n];
    if(~rt)return rt;

    if(str1[m-1]==str2[n-1])
        return rt = solve(m-1,n-1);
    return rt = 1 + min(solve(m-1,n),min(solve(m,n-1),solve(m-1,n-1)));
}
```

#### Printing Edit Distance

```cpp
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int dp[1009][1009];
string str1,str2;
int cnt,idx;
int solve(int m,int n)
{
    if(m==0)return n;
    if(n==0)return m;

    int &rt = dp[m][n];
    if(~rt)return rt;

    if(str1[m-1]==str2[n-1])
        return rt = solve(m-1,n-1);
    return rt = 1 + min(solve(m-1,n),min(solve(m,n-1),solve(m-1,n-1)));
}
void print(int m,int n)
{
    if(m==0)
    {
        while(n--)
            cout<<++cnt<<" Insert 1,"<<str2[n]<<'\n';
        return;
    }
    if(n==0)
    {
        while(m)
        cout<<++cnt<<" Delete "<<m--<<'\n';
        return;
    }

    if(str1[m-1]==str2[n-1])
    {
        idx--;
        print(m-1,n-1);
        return;
    }

    int optimal = dp[m][n];
    if(optimal == 1+solve(m-1,n))
    {
        cout<<++cnt<<" Delete "<<idx--<<'\n';
        print(m-1,n);
    }
    else if(optimal == 1+solve(m,n-1))
    {
        cout<<++cnt<<" Insert "<<idx+1<<','<<str2[n-1]<<'\n';
        print(m,n-1);
    }
    else
    {
        cout<<++cnt<<" Replace "<<idx--<<','<<str2[n-1]<<'\n';
        print(m-1,n-1);
    }
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    while(getline(cin,str1)&&getline(cin,str2))
    {
        memset(dp,-1,sizeof dp);
        cout<<solve(str1.size(),str2.size())<<'\n';
        cnt = 0;idx = str1.size();
        print(str1.size(),str2.size());
    }
    return 0;
}
```
#### Color the Fence

[Problem Link](https://codeforces.com/contest/349/problem/B)

`greed`
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
`dp` 
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
