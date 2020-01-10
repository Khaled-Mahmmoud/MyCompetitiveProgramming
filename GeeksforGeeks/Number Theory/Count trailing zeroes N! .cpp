
Given an integer n, write a function that returns count of trailing zeroes in N!

Input: n = 5
Output: 1 
Factorial of 5 is 120 which has one trailing 0.

Input: n = 20
Output: 4
Factorial of 20 is 2432902008176640000 which has
4 trailing zeroes

A trailing zero is always produced by prime factors 2 and 5 . If we can count the number of 5s and 2s , our task is done
n = 5  : There is one 5s and three 2s in prime factors of 5! (5*(2*2)*3*2*1) . So count of trailing 0s is 1
n = 11 : There are two 5s and eight 2s in prime factors of 11! (11*(5*2)*(2*2*2)*7*(2*3)*5*(2*2)*3*2*1). So count of trailing 0s is 2

We can easily observe that the number of 2s in prime factors is always more than or equal to the number of 5s
So if we count 5s in prime factors, we are done

How to count total number of 5s in prime factors of n!? A simple way is to calculate floor(n/5)
For example, 7! has one 5, 10! has two 5s. It is done yet
Numbers like 25, 125, etc have more than expected because 
5  ===>>> 5*1
10 ===>>> 5*2
15 ===>>> 5*3
20 ===>>> 5*4
25 ===>>> 5*5
125 ===>>> 5*5*5

int countzero(int n)
{
    int cnt=0;
    while(n)
    {
        cnt+=n/5;
        n/=5;
    }
}
