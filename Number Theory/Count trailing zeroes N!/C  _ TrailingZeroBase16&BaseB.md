# Trailing Zero Base 16 & Base B

Number of trailing zeroes in base 16 representation of N!

Given an integer N, the task is to find the number of trailing zeroes in the base 16 representation of the factorial of N
|Input|Output|
|6|1|

6! = 720 (base 10) = 2D0 (base 16)

(720)10 = ( 2D0 )16

16   |   720           

16   |   45   |  0        720 % 16 = 0

16   |   2    |  D      

16   |   0    |  2      

observe it's 0 when n % 16 == 0

Number of trailing zeroes would be the highest power of 16 in the factorial of N in base 10
We know that 16 = 2^4. So, the highest power of 16 is equal to the highest power 2 in the factorial of N divided by 4
n <= 1e18
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

Given two positive integers B and N . The task is to find the number of trailing zeroes in b-ary (base B) representation of N!

`6! = (720)10 = (880)9 = (246)7`. Suppose, the base is 10 i.e., decimal then we’ll have to calculate the highest power of 10 that divides N! 
not easy to get highest power of 10 , so we get highest power of 10's prime factors 
but 10 = 2 * 5 , so we answer is minimum between the highest power of 2 and the highest power of 5
Hence, problem reduces to finding the highest power of B in N!
n <= 1e18 & b <= 1e12

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
