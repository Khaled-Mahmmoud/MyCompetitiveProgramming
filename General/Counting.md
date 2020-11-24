#### Number of subarrays having sum exactly equal to k

Given an unsorted array of nonnegative integers, find a continuous subarray which adds to a given number.

Input: arr[] = {1, 4, 20, 3, 10, 5}, sum = 33

Ouptut: Sum found between indexes 2 and 4, Sum of elements between indices 2 and 4 is 20 + 3 + 10 = 33
```cpp
int countSubarrays(int arr[],int n, int k)
{
    int start = 0, end = 0, count = 0, sum = arr[0];
    while (start < n && end < n)
    {
        if (sum < k)
        {
            end++;
            if (end < n)
                sum += arr[end];
        }
        else
        {
            if (sum == k && end >= start)
                count++;
            sum -= arr[start];
            start++;
        }
    }
    return count;
}
```
Time Complexity : O(n)


Given an unsorted array of integers, find a continuous subarray which adds to a given number.

Input : arr[] = {10, 2, -2, -20, 10}, k = -10, Output : 3

Subarrays: arr[0...3], arr[1...4], arr[3..4] have sum exactly equal to -10.

Input : arr[] = {9, 4, 20, 3, 10, 5},k = 33, Output : 2, Subarrays : arr[0...2], arr[2...4] have sum exactly equal to 33.

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
        if (m.find(cur - sum) != m.end())
            res += (m[cur - sum]);
        m[cur]++;
    }
    return res;
}
```

Time Complexity: O(nlogn) 

#### Count of subarrays having exactly K prime numbers

Input: arr[] = {1, 2, 3, 4}, K = 2

Output: 4

Explanation: Since total number of prime number in the array are 2. So the 4 subarray with 2 prime number are:

- {2, 3}
- {1, 2, 3}
- {2, 3, 4}
- {1, 2, 3, 4}

**Solution**

Traverse the given array arr[] and check whether the element is prime or not.

If the current element is prime then change the value of array that that index to 1, Else change the value at that index to 0.

Now the given array is converted into Binary Array.

Find the count of subarray with sum equals to K in the above Binary Array using the approach discussed in this article.


#### Count of subarrays having exactly K perfect square numbers

Input: arr[] = {2, 4, 9, 3}, K = 2

Output: 4

Explanation: Since total number of perfect square number in the array are 2.

- {2, 4, 9}
- {2, 4, 9, 3}
- {4, 9}
- {4, 9, 3}

**Solution**

Traverse the given array arr[] and check whether the element is Perfect Square or not.

If the current element is Perfect Square then change the value of array at that index to 1, Else change the value at that index to 0.

Now the given array is converted into Binary Array.

Now, Find the count of subarray with sum equals to K in the above Binary Array using the approach discussed in this article.

#### Count subarrays with equal number of 1’s and 0’s

Given an array arr[] of size n containing 0 and 1 only. The problem is to count the subarrays having equal number of 0’s and 1’s.

Input : arr[] = {1, 0, 0, 1, 0, 1, 1}

Output : 8, The index range for the 8 sub-arrays are:
(0, 1), (2, 3), (0, 3), (3, 4), (4, 5)
(2, 5), (0, 5), (1, 6)
```cpp
int findSubarraySum(int arr[], int n, int sum=0)
{
    unordered_map<int, int>m;
    int res = 0;
    int cur = 0;
    for(int i=0;i<n;i++)
    if(!arr[i])arr[i] = -1;
    for (int i = 0; i < n; i++) 
    {
        cur += arr[i];
        if (cur == sum)
            res++;
        if (m.find(cur - sum)!= m.end())
            res += (m[cur - sum]);
        m[cur]++;
    }
    return res;
}
```

#### Count subarrays with same even and odd elements

Given an array of N integers, count number of even-odd subarrays. An even – odd subarray is a subarray that contains the same number of even as well as odd integers.

Input : arr[] = {2, 5, 7, 8} 

Output : 3

Explanation : There are total 3 even-odd subarrays. {2, 5}, {7, 8}, {2, 5, 7, 8}

```cpp
int findSubarraySum(int arr[], int n, int sum=0)
{
    unordered_map<int, int>m;
    int res = 0;
    int cur = 0;
    for(int i=0;i<n;i++)
    if(arr[i]&1)arr[i] = -1;
    else arr[i] = 1;
    for (int i = 0; i < n; i++) 
    {
        cur += arr[i];
        if (cur == sum)
            res++;
        if (m.find(cur - sum)!= m.end())
            res += (m[cur - sum]);
        m[cur]++;
    }
    return res;
}
```
