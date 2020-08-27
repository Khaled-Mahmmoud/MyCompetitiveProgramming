# Elementary

Any Task 

### with repetition

n^r

Ex. you have 5 pens and you want to write 3 tasks so number of ways is 5^3 

Ex. you forgot your password but you know it consists of 3 letters of this set A={a,b,e,i,p} so number of ways is 5^3

### without repetition

**order is important** (Permutation)

**Permutation** : It is the different arrangements of a given number of elements taken one by one, or some, or all at a time

For example, if we have two elements A and B, then there are two possible arrangements, AB and BA

`nPr = P(n,r) = n! / (n-r)!`
                 
Ex. you forgot your password but you know it consists of 3 distinct letters of this set A={a,b,e,i,p} so number of ways is 5P3 = 5! / (5-3)!

**order is not important** (Combination)

**Combination** : It is the different selections of a given number of elements taken one by one, or some, or all at a time

For example, if we have two elements A and B, then there is only one way select two items, we select both of them

`nCr = C(n,r) = n! / (n-r)! * r!`

Ex. Picking a team of 3 people from a group of 10 = 10C3 = 10! / (10-3)! * 3!
 
 `nCr = nC(n – r)`

NOTE : In the same example, we have different cases for permutation and combination

For permutation, AB and BA are two different things but for selection, AB and BA are same

Permutations: of set of objects: is an arrangement of those objects into a particular order.

E.g. for set{1,2,3}, namely (1,2,3), (1,3,2), (2,1,3), (2,3,1), (3,1,2), and (3,2,1) -> 3!	-> n!

How? The rule of product

First step we do n choices, in 2nd step, we are allowed only n-1, third n-2

Then we have n * n-1 * n-2 ... 1 ways =		p(n) = n!

what if we need arrangement of r elements. Same way: n x (n-1) x (n-2) x .....x (n- r + 1)

P(n, r) = n! / (n-r)!

Or think in another way: it is how many combination of r elements, and for each element do r! permutations

That is it: P(n, r) = C(n, r) * r!

what about Permutations with Repetition? Then always could select what do you want pr(n) = n^n

Combinations: The number of ways of picking r unordered elements out of n elements
order does not matter

How to calculate?

P(n, r) = C(n, r) * r!

n! / (n-r)! = C(n, r) * r!

C(n, r) = n! / ( (n-r)!  * r!)

Also writing a recurrence is easy

Let's do some evaluations

C(1000, 2) = 499500

C(1000, 999) = C(1000, 1) = 1000

C(66, 33) = 7219428434016265740

C(68, 34) = Overflow in long long
