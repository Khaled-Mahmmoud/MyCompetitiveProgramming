# Find number of solutions of a linear equation of n variables

Given a linear equation of n variables, find number of non-negative integer solutions of it. For example,let the given equation be “x + 2y = 5”, solutions of this equation are “x = 1, y = 2”, “x = 5, y = 0” and “x = 1. It may be assumed that all coefficients in given equation are positive integers.

Input:  coeff[] = {1, 2}, rhs = 5

Output: 3

The equation "x + 2y = 5" has 3 solutions.
(x=3,y=1), (x=1,y=2), (x=5,y=0)

Input:  coeff[] = {2, 2, 3}, rhs = 4

Output: 3

The equation "2x + 2y + 3z = 4"  has 3 solutions.
(x=0,y=2,z=0), (x=2,y=0,z=0), (x=1,y=1,z=0)

We can solve this problem recursively. The idea is to subtract first coefficient from rhs and then recur for remaining value of rhs.
```cpp
int countSol(int coeff[], int start, int end, int rhs) 
{ 
    if (rhs == 0) 
    return 1; 
  
    int result = 0;  
   
    for (int i = start; i <= end; i++) 
    if (coeff[i] <= rhs) 
        result += countSol(coeff, i, end, rhs - coeff[i]); 
  
    return result; 
} 
int main() 
{ 
    int coeff[] = {2, 2, 5}; 
    int rhs = 4; 
    int n = sizeof(coeff) / sizeof(coeff[0]); 
    cout << countSol(coeff, 0, n - 1, rhs);   // 3
    return 0; 
} 
```
The time complexity of above solution is exponential. We can solve this problem in Pseudo Polynomial Time (time complexity is dependent on numeric value of input) using Dynamic Programming. The idea is similar to Dynamic Programming solution Subset Sum problem. Below is Dynamic Programming based implementation.

```cpp
int countSol(int coeff[], int n, int rhs) 
{ 
    int dp[rhs + 1]; 
    memset(dp, 0, sizeof(dp)); 
    dp[0] = 1; 
  
    for (int i = 0; i < n; i++) 
    for (int j = coeff[i]; j <= rhs; j++) 
        dp[j] += dp[j - coeff[i]]; 
  
    return dp[rhs]; 
} 
int main() 
{ 
    int coeff[] = {2, 2, 5}; 
    int rhs = 4; 
    int n = sizeof(coeff) / sizeof(coeff[0]); 
    cout << countSol(coeff, n, rhs);          // 3
    return 0; 
}
```
Time Complexity of above solution is O(n * rhs)
