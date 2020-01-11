template<class T>
T power(T base, T exp, T mod)
{
    T ans = 1;
    base %= mod;

    while (exp) 
    {
        if (exp & 1) ans = (ans * base) % mod;
        exp >>= 1;
        base = (base * base) % mod;
    }

    return ans;
}
// int x=3,y=2;   cout<<power(x,y,1000);
// ll a=2,b=3;    cout<<power(a,b,1000ll);
