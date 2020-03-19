/*
Given the Numerator and Denominator of N fractions. The task is to find the product of N fraction and output the answer in reduced form
Input : N = 3
        num[] = { 1, 2, 5 }
        den[] = { 2, 1, 6 }
Output : 5/6
Product of 1/2 * 2/1 * 5/6 is 10/12.
Reduced form of 10/12 is 5/6.
The idea is to 
1) find the product of Numerator in a variable, say n1
2) find the product of Denominator in another variable, say n2
3) find the Greatest Common Divisor of n1 and n2 
4) divide the n1 and n2 by the calculated GCD
*/

#include <bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
    if(!b)return a;
    return gcd(b,a%b);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;int a[n],b[n];
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>b[i];
    int n1=1,n2=1;
    for(int i=0;i<n;i++)
    {
        n1*=a[i];
        n2*=b[i];
    }
    int g=gcd(n1,n2);
    n1/=g;n2/=g;
    cout<<n1<<'/'<<n2;
    return 0;
}
