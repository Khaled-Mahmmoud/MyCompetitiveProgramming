
# Number of trailing zeroes in base 16 representation of N!

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
