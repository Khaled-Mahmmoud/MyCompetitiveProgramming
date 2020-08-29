# Find the number of solutions to the given equation

Given three integers A, B and C, the task is to find the count of values of X such that the following condition is satisfied.

X = B * Sum(X)^A + C where Sum(X) denotes the sum of digits of X and 1 < X < 10^9.

Input: A = 3, B = 2, C = 8

Output: 3

For X = 10, 2 * (1)^3 + 8 = 10

For X = 2008, 2 * (10)^3 + 8 = 2008

For X = 13726, 2 * (19)^3 + 8 = 13726

Input: A = 2, B = 3, C = 10

Output: 1

Approach: An important observation can be made here that the sum of digits can be atmost 81 (i.e. X = 999999999) and corresponding to each sum of digits, we get a single value of X. So we can iterate through each sum of digit and check if the resulting value of X is valid or not.

```cpp
int getCount(int a, int b, int c) 
{ 
    int count = 0; 
    for (int i = 1; i <= 81; i++) 
    { 
        int cr = b * pow(i, a) + c; 
        int tmp = cr; 
        int sm = 0; 
        while (tmp) 
        { 
            sm += tmp % 10; 
            tmp /= 10; 
        } 
        if (sm == i && cr < 1e9) 
            count++; 
    } 
    return count; 
} 
int main() 
{ 
    int a = 3, b = 2, c = 8; 
    cout << getCount(a, b, c); 
    return 0; 
} 
```
