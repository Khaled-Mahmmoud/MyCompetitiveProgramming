# Number of subarrays having sum less than K

Given an array of non-negative numbers and a non-negative number k, find the number of subarrays having sum less than k. We may assume that there is no overflow.

Examples :

Input : arr[] = {2, 5, 6}, K = 10, Output : 4

The subarrays are {2}, {5}, {6} and {2, 5},

Input : arr[] = {1, 11, 2, 3, 15}, K = 10, Output : 4

{1}, {2}, {3} and {2, 3}


A **simple solution** is to generate all subarrays of the array and then count the number of arrays having sum less than K.

Time complexity : O(n^2)

**Efficient solution**

Time complexity : O(n)

```cpp
int countSubarrays(int arr[],int n, int k)
{
    int start = 0, end = 0, count = 0, sum = arr[0];
    while (start < n && end < n)
    {
        if (sum < k)
        {
            end++;
            if (end >= start)
                count += end - start;
            if (end < n)
                sum += arr[end];
        }
        else
        {
            sum -= arr[start];
            start++;
        }
    }
    return count;
}
```
