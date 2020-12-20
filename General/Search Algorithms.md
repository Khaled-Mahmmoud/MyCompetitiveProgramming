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
