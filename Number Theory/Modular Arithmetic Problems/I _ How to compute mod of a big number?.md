# How to compute mod of a big number?

Given a big number ‘num’ represented as string and an integer x, find value of “num % x” or “num mod x”
Output is expected as an integer.

Input:  num = "12316767678678",  a = 10
    
Output: num (mod a) ≡ 8
    
The idea is to process all digits one by one and use the property that xy (mod a) ≡ ((x (mod a) * y) (mod a))

```cpp
int mod(string num, int a) 
{ 
    int res = 0; 
    for (int i = 0; i < num.length(); i++) 
         res = (res*10 + (int)num[i] - '0') %a; 
    return res; 
} 
int main() 
{ 
    string num = "12316767678678"; 
    cout << mod(num, 10); 
    return 0; 
}
```
