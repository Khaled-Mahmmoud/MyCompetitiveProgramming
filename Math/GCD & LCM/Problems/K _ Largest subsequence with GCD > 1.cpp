/*
Largest subsequence having GCD greater than 1
Given an array arr[], find the largest subsequence such that GCD of all those subsequence are greater than 1.
Examples:

Input: 3, 6, 2, 5, 4
Output: 3
Explanation: There are only three elements(6, 2, 4) having GCD greater than 1
i.e., 2. So the largest subsequence will be 3

Solution :
If we observe then we will found that to make gcd greater than 1
all such elements must contain common prime factor greater than 1 which evenly divides all these values
*/

#define MAX 100001 
int prime[MAX], countdiv[MAX]; 
void SieveOfEratosthenes() 
{ 
    for (int i = 2; i * i <= MAX; ++i) 
    { 
        if (!prime[i]) 
            for (int j = i * 2; j <= MAX; j += i) 
                prime[j] = i; 
    } 
  
    for (int i = 1; i < MAX; ++i) 
        if (!prime[i]) 
            prime[i] = i; 
} 
int largestGCDSubsequence(int arr[], int n) 
{ 
    int ans = 0; 
    for (int i=0; i < n; ++i) 
    { 
        int element = arr[i]; 
        while (element > 1) 
        { 
            int div = prime[element]; 
            ++countdiv[div]; 
            ans = max(ans, countdiv[div]); 
            while (element % div==0) 
                element /= div; 
        } 
    } 
    return ans; 
} 
  
int main() 
{ 
    SieveOfEratosthenes(); 
  
    int arr[] = {10, 15, 7, 25, 9, 35}; 
    int size = sizeof(arr) / sizeof(arr[0]); 
    cout << largestGCDSubsequence(arr, size);
    
    return 0; 
} 
