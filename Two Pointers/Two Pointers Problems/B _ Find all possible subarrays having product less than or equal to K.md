# Find all possible subarrays having product less than or equal to K

Given an array arr[], the task is to print all possible subarrays having a product of its elements less than or equal to K.

Input: arr[] = {2, 1, 3, 4, 5, 6, 2}, K = 10 

Output: [[2], [1], [2, 1], [3], [1, 3], [2, 1, 3], [4], [5], [6], [2]] 

```cpp
vector<vector<int>> maxSubArray(int arr[], int n, int K)
{
    vector<vector<int>> solution;
    int multi = 1;
    int start = 0;
    if (n <= 1 || K < 0)
        return solution;
    for(int i = 0; i < n; i++)
    {
        multi = multi * arr[i];
        while (multi > K)
        {
            multi = multi / arr[start];
            start++;
        }
        vector<int> list;
        for(int j = i; j >= start; j--) 
        {
            list.insert(list.begin(), arr[j]);
            solution.push_back(list);
        }
    }
    return solution;
}
```
Time Complexity: O(n^2)
