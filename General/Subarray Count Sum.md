```cpp
// Given an unsorted array of integers (positive or negative)
// count a continuous subarray which adds to a given number.
int cnt_subarray(int arr[], int n, int sum)
{
    map<int, int> m;
    int res = 0;
    int cur = 0;
    for (int i = 0; i < n; i++) 
    {
        cur += arr[i];
        if (cur == sum)
            res++;
        if (m.find(cur - sum) != m.end())
            res += (m[cur - sum]);
        m[cur]++;
    }
    return res;
}
```
