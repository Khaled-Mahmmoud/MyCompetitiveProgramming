 # Longest sub-array having sum k

Given an array arr[] of size n containing integers. The problem is to find the length of the longest sub-array having sum equal to the given value k.

Input : arr[] = { 10, 5, 2, 7, 1, 9 }, k = 15

Output : 4, The sub-array is {5, 2, 7, 1}.

Input : arr[] = {-5, 8, -14, 2, 4, 12}, k = -5

Output : 5

```cpp
int lenOfLongSubarr(int arr[],int n,int k) 
{ 
    unordered_map<ll, int> m; 
    ll sum = 0;int len = 0; 
    for (int i = 0; i < n; i++)
    { 
        sum += arr[i]; 
        if (sum == k) 
            len = i + 1; 
        if (m.find(sum) == m.end()) 
            m[sum] = i; 
        if (m.find(sum - k) != m.end())  
            if (len < (i - m[sum - k])) 
                len = i - m[sum - k]; 
    } 
    return len;
} 
```
Time Complexity: O(n)
