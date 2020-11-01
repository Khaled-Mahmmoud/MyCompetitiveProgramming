# Find the longest sub-array having exactly k odd numbers

Given an array of size n. The problem is to find the longest sub-array having exactly k odd numbers.

Input : arr[] = {2, 3, 4, 11, 4, 12, 7}, k = 1

Output : 4 ,The sub-array is {4, 11, 4, 12}.

```cpp
int longSubarrWithKOddNum(int arr[], int n, int k) 
{ 
    int max = 0, count = 0, start = 0; 
    for (int i = 0; i < n; i++) 
    { 
        if (arr[i] % 2 != 0) 
            count++;
        while (count > k && start <= i)     
            if (arr[start++] % 2 != 0) 
                count--;
        if (count == k) 
            if (max < (i - start + 1)) 
                max = i - start + 1; 
    } 
    return max; 
} 
```
Time Complexity: O(n)
