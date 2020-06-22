/*

Sum of Fibonacci Numbers
Given a number positive number n, find value of f0 + f1 + f2 + …. + fn where fi indicates i’th Fibonacci number.
Remember that f0 = 0, f1 = 1, f2 = 1, f3 = 2, f4 = 3, f5 = 5, …

Input  : n = 3
Output : 4
Explanation : 0 + 1 + 1 + 2  = 4

Input  :  n = 4
Output :  7
Explanation : 0 + 1 + 1 + 2 + 3  = 7
 

Method 1 (O(n))
Brute Force approach is pretty straight forward, find all the Fibonacci numbers till f(n) and then add them up.

*/

int calculateSum(int n) 
{ 
    if (n <= 0) 
       return 0; 
  
    int fibo[n+1]; 
    fibo[0] = 0, fibo[1] = 1; 

    int sum = fibo[0] + fibo[1]; 
  
    for (int i=2; i<=n; i++) 
    { 
        fibo[i] = fibo[i-1]+fibo[i-2]; 
        sum += fibo[i]; 
    } 
  
    return sum; 
} 
  
/*

Method 2 (O(Log n))
The idea is to find relationship between the sum of Fibonacci numbers and n’th Fibonacci number.

F(i) refers to the i’th Fibonacci number.
S(i) refers to sum of Fibonacci numbers till F(i),

We can rewrite the relation F(n+1) = F(n) + F(n-1) as below
F(n-1)    = F(n+1)  -  F(n)

Similarly,
F(n-2)    = F(n)    -  F(n-1)
.          .           .
.          .             .
.          .             .
F(0)      = F(2)    -  F(1)
-------------------------------
Adding all the equations, on left side, we have
F(0) + F(1) + … F(n-1) which is S(n-1).

Therefore,
S(n-1) = F(n+1) – F(1)
S(n-1) = F(n+1) – 1
S(n) = F(n+2) – 1 —-(1)

In order to find S(n), simply calculate the (n+2)’th Fibonacci number and subtract 1 from the result

*/

F(n) can be evaluated in O(log n) time Matrices

int fib(int n)
{
    if(n <= 1)
    return n;
    
    matrix transition = zero(2,2);
    transition[0][1] = transition[1][0] = transition[1][1] = 1;
    transition = power(transition , n);
    return transition[0][1];
}
int calculateSum(int n) 
{ 
    return fib(n+2) - 1; 
} 
int main() 
{ 
    int n = 4; 
    cout << "Sum of Fibonacci numbers is : "<< calculateSum(n) << endl; 
    return 0; 
} 
