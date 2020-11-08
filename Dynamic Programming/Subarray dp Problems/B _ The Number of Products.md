# The Number of Products

[Problem Link](https://codeforces.com/contest/1215/problem/B)

```cpp
#define ll long long
struct item
{
    ll pos,neg;
    item(ll pos = 0,ll neg = 0):pos(pos),neg(neg) {}
};
int n;
int a[200005];
item dp[200005];
int main()
{
    cin>>n;
    int a[n];
    ll s_pos = 0, s_neg = 0;
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        if(x<0)
            a[i] = -1;
        else if(x>0)
            a[i] = 1;
    }
    for(int i=n-1; i>=0; i--)
    {
        if(a[i]==1)
            dp[i].pos = 1;
        else if(a[i]==-1)
            dp[i].neg = 1;

        if(i<n-1)
        {
            if(a[i]==1)
            {
                dp[i].pos += dp[i+1].pos;
                dp[i].neg += dp[i+1].neg;
            }
            else if(a[i]==-1)
            {
                dp[i].pos += dp[i+1].neg;
                dp[i].neg += dp[i+1].pos;
            }
        }
        s_neg += dp[i].neg;
        s_pos += dp[i].pos;
    }
    cout<<s_neg<<' '<<s_pos;
    return 0;
}
```
