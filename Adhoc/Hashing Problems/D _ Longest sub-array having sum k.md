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
    ll sum = 0;int len = 0,index = -1;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == k)
        {
            len = i + 1;
            index = i;
        }
        if (m.find(sum) == m.end())
            m[sum] = i;
        if (m.find(sum - k) != m.end())
            if (len < (i - m[sum - k]))
                len = i - m[sum - k],index = i;
    }
    cout<<index-len+1<<' '<<index;
    return len;
}
```
Time Complexity: O(n)

# Largest subarray with equal number of 0s and 1s

Given an array containing only 0s and 1s, find the largest subarray which contains equal no of 0s and 1s. 

Input : arr[] = {1, 0, 0, 1, 0, 1, 1}

Output : 8, The index range for the 8 sub-arrays are:
(0, 1), (2, 3), (0, 3), (3, 4), (4, 5)
(2, 5), (0, 5), (1, 6)
```cpp
int maxLen(int a[], int n)
{
    for(int i=0;i<n;i++)
    if(!a[i])a[i] = -1;
    unordered_map<int, int> m;
    int sum = 0,len = 0,index = -1,k=0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        if (sum == k)
        {
            len = i + 1;
            index = i;
        }
        if (m.find(sum) == m.end())
            m[sum] = i;
        if (m.find(sum - k) != m.end())
            if (len < (i - m[sum - k]))
                len = i - m[sum - k],index = i;
    }
    cout<<index-len+1<<' '<<index;
    return len;
}
```
