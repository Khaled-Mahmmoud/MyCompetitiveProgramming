# check Integer Primality

prime numbers : numbers which are only divisible by themselves and one

Complexity: O(sqrt(n))
```cpp
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
int main()
{
    int n;cin>>n;
    if(isprime(n))
        cout<<"prime";
    else 
        cout<<"not prime";
    return 0;
}
```
