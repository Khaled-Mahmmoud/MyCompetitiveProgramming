```cpp
// count number of k-length substrings of given string that is palindrome
const int mod = 1e9 + 7;
const int base = 128;
int mul(int x,int y)
{
    return 1ll * x * y % mod;
}
int power(int a,int b)
{
    int ans = 1;
    while(b)
    {
        if(b&1)
            ans = mul(ans,a);
        b >>= 1;
        a = mul(a,a);
    }
    return ans;
}
const int inv = power(base,mod-2);
int add(int x,int y)
{
    return (x+y)%mod;
}
int sub(int x,int y)
{
    return add(x,mod-y);
}
int rabin(string s,int k)
{
    int h1 = 0,h2 = 0, p = 1;
    for(int i=0,j=k-1;i<k;i++,j--)
    {
        if(i)
            p = mul(p,base);
        h1 = mul(h1,base);
        h1 = add(h1,s[i]);

        h2 = mul(h2,base);
        h2 = add(h2,s[j]);
    }
    int res = 0;
    for(int i=k,j=0;;i++,j++)
    {
        res += h1 == h2;
        if(!s[i])
            break;
        h1 = sub(h1,mul(s[j],p));
        h1 = mul(h1,base);
        h1 = add(h1,s[i]);

        h2 = sub(h2,s[j]);
        h2 = mul(h2,inv);
        h2 = add(h2,mul(s[i],p));
    }
    return res;
}
int main()
{
    string s;
    int k;
    cin>>k>>s;
    cout<<rabin(s,k);
    return 0;
}
```
