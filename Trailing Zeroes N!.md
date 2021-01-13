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

/*
Get right most non zero digit of factorial N?
Let's simplify. Last digit of X = X%10
Let X = 123000, then last non zero digit of X = 3
Let X = 123 * 10^3, so 3 = 123%10
Note (a*b*c)%D = (a%D * b%D * c%D) % D
If in n! we could represent it as = 10^x * reminder...then reminder%10 is the answer
again, Let n! = 2^a * 5^b * reminder1
Then	n! = 10^b * reminder2 , So to calculate reminder2 we need to cacl n! such that we don't consider b 2's 
In fact, all 5's wont't be used, and we will use overall a-b 2's
Let n = 15, n! = 1307674368000 = 2^11 * 5^3 * 5108103
So n! has 3 zeros, We want to calculate n! with only 11-3 2's
Let X = 2^8 * 5108103 = 1307674368, so X%10 = 8

Right most non zero digit of product of array
You will be given an array A of N non negative integers. Your task is to find the right most non zero digit 
in the product of array elements.
*/
int cnt2,cnt5;
int solve(long long n)
{
    while(cnt2&&n%2==0)
    {
        n/=2;
        cnt2--;
    }
    while(cnt5&&n%5==0)
    {
        n/=5;
        cnt5--;
    }
    return n%10;
}
int main()
{
    int n;
    cin>>n;
    cnt2 = 0;
    cnt5 = 0;
    long long a[n],x;
    bool flag = false;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        if(!a[i])
        {
            flag = true;
            continue;
        }
        x = a[i];
        while(x%2==0)
        {
            cnt2++;
            x = x/2;
        }
        while(x%5==0)
        {
            cnt5++;
            x = x/5;
        }
    }
    if(flag)
        return cout<<-1,0;
    cnt2 = min(cnt2,cnt5);
    cnt5 =  cnt2;
    int ans = 1;
    for(int i=0; i<n; i++)
    {
        ans = (ans * solve(a[i]))%10;
    }
    cout<<ans;
    return 0;
}
```
