# Number of ways to choose K intersecting line segments on X-axis

Given an array arr[] of line segments on the x-axis and an integer K, the task is to calculate the number of ways to choose the K line-segments such that they do intersect at any point.
Since the answer can be large, print it to modulo 998244353.

```
input
7 3
1 7
3 8
4 5
6 7
1 3
5 10
8 9

output 
9

In first test case there are nine sets of k lamps: (1,2,3), (1,2,4), (1,2,5), (1,2,6), (1,3,6), (1,4,6), (2,3,6), (2,4,6), (2,6,7).
```

```cpp
#define ll unsigned long long
#define N 300005
#define mod 998244353
ll fact[N],inv[N];
ll power(ll x,ll y)
{
    x = x % mod;
    ll ans = 1;
    while(y)
    {
        if(y&1)
            ans = (ans * x)%mod;
        x = (x * x)%mod;
        y>>=1;
    }
    return ans;
}
void init()
{
    fact[0] = inv[0] = 1;
    for(int i=1;i<N;i++)
    {
        fact[i] = (i * fact[i-1])%mod;
        inv[i] = power(fact[i],mod-2);
    }
}
ll nCr(ll n,ll r)
{
    if(r>n)
       return 0;
    return ((fact[n]*inv[r])%mod * inv[n-r])%mod;
}
int main()
{
    init();
    int n, k;
  	cin >> n >> k;
	  vector<pair<int,int>>v(n);
    for(auto &it:v)
        cin>>it.first>>it.second;
	  sort(v.begin(), v.end());
    int ans = 0;
    multiset<int> m;
    for (int i=0;i<n;i++)
    {
        while (!m.empty()&&(*m.begin()<v[i].first))
            m.erase(m.begin());
        ans += nCr(m.size()+0ll, k - 1ll);
        ans = (ans%mod+mod)%mod;
        m.insert(v[i].second);
    }
    cout << ans << endl;
    return 0;
}
```
