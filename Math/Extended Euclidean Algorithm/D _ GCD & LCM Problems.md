### GCD of array

Given an array of numbers, find GCD of the array elements.
  
The GCD of three or more numbers equals the product of the prime factors common to all the numbers
but it can also be calculated by repeatedly taking the GCDs of pairs of numbers.

gcd(a, b, c) = gcd(a, gcd(b, c))  = gcd(gcd(a, b), c) = gcd(gcd(a, c), b)

```cpp
int gcd(int a,int b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
int main()
{
    int n;cin>>n;int a[n];
    for(int i=0;i<n;i++)
      cin>>a[i];
    int g=0;
    for(int i=0;i<n;i++)
        g=gcd(g,a[i]);
    cout<<"GCD is : "<<g;
    return 0;
}
Complexity : nlog(max(a[i]))
```

### LCM of array

Given an array of n numbers, find LCM of it.
    
We know LCM = a*b / gcd(a,b)
  
The above relation only holds for two numbers LCM != a*b*c / gcd(a,b,c)
```cpp
int gcd(int a,int b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
int main()
{
    int n;cin>>n;int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    int lcm = a[0];
    for(int i=1;i<n;i++)
        lcm=lcm*a[i]/gcd(lcm,a[i]);
    cout<<"LCM is : "<<lcm;
    return 0;
}
Complexity : nlog(max(a[i]))
```

### GCD of two numbers when one of them can be very large

Given two numbers ‘a’ and ‘b’ such that (0 <= a <= 10^12 and b <= b < 10^250). Find the GCD of two given numbers
                  
```cpp
ll gcd(ll a,ll b)
{
    if(!b)return a;
    return gcd(b,a%b);
}
ll reduce(int a,string b)
{
    ll mod=0;
    for(int i=0;b[i];i++)
        mod=(mod*10+(b[i]-'0'))%a;
    return mod;
}
int main()
{
    ll a;string b;cin>>a>>b;
    int c = reduce(a,b);
    cout<<gcd(a,c);
    return 0;
}
```

### Product of given N fractions 

Given the Numerator and Denominator of N fractions. The task is to find the product of N fraction and output the answer in reduced form.
        
Input : N = 3, num[] = { 1, 2, 5 }, den[] = { 2, 1, 6 }

Output : 5/6
        
Product of 1/2 * 2/1 * 5/6 is 10/12.
        
Reduced form of 10/12 is 5/6.
        
The idea is to 

1) find the product of Numerator in a variable, say n1
2) find the product of Denominator in another variable, say n2
3) find the Greatest Common Divisor of n1 and n2 
4) divide the n1 and n2 by the calculated GCD
```cpp
#include <bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
    if(!b)return a;
    return gcd(b,a%b);
}
int main()
{
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
```
