# Dynamic Programming

is mainly an optimization over plain recursion . Wherever we see a recursive solution that has 
repeated calls for same inputs , we can optimize it using Dynamic Programming . The idea is to simply store
the results of subproblems, so that we do not have to re-compute them when needed later. This simple optimization 
reduces time complexities from exponential to polynomial.
For example, if we write simple recursive solution for Fibonacci Numbers, we get exponential time complexity 
and if we optimize it 
by storing solutions of subproblems, time complexity reduces to polynomial (linear)

Recursion : Exponentail


```
int fib(int n)
{
    if(n<2)return n;
    return fib(n-1) + fib(n-2);
}
```

Dynamic Programming : Polynomial
```
vector<int>dp(1e7);
int fib(int n)
{
    if(n<2)return n;
    if(dp[n])return dp[n];
    return dp[n] = fib(n-1) + fib(n-2);
}
```


### Tabulation vs Memoization

There are following two different ways to store the values so that the values of a sub-problem can be reused
Here, will discuss two patterns of solving DP problem:

1) Tabulation   : Bottom Up
2) Memoization  : Top Down


**Tabulation Method – Bottom Up Dynamic Programming**
                      
As the name itself suggests starting from the bottom and cumulating answers to the top
Let’s describe a state for our DP problem to be dp[x] with dp[0] as base state and dp[n] as our destination state. 
So, we need to find the value of destination state i.e dp[n].
If we start our transition from our base state i.e dp[0] and follow our state transition relation to reach 
our destination state dp[n] . we call it Bottom Up approach as it is quite clear that we started our transition
from the bottom base state and reached the top most desired state

Now, Why do we call it tabulation method?
To know this let’s first write some code to calculate the factorial of a number using bottom up approach
Once, again as our general procedure to solve a DP we first define a state. 
In this case, we define a state as dp[x], where dp[x] is to find the factorial of x
Now, it is quite obvious that dp[x+1] = dp[x] * (x+1)

```
int dp[MAXN];

int dp[0] = 1;  // base case
for (int i = 1; i< =n; i++)
{
    dp[i] = dp[i-1] * i;
}
```

**Memoization Method – Top Down Dynamic Programming** 
Here, we start our journey from the top most destination state and compute its answer by taking in count 
the values of states that can reach the destination state, till we reach the bottom most base state.

Once again, let’s write the code for the factorial problem in the top-down fashion

```
int dp[MAXN];
int solve(int x)
{
    if (x==0)
        return 1;
    if (dp[x])
        return dp[x];
    return dp[x] = x * solve(x-1);
}
```

# Dynamic Programming 

is an algorithmic paradigm that solves a given complex problem by breaking it into subproblems 
and stores the results of subproblems to avoid computing the same results again. Following are the two main 
properties of a problem that suggests that the given problem can be solved using Dynamic programming

1) Overlapping Subproblems
2) Optimal Substructure

**Overlapping Subproblems**
Like Divide and Conquer, Dynamic Programming combines solutions to sub-problems. Dynamic Programming is mainly used
when solutions  of same subproblems are needed again and again. In dynamic programming, computed solutions to 
subproblems are stored in a table so that these don’t have to be recomputed. So Dynamic Programming is not useful
when there are no common (overlapping)  subproblems because there is no point storing the solutions if they are not
needed again. For example, Binary Search doesn’t have common subproblems. If we take an example of following recursive
program for Fibonacci Numbers, there are many subproblems which are solved again and again
```
int fib(int n) 
{ 
   if ( n <= 1 ) 
      return n; 
   return fib(n-1) + fib(n-2); 
}
```
[Recursion tree](https://github.com/Khaled-Mahmmoud/MyCompetitiveProgramming/blob/master/img/Dynamic%20Programming/Recursion%20tree%20fib(5).png) for execution of fib(5)

We can see that the function fib(3) is being called 2 times. If we would have stored the value of fib(3)
then instead of computing it  again, we could have reused the old stored value.

**Optimal Substructure**

A given problems has Optimal Substructure Property if optimal solution of the given problem can be obtained by 
using optimal solutions of its subproblems

For example, the Shortest Path problem has following optimal substructure property:
If a node x lies in the shortest path from a source node u to destination node v then the shortest path 
from u to v is combination of shortest path from u to x and shortest path from x to v .The standard All Pair
Shortest Path algorithms like Floyd–Warshall and Bellman–Ford are typical examples of Dynamic Programming

On the other hand, the Longest Path problem doesn’t have the Optimal Substructure property. Here by Longest Path 
we mean longest  simple path (path without cycle) between two nodes. Consider the following unweighted graph given 
in the CLRS book. There are two [longest paths](https://github.com/Khaled-Mahmmoud/MyCompetitiveProgramming/blob/master/img/Dynamic%20Programming/longest%20path%20.png) from q to t: q→r→t and q→s→t. Unlike shortest paths, these longest
paths do not have the optimal substructure propertym, For example, the longest path q→r→t is not a combination of 
longest path from q to r and longest path from r to t, because the longest path from q to r is q→s→t→r and 
the longest path from r to t is r→q→s→t.    

Dynamic Programming most typical cases : **Minimization**, **Maximization**, **Counting**. but could have **adhoc** usages.

Subset Style : 01011011101 means pick OR leave item.

Other Subset Style : 0401502 means pick item once or more OR leave item

Consecutive Ranges Style : (ab)(cde)(fg)(h)

Nested Ranges Style : (((a)((b)(c)))(d)((ef)(g)))

