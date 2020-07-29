# Power 

10^8 = (10^2)^4 = (10^4)^2

10^9 = 10 * 10^8

```cpp
int power(int x, unsigned int y) 
{ 
    if (y == 0) 
        return 1; 
    else if (y % 2 == 0) 
        return power(x, y / 2) * power(x, y / 2); 
    else
        return x * power(x, y / 2) * power(x, y / 2); 
} 
```
Time Complexity: O(y)
    
Above function can be optimized to O(log y) by calculating power(x, y/2) only once and storing it

```cpp
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
```
Time Complexity of optimized solution: O(log y)
The recursive solutions are generally not preferred as they require space on
call stack and they involve function call overhead

Here the Best Solution
```cpp
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
```
Time complexity : O(log(y))
