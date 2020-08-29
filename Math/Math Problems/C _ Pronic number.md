# Pronic number

Check if a given number is Pronic

A pronic number is a number which is the product of two consecutive integers, that is, a number of the form n(n + 1)

The first few Pronic numbers are:

0, 2, 6, 12, 20, 30, 42, 56, 72, 90, 110, 132, 156, 182, 210, 240, 272, 306, 342, 380, 420, 462 . . . . . .
```
                    *****
             ****   *****
      ***    ****   *****
**    ***    ****   *****
1*2   2*3     3*4    4*5
```
The numbers that can be arranged to form a rectangle are called Rectangular Numbers (also known as Pronic numbers)
```cpp
bool checkPronic(int x) 
{ 
  
    for (int i = 0;i <= sqrt(x);i++) 
        if (x == i * (i + 1))  
        return true; 
  
    return false; 
} 
int main(void) 
{ 
    int n;
    cin>>n;
    cout << checkPronic(n) << " ";    
    return 0; 
} 
```
Time Complexity : O(sqrt(n))
