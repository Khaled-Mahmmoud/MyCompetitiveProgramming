template<class T>
T power(T a, T b, T mod)
{
    T ans = 1;
    a %= mod;

    while (b) 
    {
        if (b & 1) ans = (ans * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }

    return ans;
}
//  O(log b)
// int x=3,y=2;   cout<<power(x,y,1000);
// ll a=2,b=3;    cout<<power(a,b,1000ll);
