/*
Queries for GCD of all numbers of an array except elements in a given range
Given an array of n numbers and a number of queries are also given. Each query will be represented by two integers l, r
The task is to find out the GCD of all the numbers of the array excluding the numbers given 
in the range l, r (both inclusive) for each query.
Input : arr[] = {2, 6, 9}
        Ranges [0 0], [1 1], [1 2]
Output : 3
         1
         2 
GCD of numbers excluding [0 0] or 
first element is GCD(6, 9) = 3
GCD of numbers excluding the [1 1] or
second element is GCD(2, 9) = 1
GCD of numbers excluding [1 2] is 
equal to first element = 2
*/

// Filling the prefix and suffix array 
void FillPrefixSuffix(int prefix[], int arr[], int suffix[], int n) 
{ 

    prefix[0] = arr[0]; 
    for (int i=1 ;i<n; i++) 
        prefix[i] = __gcd(prefix[i-1], arr[i]); 

    suffix[n-1] = arr[n-1]; 
  
    for (int i=n-2; i>=0 ;i--) 
        suffix[i] = __gcd(suffix[i+1], arr[i]); 
} 
  
int GCDoutsideRange(int l, int r, int prefix[], int suffix[], int n) 
{ 
    if (l==0) 
        return suffix[r+1]; 
    if (r==n-1) 
        return prefix[l-1]; 
    return __gcd(prefix[l-1], suffix[r+1]); 
} 
  
int main() 
{ 
    int arr[] = {2, 6, 9}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    int prefix[n], suffix[n]; 
    FillPrefixSuffix(prefix, arr, suffix, n); 
  
    int l = 0, r = 0; 
    cout << GCDoutsideRange(l, r, prefix, suffix, n) <<endl;
} 
