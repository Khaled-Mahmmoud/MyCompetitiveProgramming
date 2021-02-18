```cpp
// Computes the length of the longest increasing subsequence (LIS) 
// O(n.log(n))
int getLIS()
{
    int len = 0;
    vector<int> LIS(n, INT_MAX);
    for (int i = 0; i < n; ++i)
    {
        // To get the length of the longest non decreasing subsequence
        // replace function "lower_bound" with "upper_bound"
        int idx = lower_bound(LIS.begin(), LIS.end(), a[i]) - LIS.begin();
        LIS[idx] = a[i];
        len = max(len, idx);
    }
    return len + 1;
}
```
