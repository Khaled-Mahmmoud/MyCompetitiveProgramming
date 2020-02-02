/*
Find minimum sum of factors of number
Given a number, find minimum sum of its factors.

Input : 12
Output : 7
Explanation: 
Following are different ways to factorize 12 and
sum of factors in different ways.
12 = 12 * 1 = 12 + 1 = 13
12 = 2 * 6 = 2 + 6 = 8
12 = 3 * 4 = 3 + 4 = 7
12 = 2 * 2 * 3 = 2 + 2 + 3 = 7
Therefore minimum sum is 7

Input : 105
Output : 15

To minimize sum, we must factorize factors as long as possible. With this process, we prime factors
So to find minimum sum of product of number, we find sum of prime factors of product.

*/

int findMinSum(int num) 
{ 
    int sum = 0; 
    for (int i = 2; i * i <= num; i++) 
    { 
        while (num % i == 0) 
        { 
            sum += i; 
            num /= i; 
        } 
    } 
    if(num > 1)
    sum += num; 
    return sum; 
} 
