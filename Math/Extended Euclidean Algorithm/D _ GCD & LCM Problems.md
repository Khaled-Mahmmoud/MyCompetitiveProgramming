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
### Check if possible to move from given coordinate to desired coordinate

Given two coordinates (x, y) and (a, b). Find if it is possible to reach (x, y) from (a, b).
  
Only possible moves from any coordinate (i, j) are (i-j, j), (i, j-i) , (i+j, j) , (i, j+i)
  
  
If we take a closer look at the problem.
  
we can notice that the moves are similar steps of Euclidean algorithm for finding GCD.
  
So, it is only possible to reach coordinate (a, b) from (x, y) if GCD of x, y is equal to GCD of a, b.
Otherwise, it is not possible.

Let GCD of (x, y) be gcd. From (x, y), we can reach (gcd, gcd) and from this point
we can reach to (a, b) if and only if GCD of ‘a’ and ‘b’ is also gcd.
```cpp 
bool ispossible(int x, int y, int a, int b) 
{ 
    x = abs(x), y = abs(y), a = abs(a), b = abs(b); 
    return (gcd(x, y) == gcd(a, b)); 
} 
int main() 
{ 
    int x = 35, y = 15; 
    int a = 20, b = 25; 
    (ispossible(x, y, a, b)) ? (cout << "Yes") : (cout << "No"); 
    return 0; 
} 
```
### Program to find GCD of floating point numbers

The greatest common divisor (GCD) of two or more numbers, which are not all zero is the largest positive number that divides each of the numbers.
    
Expressing each of the numbers without decimals as the product of primes we get:

120  = 2^3 * 3 * 5
    
2250 = 2 * 3^2 * 5^3

Now, H.C.F. of 120 and 2250 = 2 * 3 * 5=30
    
Therefore,the H.C.F. of 1.20 and 22.5 = 0.30
    
(taking 2 decimal places)
We can do this using the Euclidean algorithm. This algorithm indicates that 
if the smaller number is subtracted from a bigger number
GCD of two numbers doesn’t change.
```cpp
double gcd(double a, double b) 
{ 
    if (a < b) 
        return gcd(b, a); 
  
    if (fabs(b) < 0.001) 
        return a; 
  
    else
        return (gcd(b, a - double(a / b) * b)); 
} 
int main() 
{ 
    double a = 1.20, b = 22.5; 
    cout << gcd(a, b); 
    return 0; 
} 
```
### largest subset with GCD equal to 1

Given n integers, we need to find size of the largest subset with GCD equal to 1.

Let say we find a subset with GCD 1, if we add a new element to it then GCD still remains 1.
    
Hence if a subset exists with GCD 1 then GCD of the complete set is also 1.
    
Hence we first find GCD of the complete set, if its 1 then complete set is that subset else no subset exist with GCD 1.

### Largest subsequence having GCD greater than 1

Given an array arr[], find the largest subsequence such that GCD of all those subsequence are greater than 1.

If we observe then we will found that to make gcd greater than 1
all such elements must contain common prime factor greater than 1 which evenly divides all these values

```cpp
int largestGCDSubsequence(int arr[], int n) 
{ 
    int ans = 0; 
    for (int i=0; i < n; ++i) 
    { 
        int element = arr[i]; 
        while (element > 1) 
        { 
            int div = prime[element]; 
            ++countdiv[div]; 
            ans = max(ans, countdiv[div]); 
            while (element % div==0) 
                element /= div; 
        } 
    } 
    return ans; 
} 
```

### Count number of pairs (A <= N, B <= N) such that gcd (A , B) is B

Given a number n. We need find the number of ordered pairs of a and b such gcd(a, b) is b itself.
    
gcd(a, b) = b means that a is a multiple of b.
    
So total number of pairs will be sum of number of multiples of each b 
(where b varies from 1 to n) which are less than or equal to n.
For a number i, number of multiples of i is equal to floor(n/i)
So what we need to do is just sum the floor(n/i) for each i = 1 to n and print it.

Complexity : O(n)
```cpp
int main()
{
    int n,ans=0;cin>>n;
    for(int i=1;i<=n;i++)
        ans+=n/i;
    cout<<ans;
    return 0;
}
```
### GCD of two numbers formed by n repeating x and y times

