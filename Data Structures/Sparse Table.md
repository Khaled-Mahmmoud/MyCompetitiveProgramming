```cpp
const int N = 2e5 + 5, K = 25;
int arr[N], mn[N][K + 1], lg[N + 1];
void build() 
{
    lg[1] = 0;
    for(int i = 2; i <= n; ++i)
        lg[i] = lg[i / 2] + 1;
    for(int i = 0; i < n; ++i)
        mn[i][0] = arr[i];
    for(int j = 1; j <= K; ++j) 
    {
        for (int i = 0; i + (1 << j) <= n; ++i)
        {
            mn[i][j] = min(mn[i][j - 1], mn[i + (1 << (j - 1))][j - 1]);
        }
    }
} // O(n.log(n))
int get_min(int l, int r) 
{
    int j = lg[r - l + 1];
    return min(mn[l][j], mn[r - (1 << j) + 1][j]);
} // O(1)
```
