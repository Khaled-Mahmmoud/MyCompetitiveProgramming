/*
GCD of two numbers when one of them can be very large
Given two numbers ‘a’ and ‘b’ such that (0 <= a <= 10^12 and b <= b < 10^250). Find the GCD of two given numbers.

Examples :

Input: a = 978 
       b = 89798763754892653453379597352537489494736
Output: 6

Input: a = 1221 
       b = 1234567891011121314151617181920212223242526272829
Output: 3

Solution : In the given problem, we can see that first number ‘a’ can be handled by long long int data type but second number ‘b’
can not be handled by any int data type. Here we read second number as a string and we will try to make it less than or equal to ‘a’ 
by taking it’s modulo with ‘a’.
*/


ll gcd(ll a,ll b)
{
    if(!b)return a;
    return gcd(b,a%b);
}
ll reduce(int a,string b)
{
    ll mod=0;
    for(int i=0;b[i];i++)
        mod=(mod*10+(b[i]-'0'))%a;
    return mod;
}
int main()
{
    ll a;string b;cin>>a>>b;
    int c = reduce(a,b);
    cout<<gcd(a,c);
    return 0;
}
