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
<The Division Rule>
A food table with 3 chairs. Given 3 persons, in how many ways we can seat them? 6 ways
Wrong! 123 same as 231 same as 312 [by making 1 shift]. so answer is 6 / 3 = 2 .. or generally n! / n = n-1!,
nPr(circle) = nPr/r
In an 8x8 chess, how many ways to put 2 rocks, with no shared rows or columns?
First piece has 64 choices.. then 1 row & 1 col are blocked
So we have 7x7= 49 choices for 2nd rock. Total 64 * 49.
Wrong! (0,0), (1,1) same as (1,1), (0,0)
Symmetry of each 2 rocks. Answer: 64 * 49 / 2

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
