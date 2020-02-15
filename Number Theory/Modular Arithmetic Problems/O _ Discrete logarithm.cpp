Discrete logarithm
Given three integers a, b and m. Find an integer k such that 
a^k = b (mod m) then k is discrete logarithm of m
where a and m are relatively prime. If it is not possible for any k to satisfy this relation, print -1

Input: 2 3 5
Output: 3

Explanation:
a = 2, b = 3, m = 5

The value which satisfies the above equation
is 3, because 

=> 23 = 2 * 2 * 2 = 8
=> 23 (mod 5) = 8 (mod 5) 
=> 3
which is equal to b i.e., 3

Input: 3 7 11
Output: -1

A Naive approach is to run a loop from 0 to m to cover all possible values of k and check for which value of k
the above relation satisfies. If all the values of k exhausted, print -1. Time complexity of thuis approach is O(m)

