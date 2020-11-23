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