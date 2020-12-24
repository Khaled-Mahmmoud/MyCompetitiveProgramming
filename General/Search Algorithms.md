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
Double
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
            l = mid + 1;
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
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 3;
                
        if (f(m1) < f(m2))
            l = m1;
        else
            r = m2;
    }
    return f(l);                   
}
```
Double
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
