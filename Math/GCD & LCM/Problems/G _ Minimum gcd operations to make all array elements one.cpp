/*
Minimum gcd operations to make all array elements one
Given an array A[] of size N. You can replace any number in the array with the gcd of that element with any of its adjacent elements
Find the minimum number of such operation to make the element of whole array equal to 1. If its not possible print -1.

Input : A[] = {4, 8, 9}
Output : 3
Explanation:
In the first move we choose (8, 9) 
gcd(8, 9) = 1. Now the array becomes {4, 1, 9}.
After second move, the array becomes {1, 1, 9}. 
After third move the array becomes {1, 1, 1}.

Input : A[] = { 5, 10, 2, 6 }
Output : 5
Explanation:
There is no pair with GCD equal one. We first
consider (5, 10) and replace 10 with 5. Now array
becomes { 5, 5, 2, 6 }. Now we consider pair (5, 2)
and replace 5 with 1, array becomes { 5, 1, 2, 6 }.
We have a 1, so further steps are simple.

Input : A[] = {8, 10, 12}
Output : -1
Explanation:
Its not possible to make all the element equal to 1.

Input : A[] = { 8, 10, 12, 6, 3 }
Output : 7

Solution
If initially the array contains 1, our answer is the difference between the size of the array and count of ones in the array.
If the array has no element equal to 1. We need to find the smallest sub array with GCD equal to one
Our result is N + (length of the minimum subarray with GCD 1) – 1. Example cases are { 5, 10, 2, 6 } and { 8, 10, 12, 6, 3 }.
We can find all the sub array in O(N^2) and GCD can be calculated in O(Log N) using Euclidean algorithms.
 Complexity : O(N^2 Log N)
*/

int minimumMoves(int A[], int N) 
{ 
    int one = 0; 
    for (int i = 0; i < N; i++)  
        if (A[i] == 1) 
            one++;  
      if (one != 0)  
        return N - one;  

    int minimum = INT_MAX; 
    for (int i = 0; i < N; i++) { 
        int g = A[i]; 
        for (int j = i + 1; j < N; j++) { 
            g = __gcd(A[j], g);  
            if (g == 1) { 
                minimum = min(minimum, j - i);  
                break; 
            } 
        } 
    } 
  
    if (minimum == INT_MAX) 
        return -1; 
    else
        return N + minimum - 1; 
} 
int main() 
{ 
    int A[] = { 2, 4, 3, 9 }; 
    int N = sizeof(A) / sizeof(A[0]); 
    cout << minimumMoves(A, N); 
    return 0; 
} 
