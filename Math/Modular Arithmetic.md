```cpp
/*
<Modular Arithmetic>
b divided by a ==>> q , r
b (dividend) , a (divisor) , q (quotient) , r (remainder)
b/a = q
b%a = r
b = a * q + r   
1) Reduce N (mod 3) to a number in the range {0, 1, 2}.
2) Reduce -N (mod 3) to a number in the range {0, 1, 2}.
3) 101 = 2 (mod 3) , because 3 | (101 - 2 = 99).
4) -101 = 1 (mod 3) , because 3 | (-101 - 1 = -102).

N % m < m
N     =    0 1 2 3 4 5 6 7 8 9 10 11 12 13 ...
N % 5  =   0 1 2 3 4 0 1 2 3 4 0  1  2  3  ...   //   Periodic

a % b = a - (a/b) * b

( a + b ) % m = ( a % m + b % m ) % m
( a - b ) % m = ( a % m - b % m ) % m
( a * b ) % m = ( a % m * b % m ) % m
( a / b ) % m may NOT be same as ( (a % m) / (b % m) ) % m
but (a/b) % m = (a * inv(b)) % m
x^n    % m =  ( x % m )^n % m

MOD is expensive! That is, in case a tight order problem, code TLE due to MOD!
if(a > MOD || a < 0)
    a = (a%X + X)%X

If today is Tuesday, what day will it be after 40 days?
Represent each day with a number from 0 to 6
Let Tuesday be 3
next = (day + n) % 7
next = ( 3 + 40 ) % 7 = ( 3 % 7 + 40 % 7 ) % 7 = (3 + 5) % 7 = 8 % 7 = 1
next = ( 3 + 40 ) % 7 = 43 % 7 = 1

What day was it 40 days ago?
prev = (day - n) % 7
prev = ( 3 - 40 ) % 7 = -37 % 7 = -2 ==> 5
If the result is negative, add m
In general ( (day-n) % 7 + 7 ) % 7

Codility (Cylcic rotations)
Given an array size N , rotate it k times
10 20 30 40 50 60 70   // rotate it 2 times
60 70 10 20 30 40 50
*/
k = k % N
for(int i = 0; i < N; i++)      //    index    0  1  2  3  4  5  6 
    B[(i+k)%N] = A[i];         //     a       10 20 30 40 50 60 70
                              //      b       60 70 10 20 30 40 50
/*
// Add(or multiply) n integers together, and output the result %m.
int sum = 0;
for(int i = 0; i < n; i++)
    sum = (sum + a[i]%m)%m;
/*
|a%n| has n-1 values: 0, 1, ...n-1
(n ^ x) % n = 0 for any x >= 0
-a%n != a%n (3 %12 = 3 vs -3 %12 = 9)
((-a%n)+(a%n))%n = 0
x % (a+b) != x % a + x %b
x%10 [get the last digit]. x/10 [remove last digit]
(a^b) % n => assume b even and x = b/2 then ( (a^x) % n * (a^x) % n) % n
(1/a) % n ? modular multiplicative inverse
((a * b) % n * (1/a)%n) %n = b % n
X % (2^n) = X & (2^n - 1) => E.g. a%4 = a&3
a % 0 is undefined
*/
boo is_odd(int n)
{
    return (n % 2 == 1);     //  this wrong because if n is negative then -3 % 2 = -1
    return (n % 2 == 1) || (n % 2 == -1);   // this correct
    // or
    return (n % 2 != 0);   // this correct
    // or
    return (n & 1);
}
// (n-1) % n = n - 1 or (n-1) % n = -1
```
