/*

Zeckendorf’s Theorem (Non-Neighbouring Fibonacci Representation)
Zeckendorf’s theorem states that every positive Every positive integer can be written uniquely 
as a sum of distinct non-neighbouring Fibonacci numbers. Two Fibonacci numbers are neighbours 
if they one come after other in Fibonacci Sequence (0, 1, 1, 2, 3, 5, ..)
For example, 3 and 5 are neighbours, but 2 and 5 are not.

Given a number, find a representation of number as sum of non-consecutive Fibonacci numbers.

Examples:



Input:  n = 10
Output: 8 2
8 and 2 are two non-consecutive Fibonacci Numbers
and sum of them is 10.

Input:  n = 30
Output: 21 8 1
21, 8 and 1 are non-consecutive Fibonacci Numbers
and sum of them is 30.

The idea is to use Greedy Algorithm.

1) Let n be input number

2) While n >= 0
     a) Find the greatest Fibonacci Number smaller than n.
        Let this number be 'f'.  Print 'f'
     b) n = n - f 
     
*/


int nearestSmallerEqFib(int n) 
{ 
    if (n == 0 || n == 1) 
        return n; 
    int f1 = 0, f2 = 1, f3 = 1; 
    while (f3 <= n)
    { 
        f1 = f2; 
        f2 = f3; 
        f3 = f1 + f2; 
    } 
    return f2; 
} 
void printFibRepresntation(int n) 
{ 
    while (n > 0)
    { 
        int f = nearestSmallerEqFib(n); 
        cout << f << " "; 
        n = n - f; 
    } 
} 
