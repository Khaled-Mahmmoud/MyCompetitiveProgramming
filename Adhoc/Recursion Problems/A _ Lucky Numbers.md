# Lucky Numbers

[Problem Link](https://codeforces.com/contest/96/problem/B)

```cpp
#define ll long long
set<ll> super;
bool solve(ll n)
{
    int n4 = 0, n7 = 0;
    while(n)
    {
        if(n%10==7)
            n7++;
        else if(n%10==4)
            n4++;
        else
            return 0;
        n/=10;
    }
    return n4 == n7;
}
void init(ll x)
{
    if (x > 5e9)
        return;
    if (solve(x) && x > 0)
    {
        super.insert(x);
    }
    init(10 * x + 4);
    init(10 * x + 7);
}
int main()
{
    init(0);
    ll x;
    cin >> x;
    for (auto y: super)
    {
        if (y >= x)
        {
            cout << y << '\n';
            break;
        }
    }
    return 0;

```
