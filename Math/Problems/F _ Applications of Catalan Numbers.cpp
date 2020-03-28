/*

The number of paths on a rectangular grid from bottom left to top right
i.e., (n-1, 0) to (0, n-1) that lies above the main diagonal

Number of expressions containing n pairs of parentheses which are correctly matched
For n = 3, possible expressions are ((())), ()(()), ()()(), (())(), (()())

Count the number of possible Binary Search Trees with n keys 
(countBST(n)) = Catalan number Cn = (2n)! / ((n + 1)! * n!)

for N = 2, there are 2 unique BSTs
     1               2  
      \            /
       2         1

for N = 3, there are 5 possible BSTs
  1              3        3         2      1
    \           /        /       /    \      \
     3        2         1       1      3      2
    /       /             \                     \
   2      1                2                      3

Total number of possible Binary Trees with n different keys (countBT(n)) = countBST(n) * n!

