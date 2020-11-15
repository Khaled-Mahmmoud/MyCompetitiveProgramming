# Sum of Fibonacci Numbers
Given a number positive number n, find value of f0 + f1 + f2 + …. + fn where fi indicates i’th Fibonacci number.


**Method** 1 (O(n)) : Brute Force approach is pretty straight forward, find all the Fibonacci numbers till f(n) and then add them up.

**Method** 2 (O(Log n)) : The idea is to find relationship between the sum of Fibonacci numbers and n’th Fibonacci number.

F(n) can be evaluated in O(log n) time Matrices.

```cpp
int fib(int n)
{
    if(n <= 1)
    return n;
    
    matrix transition = zero(2,2);
    transition[0][1] = transition[1][0] = transition[1][1] = 1;
    transition = power(transition , n);
    return transition[0][1];
}
int calculateSum(int n) 
{ 
    return fib(n+2) - 1; 
} 
int main() 
{ 
    int n = 4; 
    cout << "Sum of Fibonacci numbers is : "<< calculateSum(n) << endl; 
    return 0; 
} 
```
