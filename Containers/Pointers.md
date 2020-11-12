# Pointers

Pointers store address of variables or a memory location.
  
General syntax 
```cpp
datatype *pointer_name; 
int x = 5;
int *ptr;
*ptr = &x;
```

### Pointer Arithmetic.
  
A limited set of arithmetic operations can be performed on pointers.
  
A pointer may be:

incremented ( ++ ), ptr++;
  
decremented ( — ), ptr--;
  
an integer may be added to a pointer ( + or += ), ptr = ptr + 5;
  
an integer may be subtracted from a pointer ( – or -= ), ptr = ptr - 5;
  
  
Note : Pointers contain addresses. Adding two addresses makes no sense, because there is no idea what it would point to.
  
```cpp
#include <bits/stdc++.h> 
int main() 
{ 
    int v[3] = {10, 100, 200}; 
    int *ptr; 
  
    // Assign the address of v[0] to ptr 
    // We can use ptr=&val[0];(both are same) 
    ptr = v; 
    for (int i = 0; i < 3; i++) 
    { 
        cout<<"Value of *ptr = "<<*ptr<<'\n';
        cout<<"address of ptr = ", ptr<<'\n'; 
        ptr++; 
    } 
} 
int main() 
{ 
    int v[3] = {10, 100, 200}; 
    int *ptr; 
  
    ptr = val ; 
    cout << "Elements of the array are: "; 
    cout << ptr[0] << " " << ptr[1] << " " << ptr[2]; 
  
    return; 
}
```
### Pointers and Multidimensional Arrays

int nums[2][3]  =  { {16, 18, 20}, {25, 26, 27} };
```
pointer notation       array notation          values
*(*nums)               nums[0][0]               16
*(*nums+1)             nums[0][1]               18
*(*nums+2)             nums[0][2]               20
*(*(nums+1))           nums[1][0]               25
*(*(nums+1)+1)         nums[1][1]               26
*(*(nums+1)+2)         nums[1][2]               27
In general, nums[i][j] is equivalent to *(*(nums+i)+j)
```
