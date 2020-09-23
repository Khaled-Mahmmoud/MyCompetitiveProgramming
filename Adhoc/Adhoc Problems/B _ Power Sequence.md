# Power Sequence
[Problem Link](https://codeforces.com/problemset/problem/1397/B)

```cpp
using namespace std;
int main()
{
    int n;cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    long long ans = 1e18;
    for(long long i=1;i*n<=10000000;i++)
    {
        long long res = 0,p = 1;
        bool flag = false;
        for(int j=0;j<n;j++)
        {
            if(p>1e10)
                flag = true;
            res += abs(a[j]-p);
            p = p * i;
        }
        if(flag)
            continue;
        ans = min(ans,res);
    }
    cout<<ans;
    return 0;
}
```
