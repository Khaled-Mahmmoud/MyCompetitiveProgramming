/*
Program to find GCD of floating point numbers
The greatest common divisor (GCD) of two or more numbers, which are not all zero
is the largest positive number that divides each of the numbers

Input  : 0.3, 0.9
Output : 0.3

Input  : 0.48, 0.108
Output : 0.012


a=1.20
b=22.5
Expressing each of the numbers without decimals as the product of primes we get:
120  = 2^3 * 3 * 5
2250 = 2 * 3^2 * 5^3

Now, H.C.F. of 120 and 2250 = 2 * 3 * 5=30
Therefore,the H.C.F. of 1.20 and 22.5 = 0.30
(taking 2 decimal places)
We can do this using the Euclidean algorithm. This algorithm indicates that 
if the smaller number is subtracted from a bigger number
GCD of two numbers doesn’t change
*/

double gcd(double a, double b) 
{ 
    if (a < b) 
        return gcd(b, a); 
  
    if (fabs(b) < 0.001) 
        return a; 
  
    else
        return (gcd(b, a - floor(a / b) * b)); 
} 
int main() 
{ 
    double a = 1.20, b = 22.5; 
    cout << gcd(a, b); 
    return 0; 
} 
