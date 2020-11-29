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

We have discussed a O(r) approach to find binomial coefficient nCr

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

1) Number of expressions containing n pairs of parentheses which are correctly matched
For n = 3, possible expressions are ((())), ()(()), ()()(), (())(), (()())

2) Number of possible Binary Search Trees with n keys.
```
For n  = 1, there is only one tree

   1

For n  = 2, there are two trees

   2      1
  /        \  
 1          2

For n  = 3, there are five trees

    3      1           2          3      1
   /        \         /  \       /        \
  2          2       1    3     1          3
 /            \                  \        /
1              3                  2      2
```

3) Given a number N . The task is to Find Number of Permutations of 1 to N such that no Three Terms forms Increasing Subsequence
for n = 3,Valid permutations : 132, 213, 231, 312 and 321 and not 123
for n = 4 Valid permutations : 1432, 2143, 2413, 2431, 3142, 3214, 3241, 3412, 3421, 4132, 4213, 4231, 4312 and 4321

4) Number of full binary trees with n+1 leaves or 2n+1 vertices. (root has two degree)
```
For n  = 0, there is only one tree

   o

For n  = 1, there are two trees

    o   
  /   \  
 o     o

For n  = 2, there are five trees

      o             o           
    /   \         /   \     
   o      o      o     o     
 /   \               /   \        
o      o            o     o      
```

5) Number of binary trees with n+1 vertices.
```
   o      o         o         o           o
   |      |       /   \     /   \      /  | \
   o      o      o     o   o     o    o   o  o
   |    /   \    |               |
   o   o     o   o               o
   |
   o
```

6) Number of ways to insert n pairs of parentheses in a word of n+1 letters
e.g., for n=2 there are 2 ways: ((ab)c) or (a(bc))
For n=3 there are 5 ways, ((ab)(cd)), (((ab)c)d), ((a(bc))d), (a((bc)d)), (a(b(cd)))


7) Number of Dyck words of length 2n. A Dyck word is a string consisting of n X’s and n Y’s such that no prefix segment of the string has more Y’s than X’s.  For example, the following are the Dyck words of length 6: XXXYYY     XYXXYY     XYXYXY     XXYYXY     XXYXYY.


