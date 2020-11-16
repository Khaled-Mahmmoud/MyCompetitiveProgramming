# Find power of power under mod of a prime

Given four numbers A, B, C and M, where M is prime number. Our task is to find A^(B^C) (mod M)

Input  : A = 2, B = 4, C = 3, M = 23
    
Output : 6 2^(4^3)(mod 23) = 6
    
A Naive Approach is to calculate res = B^C and then calculate res % M by modular exponential
The problem of this approach is that we can’t apply directly mod M on B^C so we have to calculate
this value without mod M But if we solve it directly then we will come up with the large value
of exponent of A which will definitely overflow in final answer

An Efficient approach is to reduce the B^C to a smaller value by using the Fermat’s Little Theorem
and then apply Modular exponential

According the Fermat's little a^(M - 1) = 1 (mod M) if M is a prime.

So if we rewrite B^C as x*(M-1) + y, then the
task of computing ABC becomes Ax*(M-1) + y
which can be written as Ax*(M-1)*Ay.
From Fermat's little theorem, we know Ax*(M-1) = 1.
So task of computing ABC reduces to computing Ay

What is the value of y?
From BC = x * (M - 1) + y,
y can be written as BC % (M-1)

We can easily use the above theorem such that we can get
A ^ (B ^ C) % M = (A ^ y ) %  M

Now we only need to find two things as:-
1) y = (B ^ C) % (M - 1)
2) Ans = (A ^ y) % M

```cpp
unsigned int power(unsigned int x, unsigned int y, unsigned int p) 
{ 
    unsigned int res = 1;      
    x = x % p;  
    while (y > 0) 
    { 
        if (y & 1) 
            res = (res*x) % p; 
        y = y>>1;
        x = (x*x) % p; 
    } 
    return res; 
} 
  
unsigned int Calculate(unsigned int A, unsigned int B, unsigned int C, unsigned int M) 
{ 
    unsigned int res, ans; 
    res = power(B, C, M-1); 
    ans = power(A, res, M); 
  
    return ans; 
} 
int main() 
{   
    unsigned int A = 3, B = 9, C = 4, M = 19; 
    cout << Calculate(A, B, C, M);
    return 0; 
} 
```
Output: 18
    
Time Complexity: O(log(B) + log(C))
