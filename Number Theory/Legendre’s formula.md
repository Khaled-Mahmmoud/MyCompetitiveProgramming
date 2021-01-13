```cpp
// largest power of prime number in n! is n/p + n/(p^2) + n/(p^3) + …… (Legendre’s formula)
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
// largest power of Composite number in n!
K = p1^a1 p1^a2 p3^a3 ....
Answer = min( larg(n,p1)/a1 , larg(n,p2)/a2 , larg(n,p3)/a3 ,....)
*/
```
