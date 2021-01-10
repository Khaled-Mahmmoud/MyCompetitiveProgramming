```cpp
// GCD of array: gcd(a, b, c) = gcd(a, gcd(b, c))  = gcd(gcd(a, b), c) = gcd(gcd(a, c), b)
void gcd()
{
    int g=0;
    for(int i=0;i<n;i++)
        g=gcd(g,a[i]);
    cout<<"GCD is : "<<g;
}
// LCM of array: LCM != a*b*c / gcd(a,b,c)
void lcm()
{
    int lcm = a[0];
    for(int i=1;i<n;i++)
        lcm=lcm*a[i]/gcd(lcm,a[i]);
    cout<<"LCM is : "<<lcm;
}
// GCD of two numbers when one of them can be very large                  
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
/*
Product of given N fractions         
Input : N = 3, num[] = { 1, 2, 5 }, den[] = { 2, 1, 6 }      
Product of 1/2 * 2/1 * 5/6 is 10/12 = 5/6
*/
int main()
{
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
/*
Check if possible to move from given coordinate(x, y) to desired coordinate(a, b).  
Only possible moves from any coordinate (i, j) are (i-j, j), (i, j-i) , (i+j, j) , (i, j+i)
We can notice that the moves are similar steps of Euclidean algorithm for finding GCD.
So, it is only possible to reach coordinate(a, b) from (x, y) if GCD of x, y is equal to GCD of a, b.
Otherwise, it is not possible.
*/
bool ispossible(int x, int y, int a, int b) 
{ 
    x = abs(x), y = abs(y), a = abs(a), b = abs(b); 
    return (gcd(x, y) == gcd(a, b)); 
} 
// Program to find GCD of floating point numbers
double gcd(double a, double b) 
{ 
    if (a < b) 
        return gcd(b, a); 
    if (fabs(b) < 0.001) 
        return a; 
    else
        return (gcd(b, a - double(a / b) * b)); 
} 
/*
Find GCD of rational numbers
Input : vect[] = {2/5, 8/9, 16/18,10/27}, Output : 2/405
**Solution** First find the GCD of all numerator of rational number then find the LCM of all the denominator of rational number then 
divide GCD of all numerator/ LCM of all the denominator then Reduce the fraction to Lowest Fraction this the GCD of rational number’s
Formula:
      GCD of all the numerator of Rational number's
GCD = -----------------------------------------------
      LCM of all the denominator of Rational number's
*/
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
/*
Find LCM of rational numbers
Input : vect[] = {2/7, 3/14, 5/3}, Output : 30/1
**Solution** First find the lcm of all numerator of rational number then find the gcd of all the denominator of rational number then 
divide lcm of all numerator/ gcd of all the denominator then Reduce the fraction to Lowest Fraction this the lcm of rational number’s.
      LCM of all the numerator of Rational number's
LCM = -----------------------------------------------
      GCD of all the denominator of Rational number's
*/
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
/*
Least Common Denominator (LCD)
The lowest Common Denominator(LCD) or Least Common Denominator is the Least Common Multiple of the denominators of a set of fractions.
 
 3   -> Numerator             2     3
---                          --- + ---
 4   -> Denominator           5     5
                               \   /
                         Common Denominator
Common denominator : when the denominators of two or more fractions are the same.
Least Common denominator is the smallest of all common denominators.
**Why do we need LCD ?**
It simplifies addition, subtraction and comparing fraction.
Common Denominator can be simply evaluated by multiplying the denominators. In this case, 3 * 6 = 18
 1     1     9     3
--- + --- = --- = ---
 3     6     18    6
But that may not always be least common denominator as in this case LCD = 6 and not 18. LCD is actually LCM of denominators.
LCD for fractions 1/3 and 4/7 is 21
Example Problem : Given two fractions, find their sum using least common dominator.
Input :  1/6  +  7/15    
Output : 19/30, Explanation : LCM of 6 and 15 is 30. So, 5/30  +  14/30 = 19/30.
*/
void printSum(int num1, int den1, int num2, int den2) 
{ 
    int lcd = lcm(den1, den2); 
    num1 *= (lcd / den1);  
    num2 *= (lcd / den2);  
 
    int res_num = num1 + num2; 
    cout << res_num << "/" << lcd; 
} 
/*
Minimum steps to come back to starting point in a circular tour
Consider circular track with n points marked as 1, 2, …n. A person is initially placed on any point. 
The person moves m, slot forward (in circular way) in each step.Answer: We find GCD(n, m) and then divide n by GCD(n, m).
```

