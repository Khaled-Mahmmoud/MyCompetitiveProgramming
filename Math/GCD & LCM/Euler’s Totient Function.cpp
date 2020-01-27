/*
totative of a positive integer n is an integer k (0 < k <= n) , such that n and k are coprimes
n = 8 , then k = 3 can be a totative
n = 12 , then k = 5 can be a totative

Euler’s Totient function(n) ? for an input n is count of numbers in {1, 2, 3, …, n} that are relatively prime to n
i.e., the numbers whose GCD (Greatest Common Divisor) with n is 1

?(1) = 1  
gcd(1, 1) is 1

?(2) = 1
gcd(1, 2) is 1, but gcd(2, 2) is 2.

?(3) = 2
gcd(1, 3) is 1 and gcd(2, 3) is 1

?(4) = 2
gcd(1, 4) is 1 and gcd(3, 4) is 1

?(5) = 4
gcd(1, 5) is 1, gcd(2, 5) is 1, 
gcd(3, 5) is 1 and gcd(4, 5) is 1

?(6) = 2
gcd(1, 6) is 1 and gcd(5, 6) is 1

*/
