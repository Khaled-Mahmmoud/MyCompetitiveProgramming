# Count of subarrays of size K with elements having even frequencies

Given an Array arr[] and an integer K, the task is to count subarrays of size K in which every element appears even number of times in the subarray.

Input: arr[] = {1, 4, 2, 10, 2, 10, 0, 20}, K = 4

Output: 1 ,Explanation: Only subarray {2, 10, 2, 10} satisfies the required condition.

```cpp
int countSubarray(int arr[], int K, int N) 
{ 
    if(K % 2 != 0) 
        return 0; 
    if(N < K) 
        return 0; 
    int start = 0,i = 0,cnt = 0; 
    int currXor = arr[i++];
    while(i < K) 
        currXor ^= arr[i++]; 
    if(!currXor) 
        cnt++; 
    currXor ^= arr[start++]; 
    while (i < N)  
    { 
        currXor ^= arr[i++]; 
        if(!currXor) 
            cnt++;
        currXor ^= arr[start++]; 
    }
    return cnt; 
} 
```
Time Complexity: O(N)

**Another Solution** : O(nlogn) using window sliding and hashing

```cpp
int countSubarray(int a[], int K, int N)
{
    if(K % 2 != 0)
        return 0;
    if(N < K)
        return 0;
    int i = 0,cnt = 0,ans=0;
    map<int,int>m;
    while(i < K)
    {
        m[a[i]]++;
        if(m[a[i]]&1)
            cnt++;
        else
            cnt--;
        i++;
    }
    if(!cnt)ans++;
    for(int i=K;i<N;i++)
    {
        m[a[i]]++;
        if(m[a[i]]&1)
            cnt++;
        else
            cnt--;
        m[a[i-K]]--;
        if(m[a[i-K]]&1)
            cnt++;
        else
            cnt--;
        if(!cnt)ans++;
    }
    return ans;
}
```
