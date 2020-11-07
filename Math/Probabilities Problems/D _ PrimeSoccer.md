# PrimeSoccer

[Problem Link](https://vjudge.net/problem/TopCoder-10033)

`pro - dp`

```cpp
#include<bits/stdc++.h>
#define ll long long
using namespace std;
double a,b,dp[19][19][19];
bool prime(int n)
{
    if(n<2)
        return 0;
    if(!(n&1))
        return n==2;
    for(int i=3;i*i<=n;i++)
        if(!(n%i))return 0;
    return 1;
}
double solve(int r,int g1,int g2)
{
    if(r>=18)
        return prime(g1)||prime(g2)?1:0;
    double &rt = dp[r][g1][g2];
    if(abs(rt+1)>1e-9)
        return rt;
    rt = a*b*          solve(r+1,g1+1,g2+1);
    rt += a*(1-b)*     solve(r+1,g1+1,g2);
    rt += (1-a)*b*     solve(r+1,g1,g2+1);
    rt += (1-a)*(1-b)* solve(r+1,g1,g2);
    return rt;
}
class PrimeSoccer
{
public:
    double getProbability(int skillOfTeamA, int skillOfTeamB)
    {
        a = skillOfTeamA/100.0;
        b = skillOfTeamB/100.0;
        memset(dp,-1,sizeof dp);
        cout<<fixed<<setprecision(18);
        return solve(0,0,0);
    }
};
```

`pro - bit`

```cpp
#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool getbit(int n,int idx){return (n>>idx)&1;}
double a,b;
bool prime(int n)
{
    if(n<2)
        return 0;
    if(!(n&1))
        return n==2;
    for(int i=3;i*i<=n;i++)
        if(!(n%i))return 0;
    return 1;
}
double solve()
{
    double aa=0,bb=0;
    for(int i=0;i<(1<<18);i++)
    {
        double cur = 1;int cnt = 0;
        for(int j=0;j<18;j++)
            if(getbit(i,j))
              cur *= a,cnt++;
            else cur *=(1-a);
        if(prime(cnt))
            aa += cur;
    }
    for(int i=0;i<(1<<18);i++)
    {
        double cur = 1;int cnt = 0;
        for(int j=0;j<18;j++)
            if(getbit(i,j))
              cur *= b,cnt++;
            else cur *=(1-b);
        if(prime(cnt))
            bb += cur;
    }
    return aa*(1-bb) + (1-aa)*bb + aa*bb;
}
class PrimeSoccer
{
public:
    double getProbability(int skillOfTeamA, int skillOfTeamB)
    {
        a = skillOfTeamA/100.0;
        b = skillOfTeamB/100.0;
        memset(dp,-1,sizeof dp);
        cout<<fixed<<setprecision(18);
        return solve();
    }
};
```

`pro - ncr`

```cpp
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int ncr(int n,int r)
{
    if(r>n)
        return 0;
    if(r==0)
        return 1;
    return n*ncr(n-1,r-1)/r;
}
bool prime(int n)
{
    if(n<2)
        return 0;
    if(!(n&1))
        return n==2;
    for(int i=3;i*i<=n;i++)
        if(!(n%i))return 0;
    return 1;
}
class PrimeSoccer
{
public:
    double getProbability(int skillOfTeamA, int skillOfTeamB)
    {
        double a,b,ans=0;
        a = skillOfTeamA/100.0;
        b = skillOfTeamB/100.0;
        for(int i=0;i<=18;i++)
        for(int j=0;j<=18;j++)
        {
            double cur = 0;
            cur = ncr(18,i)*pow(a,i)*pow(1-a,18-i);
            cur *= ncr(18,j)*pow(b,j)*pow(1-b,18-j);
            if(prime(i)||prime(j))
                ans += cur;
        }
        cout<<fixed<<setprecision(18);
        return ans;
    }
};
```
