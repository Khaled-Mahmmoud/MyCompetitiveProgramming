```cpp
/*
<without repetition>
order is important (Permutation)
How? The rule of product.
First step we do n choices, in second step, we are allowed only n-1, third n-2
Then we have n * n-1 * n-2 ... 1 ways = p(n) = n!
what if we need arrangement of r elements. Same way: n x (n-1) x (n-2) x .....x (n- r + 1)
nPr = P(n,r) = n! / (n-r)!
nPr(circle) = nPr/r

order is not important (Combination)
nCr = C(n,r) = n! / (n-r)! * r!
That is it: P(n, r) = C(n, r) * r!
nCr = nC(n – r)

<with repetition>
order is important (Permutation)
n^r

order is not important ()
Select a combination of three letters frome the set A,B,C,D and E.
combinations can include {A,B,C} , {B,D,E} , {C,D,B}

what if we allow repeated elements such as AABC, BBBCCD?
the number of such combination = ncr(n+r-1,r) = (n+r-1)! / (n-1)! * r!
*/

ll perm(ll n,ll r)
{
    if(r>n)
        return 0;
    ll ans = 1;
    for(int i=n;i>=n-r+1;i--)
        ans = (ans*i)%mod;
    return ans;
}

/*
// Permutation with repetition  
How many permutations of AAABB?
Imagine it as A1A2A3B1B2 (where A1=A2=A3, B1=B2)
Now think in permutation: A1A2B1A3B2
This is as same as A3A1B1A2B2
Specifically, fixing all except As, 3! of it are same!
Now, assume on of these 3! is fixed but B’s are changed
2! of them are same e.g. A3A1B1A2B2 = A3A1B2A2B1
Then 3! * 2! items are duplicate => 5! / (3! * 2!)
P(n) = n!..but P(n, [c1, c2...cm]) = n!/(c1!c2!...cm!) where c1 is repeated char
*/

/*
Some Rules of Binomial coefficients
nC0 + nC1 + nC2 + ……. + nCn-1 + nCn = 2^n
nC0 + nC2 + nC4 + nC6 + nC8 + ……… = 2^(n-1)
nC0^2 + nC1^2 + nC2^2 + .... + nCn-1^2 + nCn^2 = 2nCn
*/

/*
Catalan numbers are a sequence of natural numbers that occurs in many interesting counting problems 
1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862
catalan(n) = nCr(2n,n) / (n+1)
*/
/*
<Inclusion Exclusion>
Most of counting involves duplicate counting issue [count item more than once].
Inclusion Exclusion principle is a generic sum rule to solve that
|A ∪ B ∪ C| = |A| + |B| + |C| - |A ∩ B| - |A ∩ C| - |B ∩ C| + |A ∩ B ∩ C|
Enumerate all subsets, Compute each one intersection If odd subset add (include) it If even subset subtract (exclude) it.

How many integers in {1,2 ...,100} are divisible by 2, 3, 5 or 7?
F(2) + F(3) + F(5) + F(7) - F(2, 3) - F(2, 5) - F(2, 7) - F(3, 5) - F(3, 7) - F(5, 7) + F(2, 3, 5) 
+ F(2, 3, 7) + F(2, 5, 7) + F(3, 5, 7) - F(2, 3, 5, 7)
*/
int primes[4] = {2,3,5,7};
int n = 100,ans;
vector<int>sub;
void inc_exe(int idx = 0)
{
    if(idx==4)
    {
        if(sub.empty())
            return;
        int d = 1;
        for(int i=0;i<sub.size();i++)
            d *= sub[i];
        if(sub.size()&1)
            ans += n/d;
        else
            ans -= n/d;
        return;
    }
    sub.push_back(primes[idx]);
    inc_exe(idx+1);
    sub.pop_back();
    inc_exe(idx+1);
}
int main()
{
    subset();
    cout<<ans;
    return 0;
}
// Complexity : O(2^n)
/*
<The Division Rule>
A food table with 3 chairs. Given 3 persons, in how many ways we can seat them? 6 ways
Wrong! 123 same as 231 same as 312 [by making 1 shift]. so answer is 6 / 3 = 2 .. or generally n! / n = n-1!,
nPr(circle) = nPr/r
In an 8x8 chess, how many ways to put 2 rocks, with no shared rows or columns?
First piece has 64 choices.. then 1 row & 1 col are blocked
So we have 7x7= 49 choices for 2nd rock. Total 64 * 49.
Wrong! (0,0), (1,1) same as (1,1), (0,0)
Symmetry of each 2 rocks. Answer: 64 * 49 / 2

<Stars and bars>
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

<Pigeonhole Principle>
Assume we have N=5 boxes and M=6 apples, Distribute apples in boxes in whatever way, There must be 1 box with at least 2 apples.
What if we have 13 apples? one box will have at least ⌈13/5⌉ = 3 apples. Generally: ⌈N/M⌉ per a box.

Prove: Among any N positive integers, there exists 2 whose difference is divisible by N-1.
Recall: |A-B| % X = 0 IFF A%X = B%X. So, let’s compute % N-1?
Then we have N-1 values, each in range [0 - N-2].  But, we have N numbers, then at least one mode will be duplicate. 
Then, their difference must be divisible by N-1. 
N = 5 and A = {2, 3, 5, 7, 8} Compute A % 4 = {2, 3, 1, 3, 0}, 5 numbers, with values [0 - 3].
Pick 2 with same mode -> 3 is repeated mode. Then, (3, 7) are the answer

Prove: For any N positive integers, find the sum of subset of them is divisible N.
Compute Accum array % N. Accum[i] = {A[0] + A[1]...A[i]} % N
If any Accum[i] = 0, we are done. Otherwise, we have N values in [0 - N-1].
Then 2 positions will have same mode. Then getting numbers between them is answer.
Let A represents array of numbers N = 5 and A = {2, 4, 8, 2, 7}, Accumulate: B = {2, 6, 14, 16, 23}
Mode 5: C = {2, 1, 4, 1, 3} Any zeros? (if yes then A[0]+A[1]...A[i] where C[i] % N = 0. ) 
No..remaining 4 values spread on 5 index...one of them must be repeated. 2nd and 4th have mode 1.
Then range from 3rd till 4th is answer: 8, 2
*/
/*
<Permutations Cycles>
For vector {0, 1, 2} -> we have 3! = 6

Idx: 0		0 1 2		-> Sorted	     	{			Block of length 2! = 2 
Idx: 1		0 2 1					}                                      (n-1)!
      
Idx: 2		1 0 2
Idx: 3		1 2 0

Idx: 4		2 0 1
Idx: 5		2 1 0		-> Reversed
*/
// Given a permutation length, what is the ith permutation ?
vector<int> nthPerm(int len, int nth) 
{
    vector<int> id(len), perm(len);
    for(int i=0;i<len;i++)
    id[i] = i;
    for (int i = len - 1; i >= 0; --i)
    {
        int p = nth / Fact[i];
	perm[len - i - 1] = id[p];
	id.erase(id.begin() + p);
	nth %= Fact[i];
    }
    return perm;
}
// Given a permutation, what is its index ?
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
/*
Building Committee of 7 persons out of 8 women and 9 men?
No more conditions? C(17, 7)
Has Exactly 5 women? C(8, 5) * C(9, 2)
Has at least 5 women? w >= 5
Convert inequality to loop: W(5) + W(6) + W(7)
C(8, 5) * C(9, 2)+C(8, 6) * C(9, 1)+C(8, 7) * C(9, 0)
Has at least 0 women? Useless => C(17, 7)
Has at least 1 women? C(17, 7) - C(9, 7)

Combination concept can be related to:
Exact / At most / At least
Atmost(k) = SUM Exact(i) where i = [0-k]
Exact(k) = Atmost(k) - Atmost(k-1)
In range (start, end) =
SUM Exact(i) where i = [start-end]
Atmost(end) - Atmost(start-1)
Atleast(start) - Atleast(end+1)

A group consists of 4 girls and 7 boys.
In how many ways can a team of 5 members be selected, the team has at least one boy and 2 girls ?
2 girls +3 boys ⇒ 4C2 * 7C3
3 girls +2 boys ⇒ 4C3 * 7C2
4 girls +1 boy ⇒ 4C4 * 7C1
Total number of ways = 4C2 * 7C3 + 4C3 * 7C2 + 4C4 * 7C1 = 210+84+7 = 301
*/
```
