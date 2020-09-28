# Non-zero Segments

[Problem Link](https://codeforces.com/contest/1426/problem/D)

```cpp
#define ll long long
int main()
{
    int n,ans = 0;
    cin>>n;
    ll a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    map<ll,int>m;
    ll c = 0;
    m[0]++;
    for(int i=0; i<n; i++)
    {
        c += a[i];
        if(m[c])
        {
            ans++;
            m.clear();
            m[0]++;
            c = a[i];
        }
        m[c]++;
    }
    cout<<ans;

    return 0;
}

```
