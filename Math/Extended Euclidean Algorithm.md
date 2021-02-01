```cpp
/*
GCD (Greatest Common Divisor) or HCF (Highest Common Factor)
we express the 2 numbers in form of : m = qn + r 
*/
int gcd(int a,int b)
{
    if(!b)
        return a;
    return gcd(b,a%b);
}
// gcd for two strings
string gcdOfStrings(string str1, string str2)
{
    if (str1.size() < str2.size())
        return gcdOfStrings(str2, str1);
    if (str2.empty())
        return str1;
    if (str1.substr(0, str2.size()) != str2)
        return "";
    return gcdOfStrings(str1.substr(str2.size()), str2);
}
/*
two integers a and b are said to be relatively prime, mutually prime, or coprime if gcd(a,b) = 1
Assume gcd(a,b) = g then `(a+b)%g = 0` and `(a-b)%g = 0` as (a+b)%g = (a%g+b%g)%g = (0+0)%g = 0
this fact could be used as : gcd(45, 10) = gcd(35, 10) = gcd(25, 10) = gcd(15, 10) = gcd(5, 10) = 5
gcd(10, 5) = gcd(5, 5) = gcd(5, 0) = 5
Wait: We just keep reaming the small from the big, the big number turn to be the smaller, and then do reverse
How to do this switch fast? gcd(45, 10) = gcd(45%10, 10)	-> simply remove the smaller cycles in 1 step
*/

/*
LCM (Least Common Multiple) 
LCM(a,b) = a * b / GCD(a,b)
*/
int lcm(int a,int b)
{
    return a/gcd(a,b)*b;
}

/*
GCD is distributive over the LCM, and vice versa: gcd(a, lcm(b, c)) = lcm(gcd(a, b), gcd(a, c)) 
and lcm(a, gcd(b, c)) = gcd(lcm(a, b), lcm(a, c))

        GCD & LCM
Find GCD and LCM between (504,540)
   504 = 2^3 * 3^2 * 5^0 * 7^1
   540 = 2^2 * 3^3 * 5^1 * 7^0       
GCD(504,540) = 2^2 * 3^2 * 5^0 * 7^0    --> Least power
LCM(504,540) = 2^3 * 3^3 * 5^1 * 7^1    --> highest power
Note : to get GCD of two numbers , we take the least power 
to get LCM of two numbers , we take the highest power
let's do some prime representation for numbers a, b
a = 2^3 * 7^6
b = 2^5 * 7^2
gcd = 2^min(3, 5) * 7^min(6, 2)
what about lcm ? we need max
lcm = 2^max(3, 5) * 7^max(6, 2)
given a * b, and gcd(a, b) how to get lcm(a, b)
what know a * b = 2^8 7^8, and we know gcd = 2^3 7^2
so by division we substrct powers and get lcm = 2^5 7^6
*/

/*
Extended Euclidean algorithm finds integer coefficients x and y such that: ax + by = gcd(a , b) 
The extended Euclidean algorithm updates results of gcd(a, b) using the results calculated by recursive call gcd(b%a, a).
Let values of x and y calculated by the recursive call be x1 and y1. x and y are updated using the below expressions
x = y1, y = x1 - y1 * (a / b);
The above idea still works when a or b or both of them are negative. We only need to change the sign of x and y when necessary.
*/
ll x,y;
ll exgcd(ll a,ll b,ll &x,ll &y)
{
    if (!b)
    {
        x=1;
        y=0;
        return a;
    }
    ll x1, y1;
    ll d = exgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
int main()  
{  
    ll g = exgcd(abs(a), abs(b), x, y); 
    if (a < 0) x *= -1;
    if (b < 0) y *= -1;
    cout<<g<<' '<<x<<' '<<y;  
}  
/*
How does Extended Algorithm Work?
As seen above, x and y are results for inputs a and b: a.x + b.y = gcd ---- (1)  
And x1 and y1 are results for inputs b and a%b: b.x1 + a%b.y1 = gcd   
When we put a%b = (a - (⌊a/b⌋).b) in above, we get the following : b.x1 + (a - (⌊a/b⌋).b).y1  = gcd
Above equation can also be written as below a.y1 + b(x1-(⌊a/b⌋).y1) = gcd      --- (2)
After comparing coefficients of 'a' and 'b' in (1) and (2), we get following
x = y1, y = x1 - y1 * (a / b)
Bézout's identity
Assume a > 0 and b > 0, Can we generate further solutions?
a(x+b) + b(y-a) = g, Yes, we added ab - ab, so same equation
a(x+kb/m) + b(y-ka/m) = g
*/

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
**Solution** First find the GCD of all numerator of rational number
then find the LCM of all the denominator of rational number then 
divide GCD of all numerator/ LCM of all the denominator then Reduce 
the fraction to Lowest Fraction this the GCD of rational number’s
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
**Solution** First find the lcm of all numerator of rational number then 
find the gcd of all the denominator of rational number then 
divide lcm of all numerator/ gcd of all the denominator then Reduce 
the fraction to Lowest Fraction this the lcm of rational number’s.
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
The lowest Common Denominator(LCD) or Least Common Denominator is 
the Least Common Multiple of the denominators of a set of fractions.
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
But that may not always be least common denominator as in this case LCD = 6 and not 18. 
LCD is actually LCM of denominators. LCD for fractions 1/3 and 4/7 is 21
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
The person moves m, slot forward (in circular way) in each step.
Answer: We find GCD(n, m) and then divide n by GCD(n, m).
```
