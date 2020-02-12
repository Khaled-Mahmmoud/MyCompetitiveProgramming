/*

Euler’s criterion (Check if square root under modulo p exists)
Given a number ‘n’ and a prime p, find if square root of n under modulo p exists or not
A number x is square root of n under modulo p if (x*x)%p = n%p.
Examples :
Input:   n = 2, p = 5
Output:  false
There doesn't exist a number x such that 
(x*x)%5 is 2
Input:   n = 2, p = 7
Output:  true
There exists a number x such that (x*x)%7 is
2.  The number is 3.
A Naive Method is to try every number x where x varies from 2 to p-1
For every x, check if (x * x) % p is equal to n % p
Time Complexity of this method is O(p).
Euler’s criterion states that
Square root of n under modulo p exists if and only if
n^(p-1)/2 % p = 1
Here square root of n exists means is, there exist
an integer x such that (x * x) % p = 1

*/

int power(int x, int y, int p) 
{ 
    int res = 1;     
    x = x % p; 
    while (y) 
    { 
        if (y & 1) 
            res = (res*x) % p; 
        y = y>>1; 
        x = (x*x) % p; 
    } 
    return res; 
} 
bool squareRootExists(int n, int p) 
{ 
    if (power(n, (p-1)/2, p) == 1) 
       return true; 
    return false; 
} 
int main() 
{ 
   int p = 7; 
   int n = 2; 
   squareRootExists(n, p)? cout << "Yes": cout << "No"; 
   return 0; 
} 

/*

How does this work?
If p is a prime, then it must be an odd number and (p-1) 
must be an even, i.e., (p-1)/2 must be an integer.
Suppose a square root of n under modulo p exists, then
there must exist an integer x such that,
      x2 % p = n % p 
or, 
     x2 ? n mod p
Raising both sides to power (p-1)/2,
      (x2)(p-1)/2 ? n(p-1)/2 mod p           
      xp-1 ? n(p-1)/2 mod p
Since p is a prime, from Fermet's theorem, we can say that 
   xp-1 ? 1 mod p
Therefore,
  n(p-1)/2 ? 1 mod p  
  
Time complexity of this Euler Criterion based method is O(Log p)

*/
