/*
Find Square Root under Modulo p (When p is in form of 4*i + 3)
Given a number ‘n’ and a prime ‘p’, find square root of n under modulo p if it exists
It may be given that p is in the form for 4*i + 3 (OR p % 4 = 3) where i is an integer
Examples of such primes are 7, 11, 19, 23, 31, … etc

Input:  n = 2, p = 7
Output: 3 or 4
3 and 4 both are square roots of 2 under modulo 7
because (3*3) % 7 = 2 and (4*4) % 7 = 2

Input:  n = 2, p = 5
Output: Square root doesn't exist

Naive Solution : Try all numbers from 2 to p-1. And for every number x
check if x is square root of n under modulo p
Time Complexity of this solution is O(p)

Direct Method : If p is in the form 4*i + 3 with i >= 1 (OR p % 4 = 3)
And If Square root of n exists, then it must be  ±n^[(p + 1)/4]
Time Complexity of this solution is O(Log p)

*/

int power(int x, int y, int p) 
{ 
    int res = 1; 
    x = x % p; 
    while (y) 
    { 
        if (y & 1) 
            res = (res * x) % p; 
        y = y >> 1; 
        x = (x * x) % p; 
    } 
    return res; 
} 
void squareRoot(int n, int p) 
{ 
    if (p % 4 != 3)
    { 
        cout << "Invalid Input"; 
        return; 
    } 
  
    // Try "+(n^((p + 1)/4))" 
    n = n % p; 
    int x = power(n, (p + 1) / 4, p); 
    if ((x * x) % p == n) 
    { 
        cout << "Square root is " << x; 
        return; 
    } 
    
    // Try "-(n ^ ((p + 1)/4))" 
    x = p - x; 
    if ((x * x) % p == n)
    { 
        cout << "Square root is " << x; 
        return; 
    } 
    cout << "Square root doesn't exist "; 
} 
/*

How does this work?
We have discussed Euler’s Criterion in the previous post.

As per Euler's criterion, if square root exists, then 
following condition is true
 n^(p-1)/2 % p = 1

Multiplying both sides with n, we get
 n^(p+1)/2 % p = n % p  ------ (1)

Let x be the modulo square root. We can write,
  (x * x) ≡ n mod p
  (x * x) ≡ n^(p+1)/2  [Using (1) given above]
  (x * x) ≡ n^(2i + 2) [Replacing p = 4*i + 3]
        x ≡ ±n^(i + 1)  [Taking Square root of both sides]
        x ≡ ±n^(p + 1)/4 [Putting 4*i + 3 = p or i = (p-3)/4]
*/
