/*
Given two Rational numbers, the task is to find the maximum of given two rational numbers.

Input : first = 3/4, second= 3/2
Output : 3/2

Input : first = 100/100, second = 300/400
Output : 100/100

A simple solution is to find float values and compare the float values. The float computations may cause precision errors
We can avoid them using below approach.

Say first = 3/2, second = 3/4

First take a LCM of (4, 2) which is denominator of rational number. so the LCM of this is 4
then divide with both denominator and multiple with numerator of first and second respectively 
so the denominator value is first numerator = 6, second numerator = 3.
Then find the max between these two. so here first numerator is max then print first rational number.

*/

struct Rational 
{ 
    int nume, deno; 
}; 
int lcm(int a, int b)  
{ 
    return (a * b) / (__gcd(a, b)); 
} 
Rational maxRational(Rational first, Rational sec) 
{ 
    int k = lcm(first.deno, sec.deno); 
    
    int nume1 = first.nume; 
    int nume2 = sec.nume; 
  
    nume1 *= k / (first.deno); 
    nume2 *= k / (sec.deno); 
  
    return (nume2 < nume1)? first : sec; 
} 
int main() 
{ 
    Rational first = { 3, 2 }; 
    Rational sec = { 3, 4 }; 
  
    Rational res = maxRational(first, sec); 
    cout << res.nume << "/" << res.deno; 
    return 0; 
} 
