# Find GCD of rational numbers

Given an array of rational numbers, the task is to find the GCD of these numbers.

Input : vect[] = {2/5, 8/9, 16/18,10/27}

Output : 2/405
      
Input : vect[] = {9/10, 12/25, 18/35 ,21/40}

Output : 3/1400
      
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

# Find LCM of rational numbers

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
    cout << lcmOfNumerator(vect) << "/" << gcdOfDemoninators(vect); 
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
