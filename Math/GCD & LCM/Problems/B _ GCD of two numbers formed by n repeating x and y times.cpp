/*
Given three positive integer n, x, y. The task is to print Greatest Common Divisor of numbers formed by n repeating x times 
and number formed by n repeating y times.    0 <= n, x, y <= 10^9

Input : n = 123, x = 2, y = 3.
Output : 123
Number formed are 123123 and 123123123.
Greatest Common Divisor of 123123 and
123123123 is 123.


Solution : GCD(f(n, x), f(n, y)) = f(n, GCD(x, y))
*/

#include <bits/stdc++.h>
#define ll long long
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
    int n,x,y;
    cin>>n>>x>>y;
    int g=gcd(x,y);
    while(g--)
    cout<<n;
    return 0;
}
