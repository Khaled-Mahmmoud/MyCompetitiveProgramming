# Permutations Cycles

```
For vector {0, 1, 2} -> we have 3! = 6

Idx: 0		0 1 2		-> Sorted	     	{			Block of length 2! = 2
Idx: 1		0 2 1					    	}

Idx: 2		1 0 2
Idx: 3		1 2 0

Idx: 4		2 0 1
Idx: 5		2 1 0		-> Reversed

For vector {0, 1, 2, 3} -> we have 4! = 24

Idx: 0		0 1 2 3 					{
Idx: 1		0 1 3 2 					.
Idx: 2		0 2 1 3 					.			Block Start with Zeros. Its Length 3! = 6
Idx: 3		0 2 3 1 					.
Idx: 4		0 3 1 2 					.
Idx: 5		0 3 2 1 					}

Idx: 6		1 0 2 3
Idx: 7		1 0 3 2
Idx: 8		1 2 0 3
Idx: 9		1 2 3 0
Idx: 10		1 3 0 2
Idx: 11		1 3 2 0

Idx: 12		2 0 1 3
Idx: 13		2 0 3 1
Idx: 14		2 1 0 3
Idx: 15		2 1 3 0
Idx: 16		2 3 0 1
Idx: 17		2 3 1 0

Idx: 18		3 0 1 2
Idx: 19		3 0 2 1
Idx: 20		3 1 0 2
Idx: 21		3 1 2 0
Idx: 22		3 2 0 1
Idx: 23		3 2 1 0
```
**How to iteratively generate Permutations ?**

```cpp
void Permutation(int a[],int n)
{
    do
    {
        for(int i=0;i<n;i++)
            cout<<a[i]<<' ';
        cout<<'\n';
    }
    while(next_permutation(a,a+n));
}
int main() 
{ 
    int a[] = {0, 1, 2}; 
    int n = sizeof(a)/sizeof(a[0]); 
    Permutation(a, n); 
    return 0; 
} 
```
Complexity : O(!n)

number of purmutaions = !n / !(n-r) where r = n , it's !n / !0 = !n

Given a permutation length, what is the ith permutation ?

```cpp
vector<int> nthPerm(int len, int nth) 
{
    vector<int> identity(len), perm(len);
    for(int i=0;i<len;i++)
    identity[i] = i;
    for (int i = len - 1; i >= 0; --i)
    {
        int p = nth / Fact[i];
	perm[len - i - 1] = identity[p];
	identity.erase(identity.begin() + p);
	nth %= Fact[i];
    }
    return perm;
}
```

Given a permutation, what is its index ?
```cpp
int PermToIndex(vector<int> perm)
{
    int idx = 0;
    int n = perm.size();
    for (int i = 0; i < n; ++i)
    {
        // Remove first, and Renumber the remaining elements to remove gaps
        idx += Fact[n-1-i] * perm[i];
        for(int j = i+1; j < n; j++)
           perm[j] -= perm[j] > perm[i];
    }
    return idx;
}
```

### Permutations Application

Say we have a permutation: 	2 0 1 3
	
Applying a permutation on other, aka multiplication, means to map its values according to the permutation.
		
So 2 0 1 3 MEANS:

```
0 -map-> 2 
1 -map-> 0	     
2 -map-> 1
3 -map-> 3
```
		
Then
	
(0 1 2 3) * (2 0 1 3) = 2 0 1 3
		
(2 3 1 0) * (2 0 1 3) = 1 3 0 2
		
(3 2 0 1) * (2 0 1 3) = 3 1 2 0
		
(3 2 0 1) * (2 0 1 3) * (2 0 1 3) = (3 1 2 0) * (2 0 1 3) = 3 0 1 2
		
Permutation Multiplication is associative, like numbers Multiplication, e.g. doesn't matter what to apply first
	
For Numbers: 3 * 5 * 7 = (3 * 5) * 7 = 3 * (5 * 7)
		
Then for Some Permutations: P1 * p2 * p3 * p4 = P1 * (p2 * p3 * p4) = (P1 * p2) * (p3 * p4) and so on.
		
Permutation Multiplication is NOT Commutative, like numbers subtraction, e.g. order matter
	
For numbers: 3-5 ~= 5-3
		
Then for Permutations = (0 1 2 3) * (2 0 1 3) ~= (2 0 1 3) * (0 1 2 3)
		
P^k means apply Permutation k times, e.g. (3 2 0 1) * (2 0 1 3) * (2 0 1 3) is written as: p1 * p2^2
	
Say we are given P1 and P2, and we would like to evaluate p1 * p2^k, where k = 10^9?!!
	
Check above, Permutation is similar in that for Numbers.
		
E.g. how do you calculate a^16 ? we use divide and conquer: a^16 = a^8 * a^8. Calculate a^8 and square it! SAME for Permutation

```cpp
typedef vector<int> perm;
perm pow(perm inp, perm apply, int k)
{
    if(k == 0) 
        return inp;
    if(k == 1)
        return applyPerm(inp, apply);	
	
    if(k%2 == 1)	
    cur = applyPerm(cur, perm);
	
    perm = pow(inp, apply, k/2);
    cur = applyPerm(cur, cur);
	
    return cur;
}
```

Order? N for applyPerm * logk for depth -> O(nlogk)

Could we do better? YES, a bit more code, but we can do it! Using Permutation Cycle Notation.


#### Permutation Cycle Notation

From Abstract Algebra, we know that Permutation is set of dis-joint cycles. How
In other words, if you followed which value replace other, you create a cycle.
```
Let Say we have permutation p: 1 2 3 0

0 -> 1
1 -> 2
2 -> 3
3 -> 0	// End of Cycle

What about 3 2 1 0 4
	0 -> 3
	3 -> 0	// End of Even Cycle
	1 -> 2
	2 -> 1	// End of Even Cycle
	4 -> 4 // End of ODD Cycle, with one element
What about 2 0 1 4 3
	0 -> 2
	2 -> 1
	1 -> 0	// End of ODD Cycle
	3 -> 4
	4 -> 3	// End of Even Cycle

Then, any permutation is set of cycles -> this is CLUE for many permutation problems
Let's pick a one cycle permutation, and see its application: 3 0 1 2
        0 -> 3		3 -> 2		2 -> 1		1 -> 0
	
let's apply it many times over a perm p: 0 1 2 3

(0 1 2 3) * (3 0 1 2)^1 = 3 0 1 2
(0 1 2 3) * (3 0 1 2)^2 = 2 3 0 1	Notice, the rotation of the cycle
(0 1 2 3) * (3 0 1 2)^3 = 1 2 3 0
(0 1 2 3) * (3 0 1 2)^4 = 0 1 2 3	We backed again!

Think in that, a cycle of length N, if applied N times, it backs to is origin!

And applying a cycle       N+1 	= 1 	time
			   N+2 	= 2 	times
			  2N+1	= 1 	time
			    M   = M%N 	time
```
Let's think again in our problem: how to solve p1 * p2^k	and k = 10^9? Simply,

1) Generate Permutation Cycles (aka disjoint cycle decomposition) -> O(n)
2) For each cycle length M, apply cycle M%N times, which is just a rotation
3) Cleverly, implement all in O(n)
