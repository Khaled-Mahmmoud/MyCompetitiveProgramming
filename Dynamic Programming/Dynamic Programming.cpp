/*
Dynamic Programming is mainly an optimization over plain recursion . Wherever we see a recursive solution that has repeated calls for 
same inputs , we can optimize it using Dynamic Programming . The idea is to simply store the results of subproblems, so that we do not
have to re-compute them when needed later. This simple optimization reduces time complexities from exponential to polynomial.
For example, if we write simple recursive solution for Fibonacci Numbers, we get exponential time complexity and if we optimize it 
by storing solutions of subproblems, time complexity reduces to polynomial (linear)
*/



//  Recursion : Exponentail

int fib(int n)
{
    if(n<2)return n;
    return fib(n-1) + fib(n-2);
}



//  Dynamic Programming : Polynomial

vector<int>dp(1e7);
int fib(int n)
{
    if(n<2)return n;
    if(dp[n])return dp[n];
    return dp[n] = fib(n-1) + fib(n-2);
}

/*
**************  Tabulation vs Memoization   ***************
There are following two different ways to store the values so that the values of a sub-problem can be reused
Here, will discuss two patterns of solving DP problem:

Tabulation   : Bottom Up
Memoization  : Top Down


*/
