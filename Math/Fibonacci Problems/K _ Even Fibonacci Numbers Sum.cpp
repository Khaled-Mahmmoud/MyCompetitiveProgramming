/*

Even Fibonacci Numbers Sum
Given a limit, find the sum of all the even-valued terms in the Fibonacci sequence below given limit.

The first few terms of Fibonacci Numbers are, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233 ,… (Even numbers are highlighted).

Input : limit = 8
Output : 10
Explanation : 2 + 8 = 10

Input : limit = 400;
Output : 188.
Explanation : 2 + 8 + 34 + 144 = 188.

A simple solution is to iterate through all Fibonacci numbers while the next number is less than or equal to given limit
For every number, check if it is even. If the number is even, add it to the result.

An efficient solution is based on the below recursive formula for even Fibonacci Numbers

Recurrence for Even Fibonacci sequence is:
     EFn = 4EFn-1 + EFn-2
with seed values
     EF0 = 0 and EF1 = 2.

EFn represents n'th term in Even Fibonacci sequence.

So while iterating over Fibonacci numbers, we only generate even Fibonacci numbers

*/


int evenFibSum(int limit) 
{ 
    if (limit < 2) 
        return 0; 
    long long int ef1 = 0, ef2 = 2; 
    long long int sum = ef1 + ef2; 
    
    while (ef2 <= limit) 
    { 
        long long int ef3 = 4*ef2 + ef1; 
        if (ef3 > limit) 
            break; 
        ef1 = ef2; 
        ef2 = ef3; 
        sum += ef2; 
    } 
  
    return sum; 
} 
int main() 
{ 
    int limit = 400; 
    cout << evenFibSum(limit); 
    return 0; 
} 
