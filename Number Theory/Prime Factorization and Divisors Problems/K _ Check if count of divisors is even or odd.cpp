/*
Check if count of divisors is even or odd
Given a number “n”, find its total number of divisors are even or odd.

Examples :

Input  : n = 10      
Output : Even

Input:  n = 100
Output: Odd

Input:  n = 125
Output: Even

A naive approach would be to find all the divisors and then see if the total number of divisors is even or odd
Time complexity for such a solution would be O(sqrt(n))

Efficient Solution:
We can observe that the number of divisors is odd only in case of perfect squares
Hence the best solution would be to check if the given number is perfect square or not
If it’s a perfect square, then the number of divisors would be odd, else it’d be even
Time complexity for such a solution would be O(1)

*/

void countDivisors(int n) 
{ 
    int root_n = sqrt(n); 
    
    if (root_n * root_n == n) 
        printf("Odd\n"); 
    else
        printf("Even\n"); 
} 
