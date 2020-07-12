# Program for nth Catalan Number

Catalan numbers are a sequence of natural numbers that occurs in many interesting counting problems like following
The first few Catalan numbers for n = 0, 1, 2, 3, … are `1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, …`

 `Catalan Number = (2n)! / (n!*(n + 1)!)`
 Catalan numbers satisfy the following recursive formula
`C0 = 1 , C(n) = sum(i=0,n-1) Ci Cn-i-1 , n >= 1`

```cpp
int catalan[10000];
int catalan(int n) 
{ 
    if (n <= 1) return 1; 
    if(catalan[i])return catalan[i];
    int res = 0; 
    for (int i=0; i<n; i++) 
        res += catalan(i)*catalan(n-i-1); 
  
    return catalan[n] = res; 
} 
```
Complexity : O(n^2)

**Using Binomial Coefficient**

We can also use the below formula to find nth catalan number in O(n) time
`catalan(n) = nCr(2n,n) / (n+1)`
We have discussed a O(n) approach to find binomial coefficient nCr

```cpp
int binomialCoeff(int n,int r)
{
    if (n < r)
        return 0;

    if (r == 0)
        return 1;

    return n * binomialCoeff(n - 1, r - 1) / r;
}
int catalan(int n)
{
    return binomialCoeff(2*n, n) / (n+1);
}
int main()
{
    for(int i=0;i<10;i++)
        cout<<catalan(i)<<' ';
	return 0;
}
```
# Applications of Catalan Numbers

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

4) Given a [convex polygon](https://github.com/Khaled-Mahmmoud/MyCompetitiveProgramming/blob/master/img/Math/convex-concave.jpg) with n+2 sides . The task is to calculate the number of ways 
in which triangles can be formed by connecting vertices with non-crossing line segments

Input: n = 1
Output: 1
It is already a triangle so it can only be formed in 1 way.

Input: n = 2
Output: 2
It can be cut into 2 triangles by using either pair of opposite vertices

5) Given a number N . The task is to Find Number of Permutations of 1 to N such that no Three Terms forms Increasing Subsequence
Input : N = 3
Output : 5
Valid permutations : 132, 213, 231, 312 and 321 and not 123

Input : N = 4
Output : 14
Valid permutations : 1432, 2143, 2413, 2431, 3142, 3214, 3241, 3412, 3421, 4132, 4213, 4231, 4312 and 4321

Solution : find the n’th Catalan Number. First few Catalan numbers are 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862

6) Number of full binary trees with n+1 leaves

for n = 0  -->>  O 

for n = 1  -->>   O      
                /   \   
               O     O

for n = 2  -->>   O              O
                /   \          /   \
               O     O        O     O
             /   \                /   \
            O     O              O     O
            
7) Enumeration of Binary Trees
A Binary Tree is labeled if every node is assigned a label and a Binary Tree is unlabeled if nodes are not assigned any label

Below two are considered same unlabeled trees
    o                 o
  /   \             /   \ 
 o     o           o     o 

Below two are considered different labeled trees
    A                C
  /   \             /  \ 
 B     C           A    B 
How many different Unlabeled Binary Trees can be there with n nodes?

For n  = 1, there is only one tree
   o

For n  = 2, there are two trees
   o      o
  /        \  
 o          o

For n  = 3, there are five trees
    o      o           o         o      o
   /        \         /  \      /         \
  o          o       o    o     o          o
 /            \                  \        /
o              o                  o      o

Number of Labeled Tees = (Number of unlabeled trees) * n!
                       = [(2n)! / (n+1)!n!]  × n!
                       
8) Number of ways to insert n pairs of parentheses in a word of n+1 letters
e.g., for n=2 there are 2 ways: ((ab)c) or (a(bc))
For n=3 there are 5 ways, ((ab)(cd)), (((ab)c)d), ((a(bc))d), (a((bc)d)), (a(b(cd)))

9) Number of noncrossing partitions of the set {1, …, 2n} in which every block is of size 2
A partition is noncrossing if and only if in its planar diagram, the blocks are disjoint (i.e. don’t cross)

Consider a circle with 4 points
    1
2        3
    4
In above diagram, there are two 
non-crossing ways to connect
{{1, 2}, {3, 4}} and {{1, 3}, {2, 4}}.

Note that {{2, 3}, {1, 4}} is invalid
as it would cause a cross

