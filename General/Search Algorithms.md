### Binary Search
```cpp
bool valid(int m)
{
    //
    return 1;
}
int binarySearch()
{
    int l = 0, r = 1e9,ans;
    while (l <= r)
    {
        int mid = (l+r) / 2;

        if (valid(mid))
            r = mid - 1,ans = mid;
        else
            l = mid + 1;
    }
    cout<<ans;
}
```
### Ternary Search
```cpp
double ternary_search(double l, double r)
{
    double eps = 1e-9;              
    while (r - l > eps)
    {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        
        double f1 = f(m1);      
        double f2 = f(m2);      
        
        if (f1 < f2)
            l = m1;
        else
            r = m2;
    }
    return f(l);                   
}
```
