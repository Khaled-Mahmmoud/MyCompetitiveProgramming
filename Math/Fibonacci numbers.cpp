/*

The Fibonacci numbers are the numbers in the following integer sequence.
0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ……..

In mathematical terms, the sequence Fn of Fibonacci numbers is defined by the recurrence relation



    Fn = Fn-1 + Fn-2
with seed values   F0 = 0 and F1 = 1

*/


vector<ll> f(10000);
ll fib(ll n)
{
    if(n<2)
    return n;
    if(n==2)
        return 1;
    if(f[n])
        return f[n];
    ll k = (n&1) ? (n+1)/2 : n/2 ;
    return f[n] =( (n&1) ? (fib(k)*fib(k) + fib(k-1)*fib(k-1)) : (2*fib(k-1)+fib(k))*fib(k) )%mod;

}
// Complexity : O(log(n))
