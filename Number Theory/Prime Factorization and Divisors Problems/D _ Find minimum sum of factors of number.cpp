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
int isprime(int n)
{
    if(n==1)return 0;
    if(n%2==0)
    return n==2;
    for(int i=3;i<=sqrt(n);i+=2)
    {
        if(n%i==0)
        return 0;
    }
    return 1;
}
int findMinSum(int num) 
{ 
    if(isprime(num))
    return num+1;
    
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
/*
input : 11       
output : 12 (not 11 because 11 * 1 = 11 + 1 = 12)
*/
