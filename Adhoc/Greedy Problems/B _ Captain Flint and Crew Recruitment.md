# Captain Flint and Crew Recruitment

[Problem Link](https://codeforces.com/problemset/problem/1388/A)

```cpp
int main()
{
    int t;cin>>t;while(t--)
    {
        int n;
        cin>>n;
        if(n>30)
            if(n!=36&&n!=40&&n!=44)
              cout<<"YES\n"<<6<<' '<<10<<' '<<14<<' '<<n-30<<'\n';
           else
              cout<<"YES\n"<<6<<' '<<10<<' '<<15<<' '<<n-31<<'\n';
        else
            cout<<"NO\n";
    }
    return 0;
}
```
