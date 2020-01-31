/*
Given a number N
the task is to find out maximum sum of distinct numbers such that the Least Common Multiple of all these numbers is N.

Input  : N = 12
Output : 28
Maximum sum which we can achieve is,
1 + 2 + 3 + 4 + 6 + 12 = 28

Solution :
We can solve this problem by observing some cases, As N needs to be LCM of all numbers
all of them will be divisors of N but because a number can be taken only once in sum, all taken numbers should be distinct
The idea is to take every divisor of N once in sum to maximize the result
*/
int getsum(int n)
{
    int sum=0;
    for(int i=1;i*i<=n;i++)
    {
        if(n%i)
            continue;
        sum += i;
        if(i*i==n)
            continue;
        sum += n/i;
    }
    return sum;
}
