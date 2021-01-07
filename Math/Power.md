```cpp
// 10^8 = (10^2)^4 = (10^4)^2
// 10^9 = 10 * 10^8
int power(int x, unsigned int y) 
{ 
    if (y == 0) 
        return 1; 
    else if (y % 2 == 0) 
        return power(x, y / 2) * power(x, y / 2); 
    else
        return x * power(x, y / 2) * power(x, y / 2); 
} 
// O(4^log y)
    
// Above function can be optimized to O(log y) by calculating power(x, y/2) only once and storing it
int power(int x, unsigned int y) 
{ 
    int temp; 
    if( y == 0) 
        return 1; 
    temp = power(x, y/2); 
    if (y & 1) 
        return x*temp*temp;
    else
        return temp*temp;
} 
// O(log y)
// Better Solution
template<class T>
T power(T a, T b, T mod)
{
    T ans = 1;
    a %= mod;

    while (b) 
    {
        if (b & 1) ans = (ans * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }

    return ans;
}
// O(log(y))
/*
calc a^1 + a^2 + a^3 + ..... + a^k
(a^1+a^2+a^3+a^4+a^5+a^6)       = (a^1+a^2+a^3)+(a^1*a^3+a^2*a^3+a^3*a^3)
(a^1+a^2+a^3)+a^3*(a^1+a^2+a^3) = (a^1+a^2+a^3)*(1+a^3)
(a^1+a^2+a^3)+a^3*(a^1+a^2+a^3) = (a^1+a^2+a^3)*(1+ a^1+a^2+a^3 - (a^1+a^2))
= (a^1+a^2+a^3)*(1+a^3)

what about odd n (a^1+a^2+a^3+a^4+a^5+a^6+a^7)  = a + a*(a^1+a^2+a^3+a^4+a^5+a^6)
= a(1+(a^1+a^2+a^3+a^4+a^5+a^6))
*/
ll sumPower(ll a, int k)
{
    if (k == 0)
        return 0;
    if (k % 2 == 1)
        return a * (1 + sumPower(a, k - 1));
    ll half = sumPower(a, k / 2);
    return half * (1 + half - sumPower(a, k / 2 - 1));
}
// Time Complexity : O(log(k)) 

/*
Powers tower % M
Let’s compute: 2^3^4^5^6^7^8 % 56.
We can solve it using Euler theorem. let’s simplify it, compute 2^X % 56. where x is very large, e.g. x = 3^4^5^6^7^8.
Imagine we compute 2^i%M for i [0 - OO]. We know we have M mod values: [0 - M-1].
Pigeonhole: values repeat in maximum M + 1 iterations. 
Then computing X should have same value as one of the first powers in range [0-M-1]. But which 2^i%M correspond to 2^x%M ?
Let’s simulate it.
   i         0    1    2    3    4    5    6    7
2^i % 56     1    2    4    8    16   32   8    16
2^6 is same as 2^3. Then 2^7 must = 2^4...etc. {8,16,32} is cycle and {1,2,4} is precycle.
Let length of the cycle be L, and length of precycle be P.
Given some X, we can compute its i position. i = (X % L - P % L + L) % L + P -->> (X-P)%L + P
Then? Solve subproblem X % L in same manner. Then compute 2^i % M.
```
