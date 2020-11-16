# Multiply large integers under large modulo

Given an integer a, b, m. Find (a * b ) mod m, where a, b may be large and their direct multiplication may cause overflow
However they are smaller than half of the maximum allowed long long int value.

Input: a = 426, b = 964, m = 235
Output: 119

A naive approach is to use arbitrary precision data type such as int in python or Biginteger class in Java
But that approach will not be fruitful because internal conversion of string to int and then perform operation
will lead to slow down the calculations of addition and multiplications in binary number system

Efficient solution : Since a and b may be very large numbers
if we try to multiply directly then it will definitely overflow
Therefore we use the basic approach of multiplication i.e., a * b = a + a + … + a (b times)

So we can easily compute the value of addition (under modulo m) without any overflow in the calculation
But if we try to add the value of a repeatedly up to b times then it will definitely timeout for the large value of b
since the time complexity of this approach would become O(b)

So we divide the above repeated steps of a in simpler way i.e.,

If b is even then a * b = 2 * a * (b / 2), 
otherwise a * b = a + a * (b - 1)
```cpp
long long moduloMultiplication(long long a, long long b, long long mod) 
{ 
    long long res = 0;
    a %= mod; 
    while (b) 
    { 
        if (b & 1) 
            res = (res + a) % mod; 
        a = (2 * a) % mod; 
        b >>= 1; // b = b / 2 
    } 
  
    return res; 
} 
int main() 
{ 
    long long a = 10123465234878998; 
    long long b = 65746311545646431; 
    long long m = 10005412336548794; 
    cout << moduloMultiplication(a, b, m); 
    return 0; 
} 
```
Output:
4652135769797794
            
Time complexity: O(log b)
            
Auxiliary space: O(1)
