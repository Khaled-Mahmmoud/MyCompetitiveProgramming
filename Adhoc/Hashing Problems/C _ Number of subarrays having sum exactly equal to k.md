# Number of subarrays having sum exactly equal to k

Given an array of integers, find the number of subarrays having sum exactly equal to a given number k.

Input : arr[] = {10, 2, -2, -20, 10}, k = -10, Output : 3

Subarrays: arr[0...3], arr[1...4], arr[3..4] have sum exactly equal to -10.

Input : arr[] = {9, 4, 20, 3, 10, 5},k = 33, Output : 2, Subarrays : arr[0...2], arr[2...4] have sum exactly equal to 33.

**Naive Solution** : 
A simple solution is to traverse all the subarrays and calculate their sum. If the sum is equal to the required sum then increment the count of subarrays. 

Complexity : O(n^2)

**Efficient Solution** 

```cpp
int findSubarraySum(int arr[], int n, int sum)
{
    unordered_map<int, int> m;
    int res = 0;
    int cur = 0;
    for (int i = 0; i < n; i++) 
    {
        cur += arr[i];
        if (cur == sum)
            res++;
       // if (m.find(cur - sum) != m.end())
            res += (m[cur - sum]);
        m[cur]++;
    }
    return res;
}
```

Time Complexity: O(nlogn) 

Auxiliary Space: O(n)


### Count of subarrays having exactly K prime numbers

Input: arr[] = {1, 2, 3, 4}, K = 2

Output: 4

Explanation: Since total number of prime number in the array are 2. So the 4 subarray with 2 prime number are:

- {2, 3}
- {1, 2, 3}
- {2, 3, 4}
- {1, 2, 3, 4}

Traverse the given array arr[] and check whether the element is prime or not.

If the current element is prime then change the value of array that that index to 1, Else change the value at that index to 0.

Now the given array is converted into Binary Array.

Find the count of subarray with sum equals to K in the above Binary Array using the approach discussed in this article.
