# Window Sliding Technique

This technique shows how a nested for loop in some problems can be converted to a single for loop to reduce the time complexity.

Given an array of integers of size ‘n’. Our aim is to calculate the maximum sum of ‘k’ consecutive elements in the array.

Input  : arr[] = {100, 200, 300, 400}, k = 2

Output : 700
```cpp
int maxSum(int arr[], int n, int k) 
{ 
    int max_sum = INT_MIN; 
    for (int i = 0; i < n - k + 1; i++)
    { 
        int current_sum = 0; 
        for (int j = 0; j < k; j++) 
            current_sum = current_sum + arr[i + j]; 
        max_sum = max(current_sum, max_sum); 
    } 
    return max_sum; 
} 
```
Time Complexity is O(n * k)

**Window Sliding Technique**

```cpp
int maxSum(int arr[], int n, int k) 
{ 
    if (n < k) 
    { 
        cout << "Invalid"; 
        return -1; 
    } 
    int max_sum = 0; 
    for (int i = 0; i < k; i++) 
        max_sum += arr[i]; 
    int window_sum = max_sum; 
    for (int i = k; i < n; i++) 
    { 
        window_sum += arr[i] - arr[i - k]; 
        max_sum = max(max_sum, window_sum); 
    } 
    return max_sum; 
} 
```
Time Complexity is O(n)
