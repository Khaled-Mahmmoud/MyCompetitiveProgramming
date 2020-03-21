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

Recommended: Please solve it on “PRACTICE” first, before moving on to the solution.
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


 
