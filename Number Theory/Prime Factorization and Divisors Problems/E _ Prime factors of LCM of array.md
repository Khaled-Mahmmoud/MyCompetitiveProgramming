# Prime factors of LCM of array

Given an array arr[] such that 1 <= arr[i] <= 10^12, the task is to find prime factors of LCM of array elements.

Input  : arr[] = {1, 2, 3, 4, 5, 6, 7, 8}

Output : 2 3 5 7
	
// LCM of n elements is 840 and 840 = 2*2*2*3*5*7 
	
// so prime factors would be 2, 3, 5, 7

A **simple solution** for this problem is to find LCM of n elements in array. First initialize lcm = 1
then iterate for each element in array and find the lcm of previous result with new element
using formula LCM(a, b) = (a * b) / gcd(a, b) i.e., lcm = (lcm * arr[i]) / gcd(lcm, arr[i])
After finding LCM of all n elements we can calculate all prime factors of LCM.

Since here constraint are large, we can not implement above method to solve this problem because while 
calculating LCM(a, b) we need to calculate a*b and if a,b both are of value 10^12 so it will exceed
the limit of integer size , We proceed for this problem in another way using sieve of sundaram and 
prime factorization of a number.
As we know if LCM(a,b) = k so any prime factor of a or b will also be the prime factor of ‘k’

```cpp
void g(long long n,set<int>&s)
{
    for(int i=2;i<=sqrt(n);i++)
    if(n%i==0)
    {
        s.insert(i);
        while(n%i==0)
        n/=i;
    }
    if(n>1)
    s.insert(n);
}
int main()
{
    int t;cin>>t;while(t--)
    {
        int n;cin>>n;
        long long a[n];set<int>s;
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++)
        g(a[i],s);
        for(auto&z:s)cout<<z<<' ';
        cout<<'\n';
    }
	return 0;
}
````
