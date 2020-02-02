/*
Find politeness of a number
Given an integer n. Find politeness of number n
Politeness of a number is defined as the number of ways it can be expressed as the sum of consecutive integers

Input: n = 15
Output: 3
Explanation:
There are only three ways to express
15 as sum of consecutive integers i.e.,
15 = 1 + 2 + 3 + 4 + 5
15 = 4 + 5 + 6
15 = 7 + 8
Hence answer is 3

Input: n = 9;
Output:  2
There are two ways of representation:
9 = 2 + 3 + 4
9 = 4 + 5
Naive approach is to run a loop one inside another and find the sum of every consecutive integers up to n
Time complexity of this approach will be O(n^2) which will not be sufficient for large value of n

Efficient approach is to use factorization. We factorize the number n and count the number of odd factors
Total number of odd factors (except 1) is equal to politeness of the number


In general if a number can be represented as a^p * b^q * c^r … where a, b, c, … are prime factors of n
If a = 2 (even) then discard it and count total number of odd factors which can be written 
as [(q + 1) * (r + 1) * …] – 1 (Here 1 is subtracted because single term in representation is not allowed)

How does above formula work? The fact is, if a number is expressed as a^p * b^q * c^r … where a, b, c, … are prime factors of n
then number of divisors is (p+1)*(q+1)*(r+1) ……To simplify, let there be one factor and number is expressed as a^p
Divisors are 1, a, a^2, …. a^p . The count of divisors is p+1
Now let us take a slightly more complicated case a^p b^p
The divisors are :
1, a, a^2, …. a^p
b, ba, ba^2, …. ba^p
b^2, b^2a, b^2a^2, …. b^2a^p
…………….
…………….
b^q, b^qa, b^qa^2, …. b^qa^p

The count of above terms is (p+1)*(q+1). Similarly, we can prove for more prime factors.

Illustration : For n = 90, decomposition of prime factors will be as follows:-
=> 90 = 2 * 32 * 51. The power of odd prime factors 3, 5 are 2 and 1 respectively
Apply above formula as: (2 + 1) * (1 + 1) -1 = 5. Hence 5 will be the answer. We can crosscheck it
All odd factors are 3, 5, 9, 15 and 45

*/


int countOddPrimeFactors(int n) 
{ 
    int result = 1; 
    while (n % 2 == 0) 
        n /= 2; 
    for (int i = 3; i * i <= n; i += 2)
    { 
        int divCount = 0; 
        while (n % i == 0)
        { 
            n /= i; 
            ++divCount; 
        } 
  
        result *= divCount + 1; 
    } 
    if (n > 2) 
        result *= 2; 
  
    return result; 
} 
  
int politness(int n) 
{ 
    return countOddPrimeFactors(n) - 1; 
} 
int main() 
{ 
    int n = 90; 
    cout << "Politness of " << n << " = "<< politness(n) << "\n"; 
  
    n = 15; 
    cout << "Politness of " << n << " = "<< politness(n) << "\n"; 
    return 0; 
} 
/*
Output:
Politness of 90 = 5
Politness of 15 = 3
Time complexity: O(sqrt(n))
*/
