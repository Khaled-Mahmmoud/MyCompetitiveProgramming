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
### Queries for GCD of all numbers of an array except elements in a given range

Given an array of n numbers and a number of queries are also given. Each query will be represented by two integers l, r.
        
The task is to find out the GCD of all the numbers of the array excluding the numbers given in the range l, r (both inclusive) for each query.

```cpp
void FillPrefixSuffix(int prefix[], int arr[], int suffix[], int n) 
{ 

    prefix[0] = arr[0]; 
    for (int i=1 ;i<n; i++) 
        prefix[i] = __gcd(prefix[i-1], arr[i]); 

    suffix[n-1] = arr[n-1]; 
  
    for (int i=n-1; i>=0 ;i--) 
        suffix[i] = __gcd(suffix[i+1], arr[i]); 
} 
int GCDoutsideRange(int l, int r, int prefix[], int suffix[], int n) 
{ 
    if (l==0) 
        return suffix[r+1]; 
    if (r==n-1) 
        return prefix[l-1]; 
    return __gcd(prefix[l-1], suffix[r+1]); 
} 
int main() 
{ 
    int arr[] = {2, 6, 9}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    int prefix[n], suffix[n]; 
    FillPrefixSuffix(prefix, arr, suffix, n); 
  
    int l = 0, r = 0; 
    cout << GCDoutsideRange(l, r, prefix, suffix, n) <<endl;
} 
```
