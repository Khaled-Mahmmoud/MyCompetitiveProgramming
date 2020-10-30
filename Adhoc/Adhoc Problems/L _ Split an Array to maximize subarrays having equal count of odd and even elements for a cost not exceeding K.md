# Split an Array to maximize subarrays having equal count of odd and even elements for a cost not exceeding K

Given an array arr[] of size N and an integer K, the task is to split the given array into maximum possible subarrays having equal count of even and odd elements such that the cost to split the array does not exceed K.

Input: arr[] = {1, 2, 5, 10, 15, 20}, K = 4 

Output: 1 

Explanation: The optimal way is to split the array between 2 and 5. 
So it splits into {1, 2} and {5, 10, 15, 20}. 
Also, both the subarrays contain an equal number of even and odd elements. The cost of the split is abs(2 – 5) = 3 which is ≤ K.

Input: arr[] = {1, 2, 3, 4, 5, 6}, K = 100

Output: 2 

Explanation: The optimal way is to make two splits such that the subarrays formed are {1, 2}, {3, 4}, {5, 6}. 
The total cost is abs(2 – 3) + abs(4 – 5) = 2

```cpp
int make_cuts(int arr[], int n, int K) 
{ 
    int ans = 0; 
    vector<int> poss; 
    int even = 0,odd = 0; 
    for (int x = 0; x < n - 1; x++)
    { 
        if (arr[x]&1) 
            odd++; 
        else
            even++; 
        if (even == odd && odd > 0 && even > 0)
        { 
            poss.push_back(abs(arr[x] - arr[x + 1])); 
        } 
    } 
    sort(poss.begin(), poss.end()); 
    for (int x : poss) 
        if (K >= x)
            ans++, K -= x; 
        else
            break; 
    return ans; 
} 
```
Time Complexity: O(N log(N)) 
