/*

Given a positive integers ‘q’ and ‘n’. For each query ‘q’ find whether a number ‘n’ have exactly four distinct divisors or not
If the number have exactly four divisors then print ‘Yes’ else ‘No’.1 <= q, n <= 10^6

Input:
2
10
12
Output:
Yes
No

Explanation:
For 1st query, n = 10 has exactly four divisor i.e., 1, 2, 5, 10.
For 2nd query, n = 12 has exactly six divisor i.e., 1, 2, 3, 4, 6, 12.

Simple approach is to count factors by generating all divisors of a number by using this approach
after that check whether the count of all factors are equal to ‘4’ or not. Time complexity of this approach is O(sqrt(n)).

Better approach is to use Number theory. For a number to be have four factors, it must satisfy the following conditions
1) If number is a product of exactly two prime numbers(say p, q). Thus we can assure that it will have four factors i.e, 1, p, q, n
2) If a number is cube of a prime number (or cube root of the number is prime). For example, let’s say n = 8, cube root = 2 that
means ‘8’ can be written as 2*2*2 hence four factors are:- 1, 2, 4 and 8.
We can use sieve of Eratosthenes such that we will pre-calculate all the prime factor from 1 to 10^6
Now we will mark all numbers which are the product of two prime number by using two ‘for loops’ i.e, mark[p * q] =true.
Meanwhile we will also mark all numbers(cube root) by taking cube of number i.e, mark[p * p * p] = true.
After that we can easily answer each query in O(1) time.

*/

const int N = 1e6; 
vector<bool> fourDiv(N,false);  
void fourDistinctFactors() 
{ 
    vector<bool> primeAll(N,true);   
    for (int p = 2; p * p <= N; p++)
    { 
        if (primeAll[p] == true)  
              for (int i = p * 2; i <= N; i += p) 
                primeAll[i] = false; 
    } 
    vector<int> prime; 
    for (int p = 2; p <= N; p++) 
        if (primeAll[p]) 
            prime.push_back(p);   
    for (int i = 0; i < prime.size(); ++i)
    { 
        int p = prime[i]; 
        if (1LL * p * p * p <= N) 
            fourDiv[p * p * p] = true; 
  
        for (int j = i + 1; j < prime.size(); ++j)
        { 
            int q = prime[j]; 
            if (1LL * p * q > N) 
                break;
            fourDiv[p * q] = true; 
        } 
    } 
}  
int main() 
{ 
    fourDistinctFactors(); 
  
    int num = 10; 
    if (fourDiv[num]) 
        cout << "Yes\n"; 
    else
        cout << "No\n"; 
  
    num = 12; 
    if (fourDiv[num]) 
        cout << "Yes\n"; 
    else
        cout << "No\n"; 
  
    return 0; 
} 
// Time complexity: O(1) for every query
