```
The number of ways to put n identical objects into k labeled boxes is ncr(n+r-1,r-1)
E.g. we can represent with ★|★★| |★★ the following situation: in the first box is one object, 
in the second box are two objects, the third one is empty and in the last box are two objects.
This is one way of dividing 5 objects into 4 boxes.

Number of non-negative integer sums
You want to count the number of solution of the equation X1 + X2 + ⋯ + Xk = n with Xi ≥ 0.
the solution 1 + 3 + 0 = 4 for n = 4, k = 3 can be represented using ★|★★★|.the solution is ncr(n+r−1,r-1).

Number of lower-bound integer sums
we want to count the number of solutions for the equation x1 + x2 + ⋯ + xk = n with xi ≥ ai.
After substituting x′i = xi - ai we receive the modified equation (x′1+ai) + (x′2+ai) + ⋯ + (x′k+ak) = n 
x′1 + x′2 + ⋯ + x′k = n − a1 − a2 − ⋯ − ak with x′i ≥ 0. and again can apply the stars and bars theorem.
```
