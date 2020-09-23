# Boboniu and Bit Operations

[Problem Link](https://codeforces.com/problemset/problem/1395/C)

**Solution**

Suppose the answer is A. Thus for all i (1 ≤ i ≤ n), c[i] | A = A.

Since a[i] , b[i] < 2^9, we can enumerate all integers from 0 to 2^9−1, and check if there exists j for each i that (a[i] & b[j]) | A = A. The minimum of them will be the answer.

The time complexity is O(2^9⋅n^2)
```cpp
int main()
{
    int n,m;
    cin >> n >> m;
    int a[n], b[m];
    for(int i = 0;i < n;++i)
        cin >> a[i];
    for(int i = 0;i < m;++i)
       cin >> b[i];
    for(int i = 0;i < (1 << 9);++i)
    {
        bool valid = 1;
        for(int j = 0;j < n;++j)
        {
            bool tmp = 0;
            for(int k = 0;k < m;++k)
                if((i | (a[j] & b[k])) == i)
                    tmp = 1;
            if(!tmp)    valid = 0;
        }
        if(valid)   return cout << i, 0;
    }
    return 0;
}
```
