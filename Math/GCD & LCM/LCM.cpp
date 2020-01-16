// LCM (Least Common Multiple) 
#include <bits/stdc++.h>
#define ll long long
#define N 50000000
using namespace std;
int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int lcm(int a,int b)
{
    return a*b/gcd(a,b);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int a,b;cin>>a>>b;
    cout<<lcm(a,b);
    return 0;
}
//           GCD(LCM (x, y), LCM (x, z)) = LCM(x, GCD(y, z))
//gengeral   GCD(f(x,y),f(x,z)) = f(x,GCD(y,z))   where f is fuction
