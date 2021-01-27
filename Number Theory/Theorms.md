```cpp
// Goldbach's conjecture : It states that every even number greater than 2 is the sum of two prime numbers
// Wilson's theorem: (p-1)!%p = p-1 IFF p is prime

// Legendre’s formula: largest power of prime number in n! is n/p + n/(p^2) + n/(p^3) + …… (Legendre’s formula)
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
// largest power of composite number in n!
K = p1^a1 p1^a2 p3^a3 ....
Answer = min( larg(n,p1)/a1 , larg(n,p2)/a2 , larg(n,p3)/a3 ,....)
*/

```
