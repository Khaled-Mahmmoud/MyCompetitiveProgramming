# Count of subarrays of size K having at least one pair with absolute difference divisible by K-1

Given an arr[] consisting of N elements, the task is to count all subarrays of size K having atleast one pair whose absolute difference is divisible by K – 1.

Input: arr[] = {1, 5, 3, 2, 17, 18}, K = 4

Output: 3

**Efficient Approach** : The above approach can be optimized using Pigeonhole Principle. Follow the steps below to solve the problem:

- Consider K-1 boxes labeled 0, 1, 2, …, K-2 respectively. They represent the remainders when any number x from the array is divided by K-1, which means the boxes store the modulo K-1 of array elements.

- Now, in a subarray of size K, according to the Pigeonhole Principle, there must be atleast one pair of boxes with same remainders. It means that there is atleast one pair whose difference or even the summation will be divisible by K.

- From this theorem we can conclude that every subarray of size K, will always have atleast one pair whose difference is divisible by K-1.

- So, the answer will be equal to the number of subarrays of size K possible from the given array, which is equal to N – K + 1.

```cpp
int findSubarrays(int arr[], int N,int K) 
{ 
    return N - K + 1; 
} 
int main() 
{ 
    int arr[] = { 1, 5, 3, 2, 17, 18 }; 
    int K = 4; 
    int N = sizeof(arr) / sizeof(arr[0]); 
  
    cout << findSubarrays(arr, N, K); 
  
    return 0; 
} 
```
Time complexity: O(1)
