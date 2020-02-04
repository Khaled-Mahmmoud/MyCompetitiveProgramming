/*
Divisors of n-square that are not divisors of n
Given an positive large integer n. Count the number of positive divisors of n2 which
are not divisible by any divisor of n(1 <= n <= 1012).

Input: 6
Output: 5
Explanation
Total divisors of 62 are 9 i.e.,
1, 2, 3, 4, 6, 9, 12, 18, 36
Total divisors of '6' are 4,
1, 2, 3, 6
Total divisor of '36' which are not
divisible by divisors of '6' are
'5' i.e., 4, 9, 12, 18, 36

Input: 8
Output: 3
Simple approach is to traverse for every divisor of n2 and count only those divisors which are not divisor of ‘n’
Time complexity of this approach is O(n).

Efficient approach is to use prime factorization to count total divisors of n2. A number ‘n’ can be represented 
as product of primes p1^k1 p2^k2 ... pn^kn



Let n = p1^k1 p2^k2 for some primes p1 and p2.
Squaring both the sides
 n^2 = p1^2k1 p2^2k2
Total factors of n2 will be,
 (2k1+1)(2k2+1)

Total factors of 'n' will be,
 (k1+1)(k2+1) 

Difference between the two gives the required

*/
