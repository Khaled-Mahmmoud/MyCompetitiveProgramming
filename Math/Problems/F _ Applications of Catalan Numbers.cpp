/*

1) Number of paths on a rectangular grid from bottom left to top right
i.e., (n-1, 0) to (0, n-1) that lies above the main diagonal

2) Number of expressions containing n pairs of parentheses which are correctly matched
For n = 3, possible expressions are ((())), ()(()), ()()(), (())(), (()())

3) Number of possible Binary Search Trees with n keys 
(countBST(n)) = Catalan number Cn = (2n)! / ((n + 1)! * n!)

for N = 2, there are 2 unique BSTs
     1               2  
      \            /
       2         1

for N = 3, there are 5 possible BSTs

    3      1           2           3       1
   /        \         /  \        /         \
  2          2       1    3       1          3
 /            \                    \        /
1              3                    2      2

Total number of possible Binary Trees with n different keys (countBT(n)) = countBST(n) * n!

4) Given a convex polygon with n+2 sides . The task is to calculate the number of ways 
in which triangles can be formed by connecting vertices with non-crossing line segments

Input: n = 1
Output: 1
It is already a triangle so it can only be formed in 1 way.

Input: n = 2
Output: 2
It can be cut into 2 triangles by using either pair of opposite vertices

5) Given a number N . Number of Permutations of 1 to N such that no Three Terms forms Increasing Subsequence
Input : N = 3
Output : 5
Valid permutations : 132, 213, 231, 312 and 321 and not 123

Input : N = 4
Output : 14
Valid permutations : 1432, 2143, 2413, 2431, 3142, 3214, 3241, 3412, 3421, 4132, 4213, 4231, 4312 and 4321

Solution : find the n’th Catalan Number. First few Catalan numbers are 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862


