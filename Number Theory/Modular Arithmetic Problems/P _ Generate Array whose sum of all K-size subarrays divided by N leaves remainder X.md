# Generate Array whose sum of all K-size subarrays divided by N leaves remainder X

Given three integer N, K and X, the task is to create an array of length N suach that sum of all its K-length subarrays modulo N is X.

Input: N = 6, K = 3, X = 3

Output: 9 6 6 9 6 6

```cpp
m
void createArray(int n, int k, int x) 
{ 
    for (int i = 0; i < n; i++) 
    { 
        if (i % k == 0) 
            cout << x + n << " "; 
        else 
            cout << n << " "; 
    } 
} 
```
