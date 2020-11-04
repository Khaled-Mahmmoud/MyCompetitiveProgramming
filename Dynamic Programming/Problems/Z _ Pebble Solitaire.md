# Pebble Solitaire

[Problem Link](https://vjudge.net/problem/UVA-10651)

```cpp
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int setbit(int num,int idx){return (num|(1<<idx));}
int clearbit(int num,int idx){return (num&~(1<<idx));}
bool getbit(int num,int idx){return ((num>>idx)&1);}
int dp[1<<12];
int solve(int mask)
{
    int &rt = dp[mask];
    if(~rt)
        return dp[mask];
    rt = 0;
    for(int i=0;i<12-2;i++)
    {
        if(getbit(mask,i)&&getbit(mask,i+1)&&!getbit(mask,i+2))
        {
            int tmask = mask;
            tmask = clearbit(tmask,i);
            tmask = clearbit(tmask,i+1);
            tmask = setbit(tmask,i+2);
            rt = max(rt,1+solve(tmask));
        }
        if(!getbit(mask,i)&&getbit(mask,i+1)&&getbit(mask,i+2))
        {
            int tmask = mask;
            tmask = setbit(tmask,i);
            tmask = clearbit(tmask,i+1);
            tmask = clearbit(tmask,i+2);
            rt = max(rt,1+solve(tmask));
        }
    }
    return rt;
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int t;cin>>t;while(t--){
        string str;cin>>str;
        int mask = 0,cnt = 0;
        for(int i=0;str[i];i++)
            if(str[i]=='o'){
                mask = setbit(mask,i);
                cnt++;
            }
       memset(dp,-1,sizeof dp);
       cout<<cnt-solve(mask)<<'\n';
    }
    return 0;
}
```