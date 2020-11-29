### Count of Trailing Zeroes in N!


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

### Smallest Number has N Trailing Zero

Given a number n. The task is to find the smallest number whose factorial contains at least n trailing zeroes.
    
| Input | Output |
|---|---|
| 1 | 5 |
|2|10|
|6|25|
    
1!, 2!, 3!, 4! does not contain trailing zero. 5! = 120, which contains one trailing zero.

5!  has 1 trailing zeroes  ==>>  [All numbers from 6! to 9! have 1 trailing zero]

10! has 2 trailing zeroes  ==>>  [All numbers from 11! to 14! have 2 trailing zeroes]

15! to 19! have 3 trailing zeroes

20! to 24! have 4 trailing zeroes

25! to 29! have 6 trailing zeroes

We can notice that, the minimum value whose factorial contain n trailing zeroes is 5*n

```cpp
bool valid(ll mid)
{
    ll cnt=0;
    while(mid)
    {
        cnt+=mid/5;
        mid/=5;
    }
    return (cnt>=n);
}
void solve()
{
    ll l=0,r=n*5;
    while(l<r)
    {
        ll mid = l+((r-l)>>1);
        if(valid(mid))
            r=mid;
        else
            l=mid+1;
    }
    cout<<l;
}
```
Time Complexity : O( log2(n) * log5(n) )


### Number of trailing zeroes in base 16 representation of N!

Given an integer N, the task is to find the number of trailing zeroes in the base 16 representation of the factorial of N

|Input|Output|
|---|---|
|6|1|

6! = 720 (base 10) = 2D0 (base 16)

(720)10 = ( 2D0 )16

|16   |   720  | rem |
|---|---|---|
|16   |   45   |  0  |
|16   |   2    |  D  |    
|16   |   0    |  2 |     

observe it's 0 when n % 16 == 0

Number of trailing zeroes would be `the highest power of 16 in the factorial of N in base 10`
We know that 16 = 2^4. So, the highest power of 16 is equal to the highest power 2 in the factorial of N divided by 4
(n <= 1e18) 
```cpp
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
```
Time Complexity : O(log2(n))

### Number of trailing zeroes in b-ary (base B) representation of N!

Given two positive integers B and N . The task is to find the number of trailing zeroes in b-ary (base B) representation of N!

`6! = (720)10 = (880)9 = (246)7`. Suppose, the base is 10 i.e., decimal then we’ll have to calculate the highest power of 10 that divides N! 
not easy to get highest power of 10 , so we get highest power of 10's prime factors 
but 10 = 2 * 5 , so we answer is minimum between the highest power of 2 and the highest power of 5
Hence, problem reduces to finding the highest power of B in N!
n <= 1e18 & b <= 1e12

OR 

### Largest power of k in n! (factorial) where k may not be prime

Given two numbers k and n, find the largest power of k that divides n!

Constraints: K > 1 

|Input |Output|
|---|---|
|n = 7, k = 2|4|
|n = 10, k = 9|2|

The largest power of 2 that
divides 7! is 24.

The largest power of 9 that
divides 10! is 92.

Now to find the power of any non-prime number k in n!, we first find all the prime factors of the number k along with the count of number of their occurrences. 
Then for each prime factor, we count occurrences using Legendre’s formula which states that the largest possible power of a prime number p in n is `⌊n/p⌋ + ⌊n/(p^2)⌋ + ⌊n/(p^3)⌋ + ……`

Over all the prime factors p of K, the one with the minimum value of `findPowerOfK(n, p)/count` will be our answer where count is number of occurrences of p in k.

```cpp
vector<pair<ll,ll>>v;
ll solve(ll n,ll p)
{
    ll cnt=0;
    while(n)
    {
        cnt+=n/p;
        n/=p;
    }
    return cnt;
}
void primefactors(ll n)
{
    ll cnt=0;
    while(!(n & 1))
    {
        cnt++;
        n>>=1;
    }
    if(cnt)
    v.push_back({2,cnt});
    for(ll i=3;i<=sqrt(n);i+=2)
    {
        cnt=0;
        while(!(n%i))
        {
            cnt++;
            n/=i;
        }
        if(cnt)
        v.push_back({i,cnt});
    }
    if(n>1)
    v.push_back({n,1});
}
int main()
{
    ll n,b;cin>>n>>b;
    primefactors(b);
    ll ans=1e18;
    for(int i=0;i<v.size();i++)
        ans=min(ans,solve(n,v[i].first)/v[i].second);
    cout<<ans;
    return 0;
}
```

### find the number of trailing zeros in the product of array

Given a array size of n, we need to find the total number of trailing zeros in the product of array

A **solution** is based on the fact that zeros are formed by a combination of 2 and 5 
Hence the number of zeros will depend on the number of pairs of 2’s and 5’s that can be formed

Ex.: {8 , 3 , 5 , 23 , 17 , 25 , 4 , 11}
2^3 * 3^1 * 5^1 * 23^1 * 17^1 * 5^2 * 2^2 * 11^1

In this example there are 5 twos and 3 fives. Hence, we shall be able to form only 3 pairs of (2 * 5).
Hence will be 3 Zeros in the product

```cpp
int countZeros(int a[], int n) 
{ 
    int count2=0,count5=0; 
    for (int i=0;i<n;i++) 
    { 
        while(!(a[i]&1))
            a[i]>>=1,count2++; 
        while(!(a[i]%5))
            a[i]=a[i]/5,count5++;
    }
    return min(count2,count5); 
}
```
