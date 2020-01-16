/*
Given an array of n numbers, find LCM of it.
Input : {1, 2, 8, 3}
Output : 24

We know
LCM = a*b / gcd(a,b)
The above relation only holds for two numbers
LCM = a*b*c / gcd(a,b,c)
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
    int lcm;
    for(int i=0;i<n;i++)
        lcm=lcm*a[i]/gcd(lcm,a[i]);
    cout<<"LCM is : "<<lcm;
    return 0;
}
