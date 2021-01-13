```cpp
 // prime numbers : numbers which are only divisible by themselves and one
bool isprime(int n)
{
     if (n < 2)
        return 0;
     if (!(n&1))
        return (n == 2);
     for (int i = 3; i * i <= n; i += 2)
        if (!(n%i))
            return 0;
     return 1;
}
// O(sqrt(n))

// Prime factor is the factor of the given number which is a prime number.
void primeFactors(int n)  
{  
    for(int i=2;i*i<=n;i++)  
    {  
        while(!(n%i))  
        {  
            cout<<i<<" ";  
            n/=i;  
        }  
    }    
    if (n>1)  
        cout<<n<<" ";  
} 
// O(sqrt(n))
```
