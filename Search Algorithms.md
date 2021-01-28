```cpp
int binary_search()
{
    int l = 0, r = 1e9;
    while (l < r)
    {
        int mid = l + (r-l) / 2;

        if (valid(mid))
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}
double binary_search_d()
{
    double l = 0, r = 1e9;
    while (r-l > 1e-9) // somtimes give us time limited
    // better than above : while (r-l > 1e-6)
    // better than above : for (int i = 0; i < 100; ++i)
    {
        double mid = l + (r-l) / 2;

        if (valid(mid))
            r = mid;
        else
            l = mid;
    }
    return l;
}
// Ternary search to find an interger local minimum
int ternary_search(int l, int r)
{
    while(l<r)
    {
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;

        if (calc(mid1) < calc(mid2))
            r = mid2;
        else
            l = mid1;
    }
}
// Ternary search on to find a real (floating) local minimum
double ternary_search_d(double l, double r)
{
    while (r - l > 1e-9) // // somtimes give us time limited
    // better than above : while (r-l > 1e-6)
    // better than above : for (int i = 0; i < 100; ++i)
    {
        double mid1 = l + (r - l) / 3;
        double mid2 = r - (r - l) / 3;
        
        if(f(mid1) < f(mid2))
            r = mid2;
        else
            l = mid1;
    }
    return f(l);                   
}
```
