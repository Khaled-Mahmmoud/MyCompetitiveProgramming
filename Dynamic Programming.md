```cpp
int solve(int idx, int weight) // 0-1 Knapsack
{
    if (weight < 0)
        return -oo;
    if (weight == 0 || index == sz(items))
        return 0;
    int &rt = dp[idx][weight];
    if(~rt)
        return rt;
    return rt = max(solve(idx+1, weight), solve(idx+1, weight - item[idx].second) + item[idx].first);
}
int solve(int idx, int weight) // Multiple Knapsack
{
    if (weight < 0)
        return -oo;
    if (weight == 0 || index == sz(items))
        return 0;
    int &rt = dp[idx][weight];
    if(~rt)
        return rt;
    return rt = max(solve(idx+1, weight), solve(idx, weight - item[idx].second) + item[idx].first);
}
```
