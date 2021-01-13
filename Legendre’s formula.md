```cpp
/*
Count of Trailing Zeroes in N!
The number of trailing zeros in a non-zero base-b integer n equals the exponential of the highest power of b that divides n
For example, 14000 has three trailing zeros and is therefore divisible by 1000 = 10^3

Solution : for base 10, A trailing zero is always produced by prime factors 2 and 5 . 
n = 5  : There is one 5s and three 2s in prime factors of 5! = (5*(2*2)*3*2*1) . So count of trailing 0s is 1
the number of 2s in prime factors is always more than or equal to the number of 5s, So we count 5s in prime factors
How to count total number of 5s in prime factors of n!?
| num | 5s    |
| 5   | 5 * 1 |
| 10  | 5 * 2 |
| 15  | 5 * 3 |
| 20  | 5 * 4 |
| 25  | 5 * 5 | 
| 125 | 5*5*5 |
*/
int f(int n)
{
    int cnt=0;
    while(n)
    {
        cnt+=n/5;
        n/=5;
    }
    return cnt;
}
// OR
int f(int n) 
{ 
    int cnt=0;  
    for (int i=5;n/i>=1;i*=5) 
        cnt+=n/i; 
    return cnt; 
} 

/*
Number of trailing zeroes in base 16 representation of N!
6! = 720 (base 10) = 2D0 (base 16)
(720)10 = ( 2D0 )16
|16   |   720  | rem |
|16   |   45   |  0  |
|16   |   2    |  D  |    
|16   |   0    |  2  |     
observe it's 0 when n % 16 == 0
Number of trailing zeroes would be the highest power of 16 in the factorial of N in base 10
We know that 16 = 2^4. 
So, the highest power of 16 is equal to the highest power 2 in the factorial of N divided by 4 
*/
void solve(ll n)
{
    ll cnt=0;
    while(n)
    {
        cnt+=n/2;
        n/=2;
    }
    cout<<cnt/4;
}
// O(log2(n))

// largest power of prime number in n! is n/p + n/(p^2) + n/(p^3) + …… (Legendre’s formula)
int larg(int n,int p)
{
    int cnt=0;
    while(n)
    {
        cnt+=n/p;
        n/=p;
    }
    return cnt;
}
/*
// largest power of number in n!
K = p1^a1 p1^a2 p3^a3 ....
Answer = min( larg(n,p1)/a1 , larg(n,p2)/a2 , larg(n,p3)/a3 ,....)
*/
```
