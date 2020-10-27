# Big Vova

[Problem Link](https://codeforces.com/contest/1407/problem/B)

```cpp
int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int main()
{
    int t;cin>>t;while(t--)
    {
        int n;cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        int mx = 0 ,idx = -1;
        for(int i=0;i<n;i++)
        if(mx<a[i])
        {
            mx = a[i];
            idx = i;
        }
        bool vis[n];
        memset(vis,0,sizeof vis);
        vis[idx] = 1;
        cout<<mx<<' ';
        for(int i=1;i<n;i++)
        {
            idx = -1;
            for(int j=0;j<n;j++)
            if(!vis[j]&&(idx==-1||gcd(a[j],mx)>gcd(a[idx],mx)))
                idx = j;
            cout<<a[idx]<<' ';
            vis[idx] = true;
            mx = gcd(mx,a[idx]);
        }
        cout<<'\n';
    }
    return 0;
}
```
