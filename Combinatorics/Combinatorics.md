# Elementary

Any Task 

# without repetition

### order is important (Permutation)

**Permutation** : Permutations of set of objects: is an arrangement of those objects into a particular order.

For example, if we have two elements A and B, then there are two possible arrangements, AB and BA

E.g. for set{1,2,3}, namely (1,2,3), (1,3,2), (2,1,3), (2,3,1), (3,1,2), and (3,2,1) -> 3!	-> n!

How? The rule of product.

First step we do n choices, in second step, we are allowed only n-1, third n-2

Then we have n * n-1 * n-2 ... 1 ways =	p(n) = n!

what if we need arrangement of r elements. Same way: n x (n-1) x (n-2) x .....x (n- r + 1)

`nPr = P(n,r) = n! / (n-r)!`
                 
Ex. you forgot your password but you know it consists of 3 distinct letters of this set A={a,b,e,i,p} so number of ways = 5 * 4 * 3 is 5P3 = 5! / (5-3)!


Or think in another way: it is how many combination of r elements, and for each element do r! permutations

That is it: P(n, r) = C(n, r) * r!

### order is not important (Combination)

**Combination** : It is the different selections of a given number of elements.

For example, if we have two elements A and B, then there is only one way select two items, we select both of them AB

`nCr = C(n,r) = n! / (n-r)! * r!`

Ex. Picking a team of 3 people from a group of 10 = 10C3 = 10! / (10-3)! * 3!
 
 `nCr = nC(n – r)`

For permutation, AB and BA are two different things but for selection, AB and BA are same

Let's do some evaluations

C(1000, 2) = 499500

C(1000, 999) = C(1000, 1) = 1000

C(66, 33) = 7219428434016265740

C(68, 34) = Overflow in long long

# with repetition

### order is important (Permutation)

**n^r***

Ex. you forgot your password but you know it consists of 3 letters of this set A={a,b,e,i,p} so number of ways = 5 * 5 * 5 is 5^3

First step we do n choices, in second step, we are allowed n, third n.

Then we have n * n * n ... n ways =	n^r

### order is not important (Combination)

Select a combination of three letters frome the set A,B,C,D and E.

combinations can include {A,B,C} , {B,D,E} , {D,B,A}

the number of combination = nCr(5,3) = 5! / 2! * 3! = 10

ten combinations are ABC, BCD, CDE, ABD, BCE, ABE, ACD, BDE, ACE, ADE

**what if we allow repeated elements such as AAB, BCB?**

the number of such combination = `ncr(n+k-1,k) = (n+k-1)! / (n-1)! * k!`
