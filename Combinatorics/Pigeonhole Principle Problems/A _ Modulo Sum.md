# Modulo Sum

[Problem Link](https://codeforces.com/problemset/problem/577/B)

```cpp
vector<int>v;int dp[1009][1009];
int m;
bool subset(int n,int sum,bool x)
{
    if(!sum&&x)return true;
    if(!n)return false;
    int &rt = dp[n][sum];
    if(~rt)return rt;
    return rt = subset(n-1,sum%m,x)||subset(n-1,(sum+v[n-1])%m,true);
}
int main()
{
    int n;
    cin>>n>>m;
    v.resize(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        v[i] = v[i] % m;
    }
    memset(dp,-1,sizeof dp);
    if(n>m)
        cout<<"YES";
    else
    {
        if(subset(n,0,0))
            cout<<"YES";
        else
            cout<<"NO";
    }
    return 0;
}
```
