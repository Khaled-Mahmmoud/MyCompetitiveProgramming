/*
Given a number N
the task is to find out maximum sum of distinct numbers such that the Least Common Multiple of all these numbers is N

Input  : N = 12
Output : 28
Maximum sum which we can achieve is,
1 + 2 + 3 + 4 + 6 + 12 = 28

Solution :
As the LCM of all the numbers is N
So all the numbers must be the divisors of N and all the numbers are distinct so answer must be the sum of all the divisors of N
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
