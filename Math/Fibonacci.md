```cpp
// Fn = Fn-1 + Fn-2, F0 = 0, F1 = 1
int fib(int n) 
{ 
  int a = 0, b = 1, c, i; 
  if( n == 0) 
    return a; 
  for (i = 2; i <= n; i++) 
  { 
     c = a + b; 
     a = b; 
     b = c; 
  } 
  return b; 
} 
/*
  Matrix Approach : Observe
  
  0 1     0 1 ^ 1    1 1
  0 0  x  1 1     =  0 0
  
  0 1     0 1 ^ 2    1 2
  0 0  x  1 1     =  0 0
  
  0 1     0 1 ^ 3    2 3
  0 0  x  1 1     =  0 0
  
  0 1     0 1 ^ 4    3 5
  0 0  x  1 1     =  0 0

   Matrix  Approach  :   Generally
   a b       0 1          b a+b
   c d   x   1 1    =     d c+d
  Initial   Transition    Updated
  Matrix    Matrix        Matrix
*/
ll fibonacciMatrix(ll n)
{
    if(n <= 1)
        return n;
    matrix transition = zero(2, 2);
    transition[0][1] = transition[1][0] = transition[1][1] = 1;
    transition = power(transition, n - 1);
    matrix Initial = zero(2, 2);
    Initial[0][1] = 1;
    Initial = multiply(Initial, transition);
    return Initial[0][1];
}
// O(logn) 
// first row in initial matrix same as first row in transition matrix
// So instead : initial x transition^(n-1) , we use transition^n
ll fibonacciMatrix(ll n)
{
    if(n <= 1)
        return n;
    matrix transition = zero(2, 2);
    transition[0][1] = transition[1][0] = transition[1][1] = 1;
    transition = power(transition, n);
    return transition[0][1];
}
/*
In Fibonacci , F(n) depends on 2 terms only ; F(n-1) + F(n-2) 
So we have 2 base cases Then define 2x2 matrix, Fill first row with bases and Others zeros.
Let F[0][0] = 0 , F[0][1] = 1
0 1
0 0
Imaginary Sequence
F[0] = 1 , F[1] = 3 , F[2] = 4
F[n] = 2 * F[n-3] + F[n-2] + 4 * F[n-1]
we depend on 3 terms , construct 3 x 3 and fill with base cases
1 3 4
0 0 0
0 0 0
Now we need to prepare column values We know that initial matrix first row 1 3 4 (base case) and first row in updated matrix
after 1 step 3 4 x that is first 2 columns just shift 2 values , 3rd column only do calculation 2 * F[n-3] + F[n-2] - 4 * F[n-1]
0  0  2
1  0  1
0  1 -4
*/
int fmat(int n)
{
    if(n==0) return 1;
    if(n==1) return 3;
    if(n==2) return 4;
    matrix initial = zero(3,3);
    initial[0][0] = 1 , initial[0][1] = 3 , initial[0][2] = 4;
    matrix transition = zero(3,3);
    transition[1][0] = 1;
    transition[2][1] = 1;
    transition[0][2] = 2 ; transition[1][2] = 1 ; transition[2][2] = -4 ;
    transition = power(transition , n-2);
    initial = multiply(initial,transition);
    return initial[0][2];
} 
/*
The Leonardo numbers are a sequence of numbers given by the recurrence:
                   1              if n = 0
  L(n)   =         1              if n = 1
              L(n-1)+L(n-2)+1     if n > 1
The Leonardo numbers are related to the Fibonacci numbers by below relation L(n) = 2 * F(n+1) - 1 , n >= 0
*/
```
