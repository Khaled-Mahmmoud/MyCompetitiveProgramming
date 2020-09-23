# Masha and two friends

[Problem Link](https://codeforces.com/contest/1080/problem/C)

[Tutorial Link](https://codeforces.com/blog/entry/63436)

```cpp
ll w(ll a, ll b)
{
    return ((a+1)/2) * ((b+1)/2) + (a/2) * (b/2);
}
ll W(ll x1, ll y1, ll x2, ll y2)
{
    return w(x2,y2) - w(x2,y1-1) - w(x1-1,y2) + w(x1-1,y1-1);
}

ll B(ll x1, ll y1, ll x2, ll y2)
{
    return (y2 - y1 + 1) * (x2 - x1 + 1) - W(x1,y1,x2,y2);
}

int main()
{
    int t;cin >> t;
    while(t--)
    {
        ll n,m,x1,x2,x3,x4,y1,y2,y3,y4;
        cin >> n >> m >>x1 >> y1 >>x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        ll white = W(1,1,m,n);
        ll black = B(1,1,m,n);
        white = white + B(x1,y1,x2,y2);
        black = black - B(x1,y1,x2,y2);
        white = white - W(x3,y3,x4,y4);
        black = black + W(x3,y3,x4,y4);
        if(max(x1,x3) <= min(x2,x4) && max(y1,y3) <= min(y2,y4))
        {
            white = white - B(max(x1,x3),max(y1,y3),min(x2,x4),min(y2,y4));
            black = black + B(max(x1,x3),max(y1,y3),min(x2,x4),min(y2,y4));
        }
        cout << white << ' ' << black << '\n';
    }
    return 0;
}
```
