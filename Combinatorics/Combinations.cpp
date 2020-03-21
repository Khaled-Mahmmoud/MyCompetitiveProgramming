/*

Program to calculate value of nCr
Given two numbers n and r, find value of nCr

Input :  n = 5, r = 2
Output : 30
The value of 5C2 is 10

Input : n = 3, r = 1
Output : 3

The idea is simply based on below formula
nCr = (n!) / ((n-r)! * r!)

*/

int fact(int n) 
{ 
    int res = 1; 
    for (int i = 2; i <= n; i++) 
        res = res * i; 
    return res; 
} 
int nCr(int n, int r) 
{ 
    return fact(n) / (fact(r) * fact(n - r)); 
} 

/*

A binomial coefficient C(n, k) also gives the number of ways, disregarding order
that k objects can be chosen from among n objects; more formally
the number of k-element subsets (or k-combinations) of an n-element set

The Problem
Write a function that takes two parameters n and k and returns the value of Binomial Coefficient C(n, k)
For example, your function should return 6 for n = 4 and k = 2, and it should return 10 for n = 5 and k = 2.

1) Optimal Substructure
The value of C(n, k) can be recursively calculated using following standard formula for Binomial Coefficients.



   C(n, k) = C(n-1, k-1) + C(n-1, k)
   C(n, 0) = C(n, n) = 1
*/

int binomialCoeff(int n, int k)  
{  
    if (k == 0 || k == n)  
        return 1;  
    return binomialCoeff(n - 1, k - 1) + binomialCoeff(n - 1, k);  
}  
/*
2) Overlapping Subproblems
It should be noted that the above function computes the same subproblems again and again
See the following recursion tree for n = 5 an k = 2. The function C(3, 1) is called two times
For large values of n, there will be many common subproblems.

                             C(5, 2)
                    /                      \
           C(4, 1)                           C(4, 2)
            /   \                          /           \
       C(3, 0)   C(3, 1)             C(3, 1)               C(3, 2)
                /    \               /     \               /     \
         C(2, 0)    C(2, 1)      C(2, 0) C(2, 1)          C(2, 1)  C(2, 2)
                   /        \              /   \            /    \
               C(1, 0)  C(1, 1)      C(1, 0)  C(1, 1)   C(1, 0)  C(1, 1)
Since same suproblems are called again, this problem has Overlapping Subproblems property
So the Binomial Coefficient problem has both properties (see this and this) of a dynamic programming problem
Like other typical Dynamic Programming(DP) problems, re-computations of same subproblems can be avoided by 
constructing a temporary array C[][] in bottom up manner. Following is Dynamic Programming based implementation

*/

int binomialCoeff(int n, int k) 
{ 
    int C[n + 1][k + 1]; 
    int i, j;
    for (i = 0; i <= n; i++) 
    { 
        for (j = 0; j <= min(i, k); j++) 
        { 
            if (j == 0 || j == i) 
                C[i][j] = 1; 
            else
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j]; 
        } 
    } 
  
    return C[n][k]; 
} 
// Time Complexity: O(n*k)
// Auxiliary Space: O(n*k)

/**
 * Computes the number of distinct sets of size "r" chosen from "n" items.
 *
 * Note that C(n, r) = C(n, n - r).
 * So call the function with nCr(n, min(r, n-r)) for better performance.
 *
 * Complexity: O(r)
 *
 * @return "n" choose "r".
 */
int nCr(int n, int r) 
{
    if (n < r)
        return 0;

    if (r == 0)
        return 1;

    return n * nCr(n - 1, r - 1) / r;
}
