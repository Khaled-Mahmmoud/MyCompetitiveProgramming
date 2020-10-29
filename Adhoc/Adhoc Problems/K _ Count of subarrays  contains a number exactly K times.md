# Count of subarrays which contains a given number exactly K times

Given an array A[] of N elements consisting of values from 1 to N with duplicates, the task is to find the total number of subarrays which contain a given number num exactly K times.


Input: A[] = {1, 2, 1, 5, 1}, num = 1, K = 2 

Output: 2 ,Explanation: Subarrays {1, 2, 1, 5}, {1, 2, 1}, {2, 1, 5, 1} and {1, 5, 1} contains 1 exactly twice.

Input: A[] = {1, 5, 3, 5, 7, 5, 6, 5, 10, 5, 12, 5}, num = 5, K = 3 

Output: 14

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
