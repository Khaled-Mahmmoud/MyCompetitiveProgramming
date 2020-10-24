# Two Pointers Technique

Two pointers is really an easy and effective technique which is typically used for searching pairs in a sorted array
Given a sorted array A (sorted in ascending order), having N integers, find if there exists any pair of elements (A[i], A[j])
such that their sum is equal to X.

Now let’s see how the two-pointer technique works. We take two pointers, one representing the first element and other representing 
the last element of the array, and then we add the values kept at both the pointers. If their sum is smaller than X then we shift
the left pointer to right or if their sum is greater than X then we shift the right pointer to left, in order to get closer to the sum
We keep moving the pointers until we get the sum as X

```cpp
bool isPairSum(A[], N, X) 
{ 
    int i = 0 , j = N - 1; 
    while (i < j)
    { 
          if (A[i] + A[j] == X) 
            return true; 
        else if (A[i] + A[j] < X) 
            i++; 
        else
            j--; 
    } 
    return false; 
} 
```
