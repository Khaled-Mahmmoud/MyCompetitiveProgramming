# Check if elements of array can be made equal by multiplying given prime numbers

Given an array of integers and an array of prime numbers. The task is to find if it is possible to make all the elements of integer array equal
by multiplying one or more elements from prime given array of prime numbers.
        
Input : arr[]   = {50, 200} , prime[] = {2, 3}

Output : Yes

We can multiply 50 with 2 two timesto make both elements of arr[] equal

**Solution**
We find LCM of all array elements.
        
All elements can be made equal only if it is possible to convert all numbers to LCM.
        
So we find the multiplier for each element so that we can make that element equal to LCM by multiplying that number
After that we find if numbers from given primes can form given multiplier.
        
```cpp
int lcmOfArray(int arr[], int n) 
{ 
    int ans = arr[0]; 
    for (int i=1; i<n; i++) 
        ans = (arr[i]*ans)/__gcd(arr[i], ans); 
    return ans; 
} 
bool checkArray(int arr[], int prime[], int n, int m) 
{ 
    int lcm = lcmOfArray(arr,n); 
    for (int i=0; i<n; i++) 
    { 
        int val = lcm/arr[i]; 
 
        for (int j=0; j<m && val!=1; j++) 
            while (val % prime[j] == 0) 
                val = val/prime[j]; 

        if (val != 1) 
          return false; 
    } 
  
    return true; 
} 
int main() 
{ 
    int arr[] = {50, 200}; 
    int prime[] = {2, 3}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    int m = sizeof(prime)/sizeof(prime[0]); 
    checkArray(arr, prime, n, m)? cout << "Yes" : cout << "No"; 
    return 0; 
} 
```
