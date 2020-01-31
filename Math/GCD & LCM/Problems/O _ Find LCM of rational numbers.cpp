/*
Given an array of rational numbers, the task is to find the LCM of these numbers.

Examples:

Input : vect[] = {2/7, 3/14, 5/3}
Output : 30/1

Input : vect[] = {3/14, 5/3}
Output : 15/1

Input : vect[] = {3/4, 3/2}
Output : 3/2

Solution
First find the lcm of all numerator of rational number then find the gcd of all the denominator of rational number then 
divide lcm of all numerator/ gcd of all the denominator this the lcm of rational number’s.

Formula:-

      LCM of all the numerator of Rational number's
lcm = -----------------------------------------------
      GCD of all the denominator of Rational number's
*/
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
  
// find lcm of all the rational number 
void lcmOfRationals(vector<pair<int, int> > vect) 
{ 
    cout << lcmOfNumerator(vect) << "/" << gcdOfDemoninators(vect); 
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
