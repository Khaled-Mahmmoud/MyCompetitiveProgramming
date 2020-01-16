Extended Euclidean algorithm also finds integer coefficients x and y such that
  a * x + b * y = gcd(a, b) 
  /*
Input: a = 30, b = 20
Output: gcd = 10
        x = 1, y = -1
(Note that 30*1 + 20*(-1) = 10)

Input: a = 35, b = 15
Output: gcd = 5
        x = 1, y = -2
(Note that 35*1 + 15*(-2) = 5)
*/
#include <bits/stdc++.h>
using namespace std;
int x,y,z;
void gcd(int a,int b)
{
    if(!b)
    {
        x=1;
        y=0;
        z=a;
    }
    else
    {
        gcd(b,a%b);
        int temp = x;
        x = y;
        y = temp - y * (a/b);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int a,b;cin>>a>>b;
    gcd(a,b);
    cout<<"X is : "<<x<<"    Y is : "<<y;
    return 0;
}
