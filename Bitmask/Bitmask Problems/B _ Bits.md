# Bits

[Problem Link](https://codeforces.com/contest/484/problem/A)

```cpp
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll l,r,c = 0;
        cin>>l>>r;
        if(l==r)
            cout<<l<<'\n';
        else
            for(ll i=1ll<<62; i>=1; i>>=1)
            {
                if(i-1<=r&&i-1>=l)
                {
                    cout<<i-1+c<<'\n';
                    break;
                }
                else if(i<=r&&i<=l)
                {
                    c+=i;
                    l-=i;
                    r-=i;
                }
            }
    }
    return 0;
}
```
