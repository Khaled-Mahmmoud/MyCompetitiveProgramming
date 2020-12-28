### Binary Search
```cpp
int binarySearch()
{
    int l = 0, r = 1e9;
    while (l < r)
    {
        int mid = (l+r) / 2;

        if (valid(mid))
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}
```
**Double**
```cpp
double binarySearch()
{
    double l = 0, r = 1e9;
    double eps = 1e-9;  
    while (r-l > eps)
    {
        double mid = (l+r) / 2;

        if (valid(mid))
            r = mid;
        else
            l = mid;
    }
    return l;
}
```
### Ternary Search
```cpp
int ternary_search(int l, int r)
{
    while (l<=r)
    {
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;
                
        if(f(mid1) < f(mid2))
            l = mid1 + 1;
        else
            r = mid2 - 1;
    }
    return f(l);                   
}
```
**Double**
```cpp
double ternary_search(double l, double r)
{
    double eps = 1e-9;              
    while (r - l > eps)
    {
        double mid1 = l + (r - l) / 3;
        double mid2 = r - (r - l) / 3;
        
        if(f(mid1) < f(mid2))
            l = mid1;
        else
            r = mid2;
    }
    return f(l);                   
}
```
