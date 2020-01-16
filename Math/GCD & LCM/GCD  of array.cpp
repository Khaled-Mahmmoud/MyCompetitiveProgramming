/*
Given an array of numbers, find GCD of the array elements
Input  : arr[] = {2, 4, 6, 8}
Output : 2
The GCD of three or more numbers equals the product of the prime factors common to all the numbers
but it can also be calculated by repeatedly taking the GCDs of pairs of numbers

gcd(a, b, c) = gcd(a, gcd(b, c)) 
             = gcd(gcd(a, b), c) 
             = gcd(gcd(a, c), b)
*/
#include <bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    int g=0;
    for(int i=0;i<n;i++)
        g=gcd(g,a[i]);
    cout<<"GCD is : "<<g;
    return 0;
}
