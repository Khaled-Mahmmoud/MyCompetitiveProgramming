# Number of subarrays having absolute sum greater than K 

Given an integer array arr[] of length N consisting of both positive and negative integers, the task is to find the number of sub-arrays with the absolute value of sum greater than a given positive number K.

Input : arr[] = {-1, 0, 1}, K = 0

Output : 4

All possible sub-arrays and there total sum: {-1} = -1, {0} = 0, {1} = 1, {-1, 0} = -1, {0, 1} = 1, {-1, 0, 1} = 0 

```cpp

int findCnt(int arr[], int n, int k) 
{ 
    int ans = 0; 
    for (int i = 1; i < n; i++)
    { 
        arr[i] += arr[i - 1]; 
        if (arr[i] > k or arr[i] < -1 * k) 
            ans++; 
    } 
    if (arr[0] > k || arr[0] < -1 * k) 
        ans++; 
    sort(arr, arr + n); 
    for (int i = 0; i < n; i++) 
        ans += n - (upper_bound(arr, arr + n, arr[i] + k) - arr); 
    return ans; 
} 
```
Time complexity : O(Nlog(N))
