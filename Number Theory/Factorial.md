# Factorial

Factorial of a non-negative integer, is multiplication of all integers smaller than or equal to n

For example factorial of 6 is 6*5*4*3*2*1 which is 720

`!n = n * (n-1) * (n-2) * (n-3) * .... * 1`

!4 = 4 * 3 * 2 * 1

!6 = 6 * 5 * 4 * 3 * 2 * 1

Recursive Solution:

Factorial can be calculated using following recursive formula

n! = n * (n-1)!
  
0! = 1 
  
1! = 1
  
```cpp
int factorial(int n) 
{ 
    if(n == 0) 
        return 1; 
    return n * factorial(n - 1); 
} 
int factorial(int n) 
{ 
    int res = 1; 
    for(int i = 1; i <= n; i++) 
        res *= i; 
    return res; 
} 
```
**Facts**

- n! % x = 0 where x <= n
- Wilson's theorem: (p-1)!%p = p-1 IFF p is prime
- 2! is the only prime factorial

### What about implementing a big factorial? e.g. 500!

Overflow. Use Big integers...or just simplified code (we just need *)

Create a vector of max length expected

Intialize it to 1

From i = 2 to N
		
Multiply i in every cell

For every cell, if its value > 9, handle its carry (v%10, v/10)

For last cell, check if it has carry (typically will have), and put it in next cell, AS LONG AS there is a carry
```cpp
vector<string>v(1009);
int multiply(int x, int res[], int res_size) 
{ 
    int carry = 0; 
    for (int i=0; i<res_size; i++) 
    { 
        int prod = res[i] * x + carry; 
        res[i] = prod % 10;   
        carry  = prod/10;     
    } 
    while (carry) 
    { 
        res[res_size++] = carry%10; 
        carry = carry/10; 
    } 
    return res_size; 
} 
void fact() 
{ 
    int res[3000];  // size of factorial(1000) equals 2568

    res[0] = 1; 
    int res_size = 1; 
  
    for (int x=1; x<=n; x++) 
    {
        res_size = multiply(x, res, res_size);
        for (int i=res_size-1; i>=0; i--) 
        v[x].push_back(res[i]+'0'); 
    }
} 
```
### Number of factorial digits?
 
how many digit for 1000? 1050? 9000 ? 9999? 4 digits. Use 1 + (int)log10(n)

pow(10, log10(X) ) = X 

log(a * b) = log(a)+log(b)

log(n!) = log(1) + log(2) .... log(n)
