/*
Given GCD G and LCM L, find number of possible pairs (a, b)
We need to find number of possible pairs (a, b) 
such that GCD(a, b) is equal to given G and LCM(a, b) is equal to given L

Input : G = 2, L = 12
Output : 4
Explanation : There are 4 possible pairs : (2, 12), (4, 6), (6, 4), (12, 2)
Input : G = 3, L = 6
Output : 2
Explanation : There are 2 possible pairs : (3, 6), (6, 3)

Solution 1 (Simple):
Since a and b both will be less than or equal to lcm(a, b) L
so we try all possible pairs that have product equal to L * G
Note that product of a and b is same as product of gcd(a, b) and lcm(a, b), a*b = G*L

*/

int countPairs(int G, int L) 
{ 
    int count = 0; 
    int p = G*L; 
    for (int a=1; a<=L; a++) 
        if (!(p%a) && gcd(a, p/a)==G) 
            count++; 
    return count; 
} 
// Time Complexity: O( L * log(L) )

/*
Solution 2 (Efficient):

We know that G * L = a * b 
Since G is gcd(a, b), both a and b will have G as its factor
Let A = a/G
Let B = b/G

From above definitions of A and B, GCD of A and B must be 1.
We can write, a = G * A, b = G * B

G * L = G * A * G * B
A * B = L / G

Now, we need to find all possible pairs of (A, B)
such that gcd(A, B) = 1 and A*B = L/G

Let say p1, p2, ..., pk are prime factors of L/G.
Then if p1 is present in prime factorization of A 
then p1 can't be present in prime factorization of B because gcd(A, B) = 1
Therefore each prime factor pi will be present in either A or B
Hence total possible ways to divide all prime 
factors among A and B is 2^k, where L/G has k distinct prime factors.

Example let G = 2 , L = 12
A * B = L/G 
A * B = 6
Primes(6) = {2,3}
  A      B     A    B     a    b
(2,3)    ()    6    1     12   2
 (2)    (3)    2    3     4    6
 (3)    (2)    3    2     6    4
 ()    (2,3)   1    6     2    12
 there 4 pairs
*/


int totalPrimeFactors(int n) 
{ 
    int count = 0; 
    if (!(n%2)) 
    { 
        count++; 
        while (!(n%2)) 
            n /= 2; 
    } 
    for (int i = 3; i*i <= n; i = i+2) 
    { 
        if (!(n%i)) 
        { 
            count++; 
            while (!(n%i)) 
                n /= i; 
        } 
    } 
    if (n > 2) 
        count++; 
  
    return count; 
}  
int countPairs(int G, int L) 
{ 
    if (L % G != 0) 
       return 0; 
    int div = L/G; 
    return (1 << totalPrimeFactors(div)); 
} 
// Time Complexity : O(sqrt(L/G) * log(L/G)).
