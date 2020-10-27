# Check if LCM of array elements is divisible by a prime number or not

Given an array and a prime number k, the task is to find if LCM of the array is divisible by k or not.
    
Input : int[] a = {10, 20, 15, 25} k = 3;

Output : true
    
**Solution** :
One simple solution is to first find LCM of array elements, then check if LCM is divisible by k or not.

Complexity : O(nlog(max(a[i])))
    
Here, we can find that LCM of array of number is divisible by a prime number k or not
If any number of the array is divisible by prime number k
then the LCM of the number is also divisible by prime number k
```cpp
bool func(int a[], int k, int n) 
{ 
    for (int i = 0; i < n; i++) 
        if (a[i] % k == 0) 
        return true; 
    return false; 
} 
```
Complexity : O(n)
