/*
Given a number ‘n’, write a function that prints the last digit of n’th (‘n’ can also be a large number) Fibonacci number

Input : n = 0
Output : 0

Input: n = 2
Output : 1

Input : n = 7
Output : 3


Method 1 : (Naive Method)
Simple approach is to calculate the n’th Fibonacci number and printing the last digit


*/

int f[1009];
int fib(ll n)
{
    if(n<2)return n;
    if(n==2)return 1;
    if(f[n])return f[n];
    int k = (n&1)?(n+1)/2:n/2;
    return f[n] = (n&1)?(fib(k)*fib(k)+fib(k-1)*fib(k-1))%mod
    :(((2*fib(k-1)+fib(k))*fib(k)))%mod;
}
int main()
{
    int t;cin>>t;while(t--)
    {
        ll n;cin>>n;
        cout<<fib(n)%10<<'\n';
    }
	return 0;
}
/*
Limitation of this implementation:
Fibonacci numbers grow exponentially fast
For example, the 200’th Fibonacci number equals 280571172992510140037611932413038677189525
And F(1000) does not fit into the standard C++ int type. To overcome this difficulty
instead of calculating n’th Fibonacci number
there is a direct algorithm to just calculate its last digit (that is, F(n) mod 10)

Method 2 : (Direct Method)
Look at the final digit in each Fibonacci number – the units digit:

0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, ...
Is there a pattern in the final digits?

0, 1, 1, 2, 3, 5, 8, 3, 1, 4, 5, 9, 4, 3, 7, 0, 7, ...

Yes!
It takes a while before it is noticeable. In fact, the series is just 60 numbers long and then it repeats
the same sequence again and again all the way through the Fibonacci series 

*/

ll fib(ll f[], ll n) 
{ 
    f[0] = 0; 
    f[1] = 1; 
    for (ll i = 2; i <= n; i++) 
        f[i] = (f[i - 1] + f[i - 2]) % 10; 
  
    return f[n]; 
} 
int findLastDigit(int n) 
{ 
    ll f[60] = {0}; 
    fib(f, 60); 
  
    return f[n % 60]; 
} 
int main () 
{ 
    ll n = 1; 
    cout << findLastDigit(n) << endl; 
    return 0; 
} 
