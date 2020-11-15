# Nth Even Fibonacci Number

Given a value n, find the n’th even Fibonacci Number

The even number Fibonacci sequence is, 0, 2, 8, 34, 144, 610, 2584…. We need to find n’th number in this sequence
If we take a closer look at Fibonacci sequence, we can notice that every third number in sequence is even 
and the sequence of even numbers follow following recursive formula

Recurrence for Even Fibonacci sequence is: EFn = 4EFn-1 + EFn-2
 
with seed values EF0 = 0 and EF1 = 2.

```cpp
int evenFib(int n) 
{ 
    int ef1 = 0, ef2 = 2, ef3;  
    if(n==0)
      return ef1;
    for(int i=2;i<=n;i++)
    { 
        ef3 = 4*ef2 + ef1; 
        ef1 = ef2; 
        ef2 = ef3; 
    } 
    return ef2; 
} 
int main () 
{ 
    int n = 7; 
    cout << evenFib(n);  
    return 0; 
}
```
Complexity : O(n)
