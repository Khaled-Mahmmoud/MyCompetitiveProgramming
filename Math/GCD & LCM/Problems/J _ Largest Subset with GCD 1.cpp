/*
Given n integers, we need to find size of the largest subset with GCD equal to 1.

n <= 10^5
A[i] <= 10^5

Input : A = {2, 3, 5}
Output : 3

Input : A = {3, 18, 12}
Output : -1

Optimized O(n) solution :
Let say we find a subset with GCD 1, if we add a new element to it then GCD still remains 1
Hence if a subset exists with GCD 1 then GCD of the complete set is also 1
Hence we first find GCD of the complete set, if its 1 then complete set is that subset else no subset exist with GCD 1

*/

// Function to return gcd of a and b 
int gcd(int a, int b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b%a, a); 
} 
  
// Function to find largest subset with GCD 1 
int largestGCD1Subset(int A[], int n) 
{ 
    int currentGCD = A[0]; 
    for (int i=1; i<n; i++) 
    { 
        currentGCD = gcd(currentGCD, A[i]); 

        if (currentGCD == 1) 
            return n; 
    } 
  
    return 0; 
} 
  
int main() 
{ 
    int A[] = {2, 18, 6, 3}; 
    int n = sizeof(A)/sizeof(A[0]); 
    cout << largestGCD1Subset(A, n); 
    return 0; 
} 
// Time Complexity : O(n* log(n))
