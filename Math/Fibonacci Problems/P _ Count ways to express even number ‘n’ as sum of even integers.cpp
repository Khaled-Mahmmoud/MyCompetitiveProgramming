Count ways to express even number ‘n’ as sum of even integers
Given an positive even integer ‘n’. Count total number of ways to express ‘n’ as sum of even positive integers
Output the answer in modulo 109 + 7

Input: 6
Output: 4

Explanation
There are only four ways to write 6
as sum of even integers:
1. 2 + 2 + 2
2. 2 + 4
3. 4 + 2
4. 6
Input: 8
Output: 8
Recommended: Please try your approach on {IDE} first, before moving on to the solution.
Approach is to find pattern or recursive function whichever is possible
The approach would be the same as already discussed in “Count ways to express ‘n’ as sum of odd integers“
Here the given number is even that means even sum can only be achieved by adding the (n-2)th number as two times
We can notice that (by taking some examples) adding a 2 to a number doubles the count
Let the total number of ways to write ‘n’ be ways(n). The value of ‘ways(n)’ can be written by formula as follows:



ways(n) = ways(n-2) + ways(n-2)
ways(n) = 2 * ways(n-2)

ways(2) = 1 = 20
ways(4) = 2 = 21
ways(6) = 4 = 22
ways(8) = 8 = 23
''
''
''
ways(2 * n) = 2n-1

Replace n by (m / 2)
=> ways(m) = 2^(m/2 - 1)
