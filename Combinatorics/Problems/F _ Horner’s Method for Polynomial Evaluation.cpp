/*

Horner’s Method for Polynomial Evaluation
Given a polynomial of the form cnxn + cn-1xn-1 + cn-2xn-2 + … + c1x + c0 and a value of x
find the value of polynomial for a given value of x
Here cn, cn-1, .. are integers (may be negative) and n is a positive integer.

Input is in the form of an array say poly[] where poly[0] represents coefficient for xn and poly[1]
represents coefficient for xn-1 and so on

Input: poly[] = {2, -6, 2, -1}, x = 3
Output: 5

Input: poly[] = {2, 0, 3, 1}, x = 2
Output: 23

A naive way to evaluate a polynomial is to one by one evaluate all terms
First calculate xn, multiply the value with cn, repeat the same steps for other terms and return the sum
Time complexity of this approach is O(n2) if we use a simple loop for evaluation of xn
Time complexity can be improved to O(nLogn) if we use O(Logn) approach for evaluation of xn.
Horner’s method can be used to evaluate polynomial in O(n) time. To understand the method
let us consider the example of 2x3 – 6x2 + 2x – 1. The polynomial can be evaluated as ((2x – 6)x + 2)x – 1
The idea is to initialize result as coefficient of xn which is 2 in this case
repeatedly multiply result with x and add next coefficient to result. Finally return result.

*/

int horner(int poly[], int n, int x) 
{ 
    int result = poly[0];  
  
    for (int i=1; i<n; i++) 
        result = result*x + poly[i]; 
  
    return result; 
} 
int main() 
{ 
    int poly[] = {2, -6, 2, -1}; 
    int x = 3; 
    int n = sizeof(poly)/sizeof(poly[0]); 
    cout << "Value of polynomial is " << horner(poly, n, x); 
    return 0; 
} 
/*
Output:
Value of polynomial is 5
Time Complexity: O(n)
