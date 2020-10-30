# Count even length subarrays having bitwise XOR equal to 0

Given an array arr[] of size N, the task is to count all possible even length subarrays having bitwise XOR of subarray elements equal to 0.

Input: arr[] = {2, 2, 3, 3, 6, 7, 8}

Output: 3

Explanation: Subarrays having XOR of of elements equal to 0 are: {{2, 2}, {3, 3}, {2, 2, 3, 3}}
Therefore, the required output is 3.
```cpp

int cntSubXor(int arr[], int N)
{
    int prefixXor = 0, Even[M], Odd[M], cntSub = 0;
    Odd[0] = 1;
    for (int i = 0; i < N; i++) 
    {
        prefixXor ^= arr[i];
        if (i % 2 == 1) 
        {
            cntSub += Odd[prefixXor];
            Odd[prefixXor]++;
        }
        else 
        {
             cntSub += Even[prefixXor];
            Even[prefixXor]++;
        }
    }
    return cntSub;
}
```
Time Complexity: O(N)

Auxiliary Space: O(M), where M is the maximum bitwise XOR possible in all subarrays.
