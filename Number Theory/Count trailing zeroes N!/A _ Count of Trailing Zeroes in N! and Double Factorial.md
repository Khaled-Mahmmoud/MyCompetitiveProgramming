# Count of Trailing Zeroes in N! and Double Factorial

**Leading Zero** :: is any 0 digit that comes before the first nonzero digit in a number string in positional notation.

0070009 ==>> has 2 leading zero , 000402 has 3 leading zero

**Trailing Zeros** ::  is any 0 digit that comes after the last nonzero digit in a number string in positional notation.

910034050000 ==>> The number has {4} trailing zeros 


The number of trailing zeros in a non-zero base-b integer n equals the exponential of the highest power of b that divides n
For example, 14000 has three trailing zeros and is therefore divisible by 1000 = 10^3

**Problem** : Given an integer n, write a function that returns count of trailing zeroes in N!
OR Given an integer N, the task is to find the number of trailing zeroes in the base 10 representation of the factorial of N

|input|output|
|---|---|
|5|1|
|20|4|

Factorial of 5 is 120 which has one trailing 0.

Factorial of 20 is 2432902008176640000 which has 4 trailing zeroes

**Solution** : A trailing zero is always produced by prime factors 2 and 5 . 

n = 5  : There is one 5s and three 2s in prime factors of `5! = (5*(2*2)*3*2*1)` . So count of trailing 0s is 1

n = 11 : There are two 5s and eight 2s in prime factors of `11! = (11*(5*2)*(3*3)*(2*2*2)*7*(2*3)*5*(2*2)*3*2*1)` So count of trailing 0s is 2

We can easily observe that the number of 2s in prime factors is always more than or equal to the number of 5s, So we count 5s in prime factors

**How to count total number of 5s in prime factors of n!?** A simple way is to calculate floor(n/5)
For example, 7! has one 5, 10! has two 5s. It is done yet

Numbers like 25, 125, etc have more than expected because 

| num | 5s |
|---|---|
| 5  | 5 * 1 |
| 10 | 5 * 2 |
| 15 | 5 * 3 |
| 20  | 5 * 4 |
| 25 | 5 * 5 | 
| 125 | 5 * 5 * 5 |

    
```cpp
int f(int n)
{
    int cnt=0;
    while(n)
    {
        cnt+=n/5;
        n/=5;
    }
}
```
OR
```cpp
int f(int n) 
{ 
    int cnt=0;  
    for (int i=5;n/i>=1;i*=5) 
        cnt+=n/i; 
    return cnt; 
} 
```
if n = 1e18 , time = 0,042s

**Double Factorial Problem**

F(n) = 1 if(n<2)

F(n) = n * f(n-2) if(n>=2)

Given is an integer n , Find the number of trailing zeros of F(n)

n <= 1e18    

```cpp
#define ll long long
ll f(ll n)
{
    ll cnt=0;
    for(ll i=10;n/i>=1;i*=5)
        cnt+=n/i;
    return cnt;
}
int main()
{
    fast();
    ll n;cin>>n;
    cout<<(n%2?0:f(n));
    return 0;
}

```