Given three positive integer n, x, y. The task is to print Greatest Common Divisor of numbers formed by n repeating x times
and number formed by n repeating y times.    
    
0 <= n, x, y <= 10^9

Input : n = 123, x = 2, y = 3, Output : 123
    
Number formed are 123123 and 123123123. Greatest Common Divisor of 123123 and 123123123 is 123.
    
Solution : GCD(f(n, x), f(n, y)) = f(n, GCD(x, y))

```cpp
int main()
{
    int n,x,y;
    cin>>n>>x>>y;
    int g=gcd(x,y);
    while(g--)
    cout<<n;
    return 0;
}
```

### Find GCD of rational numbers

Given an array of rational numbers, the task is to find the GCD of these numbers.

Input : vect[] = {2/5, 8/9, 16/18,10/27}

Output : 2/405

      
**Solution** First find the GCD of all numerator of rational number then find the LCM of all the denominator of rational number then 
divide GCD of all numerator/ LCM of all the denominator then Reduce the fraction to Lowest Fraction this the GCD of rational number’s
Formula:

```
      GCD of all the numerator of Rational number's
GCD = -----------------------------------------------
      LCM of all the denominator of Rational number's
```

```cpp
int LCM(int a, int b) 
{ 
    return (a * b) / (__gcd(a, b)); 
} 
int gcdOfNumerator(vector<pair<int, int> > vect) 
{ 
    int gcd = vect[0].first; 
    for (int i = 1; i < vect.size(); i++)  
        gcd = __gcd(vect[i].first, gcd);  
      return gcd; 
} 
int lcmOfDemoninators(vector<pair<int, int> > vect) 
{ 
    int lcm = vect[0].second; 
    for (int i = 1; i < vect.size(); i++)  
        lcm = LCM(vect[i].second, lcm);  
    return lcm; 
} 
void gcdOfRationals(vector<pair<int, int> > vect) 
{ 
    int Numerator = gcdOfNumerator(vect);
    int Demoninator = lcmOfDemoninators(vect)
    int g = __gcd(Numerator,Demoninator);
    cout<<Numerator/g<< "/" << Demoninator/g<<endl; 
} 
  
int main() 
{ 
    vector<pair<int, int> > vect; 
    vect.push_back(make_pair(2, 7)); 
    vect.push_back(make_pair(3, 14)); 
    vect.push_back(make_pair(5, 3)); 
    gcdOfRationals(vect); 
    return 0; 
} 
```

### Find LCM of rational numbers

Given an array of rational numbers, the task is to find the LCM of these numbers.

Input : vect[] = {2/7, 3/14, 5/3}

Output : 30/1

**Solution** First find the lcm of all numerator of rational number then find the gcd of all the denominator of rational number then 
divide lcm of all numerator/ gcd of all the denominator then Reduce the fraction to Lowest Fraction this the lcm of rational number’s.
```
      LCM of all the numerator of Rational number's
LCM = -----------------------------------------------
      GCD of all the denominator of Rational number's
```

```cpp
int LCM(int a, int b) 
{ 
    return (a * b) / (__gcd(a, b)); 
} 
int lcmOfNumerator(vector<pair<int, int> > vect) 
{ 
    int lcm = vect[0].first; 
    for (int i = 1; i < vect.size(); i++)  
        lcm = LCM(vect[i].first, lcm);  
      return lcm; 
} 
int gcdOfDemoninators(vector<pair<int, int> > vect) 
{ 
    int gcd = vect[0].second; 
    for (int i = 1; i < vect.size(); i++)  
        gcd = __gcd(vect[i].second, gcd);  
    return gcd; 
} 
void lcmOfRationals(vector<pair<int, int> > vect) 
{ 
    int Numerator = lcmOfDemoninators(vect);
    int Demoninator = gcdOfNumerator(vect)
    int g = __gcd(Numerator,Demoninator);
    cout<<Numerator/g<< "/" << Demoninator/g<<endl; 
} 
int main() 
{ 
    vector<pair<int, int> > vect; 
    vect.push_back(make_pair(2, 7)); 
    vect.push_back(make_pair(3, 14)); 
    vect.push_back(make_pair(5, 3)); 
    lcmOfRationals(vect); 
    return 0; 
} 
```
