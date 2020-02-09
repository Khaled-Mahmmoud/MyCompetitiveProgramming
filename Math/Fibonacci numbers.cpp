/*

The Fibonacci numbers are the numbers in the following integer sequence.
0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ……..

In mathematical terms, the sequence Fn of Fibonacci numbers is defined by the recurrence relation



    Fn = Fn-1 + Fn-2
with seed values   F0 = 0 and F1 = 1

*/

// Method 1 ( Use recursion ) 
// A simple method that is a direct recursive implementation mathematical recurrence relation given above
int fib(int n) 
{ 
    if (n < 2) 
        return n; 
    return fib(n-1) + fib(n-2); 
} 

// Method 2 ( Use Dynamic Programming )
// We can avoid the repeated work done is the method 1 by storing the Fibonacci numbers calculated so far.

int fib(int n) 
{ 
  int f[n+1];   
  f[0] = 0; 
  f[1] = 1; 
  
  for (int i = 2; i <= n; i++) 
      f[i] = f[i-1] + f[i-2]; 
    
  return f[n]; 
} 

// Method 3 ( Space Optimized Method 2 )
// We can optimize the space used in method 2 by storing the previous two numbers only 
// because that is all we need to get the next Fibonacci number in series.
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

Method 4 (O(Log n) Time)
Below is one more interesting recurrence formula that can be used to find n’th Fibonacci Number in O(Log n) time

If n is even then k = n/2:
F(n) = [2*F(k-1) + F(k)]*F(k)

If n is odd then k = (n + 1)/2
F(n) = F(k)*F(k) + F(k-1)*F(k-1)

*/
vector<ll> f(10000);
ll fib(ll n)
{
    if(n<2)
    return n;
    if(n==2)
        return 1;
    if(f[n])
        return f[n];
    ll k = (n&1) ? (n+1)/2 : n/2 ;
    return f[n] =( (n&1) ? (fib(k)*fib(k) + fib(k-1)*fib(k-1)) : (2*fib(k-1)+fib(k))*fib(k) )%mod;

}
// Complexity : O(log(n))
