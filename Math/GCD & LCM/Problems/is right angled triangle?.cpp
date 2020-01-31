/*
Check whether right angled triangle is valid or not for large sides
Given three integers a, b and c as triplets. Check if it is possible to make right angled triangle or not
Print Yes if possible, else No. 10^-18 <= a, b, c <= 10^18

Examples:

Input: 3 4 5
Output: Yes
Explanation:
Since 3*3 + 4*4 = 5*5
Hence print "Yes"

Input: 8 5 13
Since 8 + 5 < 13 which violates the property of triangle. Hence print "No"

Solution :
1) a, b and c should be greater then 0.
2) Sum of any two sides of triangle must be greater than the third side.
3) Pythagorean Theorem i.e., a^2 + b^2 = c^2.

First two conditions can be easily checked but for third condition we have to take care of overflow
Since a, b and c can be large so we can’t compare them directly unless we use python or BigInteger library in Java
For languages like C and C++, we have to reduce the expression in fraction form.

  a^2 + b^2 = c^2   
  a^2 = c^2 - b^2  
  a^2 = (c+b)(c-b)
   a     c+b
  --- =  ---
  c-b     a
*/
bool Triplets(long long a, long long b, long long c) 
{ 
    if (a <= 0 || b <= 0 || c <= 0) 
        return false; 
  
    vector<long long> vec{ a, b, c }; 
    sort(vec.begin(), vec.end()); 
    a = vec[0], b = vec[1], c = vec[2]; 
     if (a + b <= c) 
        return false; 
  
    long long p1 = a, p2 = c - b; 
    long long div = __gcd(p1, p2); 
    p1 /= div, p2 /= div; 
  
    long long q1 = c + b, q2 = a; 
    div = __gcd(q1, q2); 
    q1 /= div, q2 /= div; 
    
    return (p1 == q1 && p2 == q2); 
} 
string checkTriplet(long long a, long long b, long long c) 
{ 
    if (Triplets(a, b, c)) 
        return "Yes"; 
    else
        return "No"; 
} 
int main() 
{ 
    long long a = 4, b = 3, c = 5; 
    cout << checkTriplet(a, b, c) << endl; 
  
    a = 8, b = 13, c = 5; 
    cout << checkTriplet(a, b, c) << endl; 
  
    a = 1200000000000, b = 1600000000000, c = 2000000000000; 
    cout << checkTriplet(a, b, c) << endl; 
  
    return 0; 
} 
