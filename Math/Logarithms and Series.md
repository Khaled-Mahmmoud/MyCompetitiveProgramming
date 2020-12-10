# Logarithms

The logarithm of a number x is denoted logk(x), where k is the base of the logarithm

According to the definition, logk(x) = a exactly when x = k^a 

A useful property of logarithms is that logk(x) equals the number of times we have to divide x by k before we reach the number 1

For example, log2(8) = 3 because 3 divisions are needed

8 → 4 → 2 → 1

log10(1000) = 3 because 3 divisions are needed

1000 → 100 → 10 → 1

Logarithms are often used in the analysis of algorithms, because many efficient algorithms halve something at each step

Hence, we can estimate the efficiency of such algorithms using logarithms

The logarithm of a product is 
```
logk(ab) = logk(a)+logk(b)
```
and consequently
```
logk(x^n) = n·logk(x)
```                                  
In addition, the logarithm of a quotient is
```
logk(a/b) = logk(a)−logk(b)
```
Another useful formula is
```
logu(x) = logk(u)/logk(x)
``` 
and using this, it is possible to calculate logarithms to any base if there is a way
to calculate logarithms to some fixed base

The natural logarithm ln(x) = loge(x) of a number x is a logarithm whose base is

e ≈ 2,71828

k = [10, e, 2] => (common, natural, binary) log
- Math notations: lg(x), ln(x), lb(x)
- In c++: log10(x), log(x), log2(x)


Another property of logarithms is that the number of digits of an integer x in base b is `[ floor(logb(x)) + 1 ]`

For example, the representation of 123 in base 2 is 1111011 and [ log2(123) + 1 ] = 7
```
logb b = 1, logb 1 = 0, logb 0 = -oo, log1 x = undefined
● b^logb(x) = x => take logb for the equation to get x
● x b^y => b^(logb(x) + y)
```

### + more 

1/1 + 1/2 + 1/3 + 1/4 + 1/5 + ..... + 1/(n-1) + 1/n = log(n)  ```Harmonic Progression```

1/2 + 1/3 + 1/5 + 1/7 + ..... + 1/p = log(log n) where p is largest prime less then n

Θ(log(n!)) = Θ(n·log(n))

log(n!) = log(1) + log(2) + ... + log(n-1) + log(n) ==>> log(a * b) = log(a) + log(b)

log(1) + log(2) + ... + log(n) <= log(n) + log(n) + ... + log(n) = n*log(n)

sum(x=1,n) x   = 1 + 2 + 3 + ... + n = n*(n+1)/2

sum(x=1,n) x^2 = 1 + 4 + 9 + ... + n*n = n*(n+1)*(2n+1)/6


### Arithmetic Progression (AP) 

Arithmetic Progression (AP) :: is a sequence of numbers where the difference between any two consecutive numbers is constant.

n ==>> number of elements , a ==>> first element , b ==>> last element , d ==>> difference between any two consecutive numbers

a , a+d , a+2d , a+3d , ..... , b

3 , 7 , 11 , 15 , 19 , 23 , 27

i'th term = a + (i-1) * d
```
          n*(a+b)     n*(a+[a+(n-1)*d])
The sum =--------- = ----------------
             2             2
```
for Arithmetic Progression 2 5 8 where a=2 , b=8 , d=3 , n=3 , a+b=10
```
2   5   8  
8   5   2
==========
10  10  10
```

### Geometric Progression (GP) 

Geometric Progression (GP) :: is a sequence of numbers where the ratio between any two consecutive numbers is constant.

n ==>> number of elements , a ==>> first element , b ==>> last element , r ==>> ratio between any two consecutive numbers

a , a*r , a*r*r , a*r*r*r , .... , b

3 , 6 , 12 , 24 , 48 , 96 , 192

i'th term = a * r^(i-1)
```
           (br-a)   a*(r^n-1)
The sum =  ------ = ---------
           (r-1)     (r-1)
```
This formula can be derived as follows

S = a + a*r + a*r*r +··· + b

By multiplying both sides by r , we get

S*r = a*r + a*r*r + a*r*r*r +··· + b*r

and solving the equation

S*r − S = b*r − a

S*(r-1) = b*r - a
```
    (b*r-a)
S = ------
    (r-1)
```
A special case of a sum of a geometric progression is the formula

  1   +   2   +   4   +  8   + ... + 2^(n-1) = 2^n - 1 
  
2^(0) + 2^(1) + 2^(2) +2^(3) + ... + 2^(n-1) = 2^n - 1

Assume we have sum of this geometric (k) , how to get n

k = 2^n - 1

k + 1 = 2^n   

Taking log(base 2) of both sides give

log(k+1)=log(2^n)    

log(k+1) = n log(2)

n = log(k+1) // log(base 2)

**infinite geometric series**

As n goes to infinity, the absolute value of r must be less than one for the series to converge. The sum then becomes

a + ar + ar^2 + ar^3 + ..... = a/(1-r). for abs(r) < 1

When a = 1, this can be simplified to 1 + r + r^2 + r^3 + ..... = 1/(1-r)

### Harmonic Series 

Harmonic Series ::  is inverse of a arithmetic progression. 

In general, the terms in a harmonic progression can be denoted as 1/a, 1/(a + d), 1/(a + 2d), 1/(a + 3d) …. 1/(a + nd).


sum(x=1,n) 1/x = 1 + 1/2 + 1/3 + 1/4 + ... + 1/n

How to find the Nth Harmonic Number OR to find sum of harmonic series ?
```
H1 = 1
H2 = H1 + 1/2
H3 = H2 + 1/3
H4 = H3 + 1/4
.
.
.
Hn = Hn-1 + 1/n
```
Time complexity : O(n)

Note : the n-th harmonic number is the sum of the previous harmonic numbers

An upper bound for a harmonic sum is log2(n) + 1
