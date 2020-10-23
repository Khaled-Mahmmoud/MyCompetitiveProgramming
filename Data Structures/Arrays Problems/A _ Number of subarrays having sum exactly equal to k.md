# Number of subarrays having sum exactly equal to k

Given an array of integers, find the number of subarrays having sum exactly equal to a given number k.

Input : arr[] = {10, 2, -2, -20, 10}, k = -10, Output : 3

Subarrays: arr[0...3], arr[1...4], arr[3..4] have sum exactly equal to -10.

Input : arr[] = {9, 4, 20, 3, 10, 5},k = 33, Output : 2, Subarrays : arr[0...2], arr[2...4] have sum exactly equal to 33.

**Naive Solution** : 
A simple solution is to traverse all the subarrays and calculate their sum. If the sum is equal to the required sum then increment the count of subarrays. 

Complexity : O(n^2)

**Efficient Solution** : 

Time Complexity: O(nlogn) 

Auxiliary Space: O(n)

```cpp
int findSubarraySum(int arr[], int n, int sum)
{
    unordered_map<int, int> prevSum;
    int res = 0;
    int currsum = 0;
    for (int i = 0; i < n; i++) 
    {
        currsum += arr[i];
        if (currsum == sum)
            res++;
        if (prevSum.find(currsum - sum) != prevSum.end())
            res += (prevSum[currsum - sum]);
        prevSum[currsum]++;
    }
    return res;
}
```
