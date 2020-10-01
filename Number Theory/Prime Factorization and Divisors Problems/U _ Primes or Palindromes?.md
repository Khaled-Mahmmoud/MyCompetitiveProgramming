# Primes or Palindromes?

[Problem Link](https://codeforces.com/contest/568/problem/A)

[Tutorial Link](https://codeforces.com/blog/entry/19705)

```cpp
#define ll long long
#define N 2000006
int spf[N];
void sieve()
{
    spf[0] = 1;
    for(int i=2;i*i<N;i++)
        if(!spf[i])
        for(int j=i;j<N;j+=i)
        if(!spf[j])
        spf[j] = i;
    for(int i=3;i<N;i+=2)
        if(!spf[i])
            spf[i] = i;
}
bool check(int num)
{
    if(!num)
        return false;
    string str = to_string(num);
    for(int i=0;i<str.size()/2;i++)
        if(str[i]!=str[str.size()-1-i])
            return false;
    return true;
}
int main()
{
    sieve();
    int p,q,ans = -1,prime=0,palindrome=0;
    cin>>p>>q;
    for(int i=0;i<N;i++)
    {
        if(spf[i]==i)
            prime++;
        if(check(i))
            palindrome++;
        if(q*prime<=palindrome*p)
            ans = i;
    }
    if(~ans)
        cout<<ans;
    else
        cout<<"Palindromic tree is better than splay tree";
    return 0;
}
```
