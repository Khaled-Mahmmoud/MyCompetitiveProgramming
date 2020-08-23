# Modular Arithmetic

b divided by a ==>> q , r

b (dividend) , a (divisor) , q (quotient) , r (remainder)

b/a = q

b%a = r

b = 7 , a = 5

7/5 = 1

7%5 = 2

b = a * q + r   

7 = 5 * 1 + 2

_**Properties**_

`N % m < m`

N     =    0 1 2 3 4 5 6 7 8 9 10 11 12 13 ...

N % 5  =   0 1 2 3 4 0 1 2 3 4 0  1  2  3  ...   //   Periodic


`a % b = a - (a/b) * b`

`( a + b ) % m = ( a % m + b % m ) % m`

`( a - b ) % m = ( a % m - b % m ) % m`

`( a * b ) % m = ( a % m * b % m ) % m`

( a / b ) % m may NOT be same as ( (a % m) / (b % m) ) % m

 `x^n    % m =    ( x % m )^n    % m`

( 56 + 47 ) % 10 = 103 % 10 = 3

( 56 + 47 ) % 10 = ( 56 % 10 + 47 % 10) % 10 = ( 6 + 7 ) % 10 = 13 % 10 = 3

_**Applications**_

If today is Tuesday, what day will it be after 40 days?

Represent each day with a number from 0 to 6

Let Tuesday be 3

next = ( day + n ) % 7

next = ( 3 + 40 ) % 7 = ( 3 % 7 + 40 % 7 ) % 7 = (3 + 5) % 7 = 8 % 7 = 1

next = ( 3 + 40 ) % 7 = 43 % 7 = 1


What day was it 40 days ago?

prev = ( n - day ) % 7

prev = ( 3 - 40 ) % 7 = -37 % 7 = -2 ==> 5

If the result is negative, add m

In general ( (day-n) % 7 + 7 ) % 7

_**Codility**_ (Cylcic rotations)

Given an array size N , rotate it k times

10 20 30 40 50 60 70   // rotate it 2 times

30 40 50 60 70 10 20

```cpp
k = k % N
for(int i = 0; i < N; i++)      //    index    0  1  2  3  4  5  6 
    B[(i+k)%N] = A[i];         //     a       10 20 30 40 50 60 70
                              //      b       60 70 10 20 30 40 50
```
Other applications: Clock arithmetic, circles, bottle rotation, ...


Add(or multiply) n integers together, and output the result %m.
```cpp
int sum = 0;
for(int i = 0; i < n; i++)
    sum = (sum + a[i]%m)%m;
```

some other facts : 

` |a%n| has n-1: 0, 1, ...n-1

- (n ^ x) % n = 0 for any x >= 0

- -a%n != a%n (3 %12 = 3 vs -3 %12 = 9)

- ((-a%n)+(a%n))%n = 0

- x % (a+b) != x % a + x %b

- x%10 [get the last digit]. x/10 [remove last digit]

-(a^b) % n => assume b even and x = b/2 then ( (a^x) % n * (a^x) % n) % n
     
- (1/a) % n ? modular multiplicative inverse

- ((a * b) % n * (1/a)%n) %n = b % n

- a % (2^n) = a & (n-1) => E.g. a%4 = a&3

- a % 0 is undefined

```cpp
boo is_odd(int n)
{
    return (n % 2 == 1);     //  this wrong because if n is negative then n % 2 = -1 
    return (n % 2 == 1) || (n % 2 == -1);   // this correct
    retunr (n % 2 != 0);   // this correct
}
```
