# KMP (Knuth-Morris-Pratt)

** KMP is Pattern Matching**

Given a string S, pattern P, find all P in S , S = abababcabaddd, P = aba

2 matches: ab**aba**bc**aba**ddd

**Brute Force**

Let: n = length(S) and m = length(P)

Try every location in S, and check of it matches P For i = 0   to   n-m

Let t  = S[i, …i+m-1]	=> Substring from S. If equal(P, t) Display, we found a match

Time Complexity  O(nm)
