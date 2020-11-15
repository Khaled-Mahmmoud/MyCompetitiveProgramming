# Count ways to reach the n'th stair

There are n stairs, a person standing at the bottom wants to reach the top
The person can climb either 1 stair or 2 stairs at a time. Count the number of ways, the person can reach the top
Consider the example shown in diagram. The value of n is 3. There are 3 ways to reach the top
The diagram is taken from Easier Fibonacci puzzles

Input: n = 1, Output: 1, There is only one way to climb 1 stair

Input: n = 2, Output: 2, There are two ways: (1, 1) and (2)

Input: n = 4, Output: 5, (1, 1, 1, 1), (1, 1, 2), (2, 1, 1), (1, 2, 1), (2, 2)

```cpp
vector<int>dp(100009,0);
int solve(int n)
{
    if(!n)return 1;
    if(n<0)return 0;
    if(dp[n])return dp[n];
    return dp[n] = solve(n-1) + solve(n-2);
}
```
Complexity : O(n)

We can easily find recursive nature in above problem
The person can reach n’th stair from either (n-1)’th stair or from (n-2)’th stair
Let the total number of ways to reach n’t stair be ‘ways(n)’. The value of ‘ways(n)’ can be written as following.

ways(n) = ways(n-1) + ways(n-2)
    
The above expression is actually the expression for Fibonacci numbers, but there is one thing to notice
the value of ways(n) is equal to fibonacci(n+1)

ways(1) = fib(2) = 1
ways(2) = fib(3) = 2
ways(3) = fib(4) = 3

```cpp
int fib(int n) 
{ 
   if (n <= 1) 
      return n; 
   return fib(n-1) + fib(n-2); 
} 
int countWays(int s) 
{ 
    return fib(s + 1); 
} 
```
The time complexity of the above implementation is exponential. It can be optimized to work in O(Logn) time using matrices
