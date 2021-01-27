```cpp
/*
<Logarithms>
logk(x) means the number of times we have to divide x by k before we reach the number 1
(x = k^a) ==> (a = logk(x))

log(a * b) = log(a) + log(b)
log(x^n) = log(x * x * x...n times) = log(x) + log(x) + ... + n times =  n·log(x)
log(a/b) = log(a) − log(b)
logu(x) = log(u) / log(x)

The natural logarithm ln(x) = loge(x) where e ≈ 2,71828
k = [10, e, 2] => (common, natural, binary) log
- Math notations: lg(x), ln(x), lb(x)
- In c++: log10(x), log(x), log2(x)
logb b = 1, logb 1 = 0, logb 0 = -oo, log1 x = undefined, b^logb(x) = x 
number of digits of integer x in base b is floor(logb(x)) + 1 
*/
#define numOfDigit(x) 1 + floor(log10(x))
#define numOfBits(x)  1 + floor(log2(x)))
// Number of Digits in !n = floor(log10(1 * 2 * 3 * 4 * 5 *  .... * n)) + 1 
//                        = floor(log10(1) + log10(2) + ... + log10(n)) + 1
int main()
{
    int n;
    cin>>n;
    double ans = 0;
    for(int i=1;i<=n;i++)
        ans += log10(i);
    cout<<fixed<<setprecision(0)<<floor(ans) + 1;
    return 0;
}
/*
Harmonic Progression: 1/1 + 1/2 + 1/3 + 1/4 + 1/5 + ..... + 1/(n-1) + 1/n = log(n)
1/2 + 1/3 + 1/5 + 1/7 + ..... + 1/p = log(log n) where p is largest prime less then n

Θ(log(n!)) = Θ(n·log(n))
log(1) + log(2) + ... + log(n) <= log(n) + log(n) + ... + log(n) 
*/
```

```cpp
/*
<Series>
sum(x=1,n) x   = 1 + 2 + 3 + ... + n = n*(n+1)/2
sum(x=1,n) x^2 = 1 + 4 + 9 + ... + n*n = n*(n+1)*(2n+1)/6

Arithmetic Progression (AP) :: is a sequence of numbers where the difference between any two consecutive numbers is constant.
n ==>> number of elements , a ==>> first element , b ==>> last element , d ==>> difference between any two consecutive numbers
a , a+d , a+2d , a+3d , ..... , b : 2 5 8
i'th term = a + (i-1) * d
          n*(a+b)     n*(a+[a+(n-1)*d])
The sum =--------- = ----------------
             2             2
2   5   8  
8   5   2
==========
10  10  10  sum = (10 + 10 + 10) /2

Geometric Progression (GP) :: is a sequence of numbers where the ratio between any two consecutive numbers is constant.
n ==>> number of elements , a ==>> first element , b ==>> last element , r ==>> ratio between any two consecutive numbers
a , a*r , a*r*r , a*r*r*r , .... , b: 3 , 6 , 12 
i'th term = a * r^(i-1)
           (br-a)   a*(r^n-1)
The sum =  ------ = ---------
           (r-1)     (r-1)
S = a + a*r + a*r*r +··· + b
S*r = a*r + a*r*r + a*r*r*r +··· + b*r
S*r − S = b*r − a
S*(r-1) = b*r - a

2^(0) + 2^(1) + 2^(2) +2^(3) + ... + 2^(n-1) = 2^n - 1
Infinite Geometric Series:  a + ar + ar^2 + ar^3 + ..... = a/(1-r). for abs(r) < 1
*/

//sum 1/(x^i) for i = 1 to n
double summation(int x, int n)
{
   double p = power(x, n);
   return(p - (x - 1.0)) / p;
}

/*
 Harmonic Series
 1 + 1/2 + 1/3 + 1/4 + 1/5 ... + 1/n is O(log n)
 1 + 1/2 + 1/3 + 1/7 + ... + 1/p is O(log log n) where p is largest prime less than n

*/
```
