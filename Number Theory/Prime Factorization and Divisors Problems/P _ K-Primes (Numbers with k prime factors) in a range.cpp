/*

Given three integers A, B and K. We need to find no. of K-prime numbers in the range [A, B]
A number is called K-prime if it has exactly K distinct prime factors.

Input : A = 4, B = 10, K = 2.
Output : 6 10
Given range is [4, 5, 6, 7, 8, 9, 10].
From the above range 6 and 10 have 2 distinct 
prime factors, 6 = 3*2; 10 = 5*2.

Input : A = 14, B = 18, K = 2.
Output : 14 15 18
Range = [14, 15].
Both 14, 15 and 18 have 2 distinct prime factors
14 = 7*2, 15 = 3*5 and 18 = 2*3*3

A simple solution is to traverse through given range. For every element of the range, find its prime factors
Finally print all those numbers whose prime factors are k.

An efficient solution is to use Sieve Of Eratosthenes Algorithm

prime[n] = {true};
for (int p=2; p*p<=n; p++)
{
   // If prime[p] is not changed, then 
   // it is a prime
   if (prime[p] == true)
   {
      // Update all multiples of p
      for (int i=p*2; i<=n; i += p)
         prime[i] = false;
    }
}
 
If we observe the above algorithm clearly it has a property of iterating through all the multiples 
of prime numbers less than N So the number of times the algorithm marks a number not prime is equal 
to the number of prime factors of that number , To achieve this, maintain an array called marked and 
increase the count of a number every time when it is marked as not prime by the algorithm
And in the next step, we iterate through all the numbers in the range [A, B] and increase 
our count of k-prime numbers if marked[number] == K


*/

void printKPFNums(int A, int B, int K) 
{  
    int p_factors[B+1] = { 0 }; 
    for (int p = 2; p <= B; p++)  
        if (p_factors[p] == 0)  
            for (int i = p; i <= B; i += p)  
                p_factors[i]++; 
  
    for (int i = A; i <= B; i++)  
        if (p_factors[i] == K) 
            cout << i << " "; 
} 
