# The World is a Theatre

[Problem Link](https://codeforces.com/contest/131/problem/C)

### A group consists of 4 girls and 7 boys. In how many ways can a team of 5 members be selected is the team has at least one boy and one girl ?

**ANSWER**

Total number of girls in the group = 4

Total number of boys in the group = 7

Probability of selecting atleast one boy and one girl =?

By considering following ways we can select

- 1 girls + 4 boys ⇒  4C1 * 7C4
- 2 girls +3 boys  ⇒  4C2 * 7C3
- 3 girls +2 boys  ⇒  4C3 * 7C2
- 4 girls +1 boy   ⇒  4C4 * 7C1

Total number of ways = 4C1 * 7C4 + 4C2 * 7C3 + 4C3 * 7C2 + 4C4 * 7C1 = 140+210+84+7 =441

```cpp
#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;
ll dp[35][35];
ll ncr(int n,int r)
{
    if(r==0||r==n)
        return 1;
    ll &rt = dp[n][r];
    if(~rt)
        return rt;
    return rt = ncr(n-1,r-1) + ncr(n-1,r);
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m,t;
    cin>>n>>m>>t;
    memset(dp,-1,sizeof dp);
    ll ans = 0;
    for(int i=1;i<=m&&(t-i)>=4;i++)
        if(t-i<=n)
        ans += ncr(m,i) * ncr(n,t-i);
    cout<<ans;
    return 0;
}
```

### whay nC4 * mC1 * (n-4+m-1)C(t-5) is wrong ?

I think the error is that we are choosing same group multiple times.

For eg, lets say n=7 , m = 3 and t = 6. If we write nC4 * mC1 * (n+m-5)C(t-5) , what we are doing is selecting 4 boys,lets say A,B,C and D, one girl lets say girl G1, and out of the remaining people (Boys E F G, girls: G2, G3) we pick up one more.Lets suppose we pick up boy E. So, we have finally picked up : A,B,C,D,E and G1.

But this same combination is picked up when we pick up A B C E in the first four boys,G1 for choosing the girl and D in the remaining people to be picked up.This is the same combination and we are counting it twice.There will be multiple such cases and hence our formula seems wrong.

Please feel free to correct me!
