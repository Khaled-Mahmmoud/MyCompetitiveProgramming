# GCD of array

Given an array of numbers, find GCD of the array elements.

Input  : arr[] = {2, 4, 6, 8}

Output : 2
  
The GCD of three or more numbers equals the product of the prime factors common to all the numbers
but it can also be calculated by repeatedly taking the GCDs of pairs of numbers.
````
gcd(a, b, c) = gcd(a, gcd(b, c)) 
             = gcd(gcd(a, b), c) 
             = gcd(gcd(a, c), b)
```
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
    int g=0;
    for(int i=0;i<n;i++)
        g=gcd(g,a[i]);
    cout<<"GCD is : "<<g;
    return 0;
}
```
Complexity : nlog(max(a[i]))

# LCM of array

Given an array of n numbers, find LCM of it.
  
Input : {1, 2, 8, 3}

Output : 24.
  
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
```
Complexity : nlog(max(a[i]))
