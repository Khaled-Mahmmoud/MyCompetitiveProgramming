# Adding Powers

[Problem Link](https://codeforces.com/contest/1312/problem/C)

[Tutorial Link](https://codeforces.com/blog/entry/74640)

```cpp
#define ll long long
int main()
{
    int t;cin>>t;while(t--)
    {
        int n;ll k,u;cin>>n>>k;
        ll a[n];u = k;
        for(int i=0;i<n;i++)
        cin>>a[i];
        while(k<=1e16)
            k *= u;
        int cnt;
        while(k)
        {
            cnt = 0;
            for(int i=0;i<n;i++)
                if(a[i]>=k)
                {
                    a[i]-=k;
                    cnt++;
                }
            if(cnt>1)
                break;
            k /= u;
        }
        for(int i=0;i<n;i++)
            if(a[i])cnt = 2;
        if(cnt>1)
            cout<<"NO";
        else
            cout<<"YES";
        cout<<'\n';
    }
    return 0;
}
```
