// prime numbers : numbers which are only divisible by themselves and one
#include <bits/stdc++.h>
#define ll long long
#define N 50000000
using namespace std;
bool isprime(int n)
{
     if (n < 2)
        return 0;
     if (!(n%2))
        return (n == 2);
     for (int i = 3; i * i <= n; i += 2)
        if (!(n%i))
            return 0;
     return 1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    if(isprime(n))
        cout<<"prime";
    else 
        cout<<"not prime";
    return 0;
}
