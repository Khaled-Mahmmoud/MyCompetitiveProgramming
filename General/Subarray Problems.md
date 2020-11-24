#### Count of subarrays which contains a given number exactly K times	
```cpp	
int countSubarrays(int A[], int num,int K, int size)  	
{                                                  	
    vector<int> indices;	
    for (int i = 0; i < size; i++) 	
        if (A[i] == num)	
            indices.push_back(i);	
    if (indices.size() < K)	
        return 0;	
    int prev = -1,ans = 0,ctr = 0;	
    for (int i = 0;i <= indices.size() - K;i++) 	
    {	
        ctr = indices[i] - prev;	
        if (i < indices.size() - K) 	
            ctr *= (indices[i + K]- indices[i + K - 1]);	
        else 	
            ctr *= ((size - 1) - indices[i + K - 1] + 1);	
        ans += ctr;	
        prev = indices[i];	
    }	
    return ans;	
}	
```	
Time Complexity : O(N)

#### Number of subarrays having sum exactly equal to k

Given an unsorted array of nonnegative integers, find a continuous subarray which adds to a given number.
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

**Solution**

Traverse the given array arr[] and check whether the element is prime or not.

If the current element is prime then change the value of array that that index to 1, Else change the value at that index to 0.

Now the given array is converted into Binary Array.

Find the count of subarray with sum equals to K in the above Binary Array using the approach discussed in this article.


#### Count of subarrays having exactly K perfect square numbers

**Solution**

Traverse the given array arr[] and check whether the element is Perfect Square or not.

If the current element is Perfect Square then change the value of array at that index to 1, Else change the value at that index to 0.

Now the given array is converted into Binary Array.

Now, Find the count of subarray with sum equals to K in the above Binary Array using the approach discussed in this article.

#### Count subarrays with equal number of 1’s and 0’s
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
 #### Longest sub-array having sum k
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

#### Largest subarray with equal number of 0s and 1s
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
#### Subarray with given XOR
Given an array of integers A and an integer B.
Find the total number of subarrays having bitwise XOR of all elements equals to B.
 
A = [4, 2, 2, 6, 4], B = 6
 
The subarrays having XOR of their elements as 6 are: [4, 2], [4, 2, 2, 6, 4], [2, 2, 6], [6]
 
```cpp
int findsubarray(int a[],int n,int b)
{
    unordered_map<int,int>m;
    int res = 0,cur = 0;
    for(int i=0;i<n;i++)
    {
        cur += a[i];
        if(cur==b)
            res++;
        if(m.find(cur^b)!=m.end())
            res += m[cur^b];
        m[cur]++;
    }
    return res;
}
```
