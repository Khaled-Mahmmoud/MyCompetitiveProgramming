# N-bonacci Numbers

You are given two Integers N and M, and print all the terms of the series upto M-terms of the N-bonacci Numbers
For example, when N = 2, the sequence becomes Fibonacci, when n = 3, sequence becomes Tribonacci.

In general, in N-bonacci sequence, we use sum of preceding N numbers from the next term
For example, a 3-bonacci sequence is the following:
0, 0, 1, 1, 2, 4, 7, 13, 24, 44, 81

The Fibonacci sequence is a set of numbers that starts with one or zero, followed by a one
and proceeds based on the rule that each number is equal to the sum of preceding two numbers 0, 1, 1, 2, 3, 5, 8….

Input : N = 3, M = 8
Output : 0, 0, 1, 1, 2, 4, 7, 13

Method 1 (Simple)
    
Initialize first N-1 terms as 0 and N-th term as 1. Now to find terms from (N+1)-th to M-th
we simply compute sum of previous N terms.
```cpp
void bonacciseries(int n, int m) 
{ 
    int a[m] = { 0 }; 
    a[n - 1] = 1; 
    for (int i = n; i < m; i++) 
        for (int j = i - n; j < i; j++) 
            a[i] += a[j]; 
  
    for (int i = 0; i < m; i++) 
        cout << a[i] << "  "; 
} 
```
Time Complexity : O(M * N), Auxiliary Space : O(M)
Method 2 (Optimized)
We can optimize for large values of N. The idea is based on sliding window
The current term a[i] can be computed as a[i-1] + a[i-1] – a[i-n-1]
```cpp
void bonacciseries(int n, int m) 
{ 
  
    int a[m] = { 0 }; 
    a[n - 1] = 1; 
    a[n] = 1; 
  
    for (int i = n + 1; i < m; i++) 
        a[i] = 2 * a[i - 1] - a[i - n - 1]; 
  
    for (int i = 0; i < m; i++) 
        cout << a[i] << " "; 
} 
```
Time Complexity: O(M), Auxiliary Space: O(M)
