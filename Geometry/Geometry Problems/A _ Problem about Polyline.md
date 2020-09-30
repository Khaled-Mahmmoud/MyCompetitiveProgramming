# Problem about Polyline

[Problem Link](https://codeforces.com/contest/578/problem/A)

[Tutorial Link](https://codeforces.com/blog/entry/20368)

```cpp
#define ll long long
int main()
{
    ll a,b;
    cin>>a>>b;
    if(a<b)puts("-1");
    else printf("%.12f\n",(a+b)/(2.*((a+b)/(2*b))));
    return 0;
}
```
