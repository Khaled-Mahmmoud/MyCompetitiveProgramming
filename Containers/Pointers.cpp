/*
Pointers store address of variables or a memory location
  General syntax
datatype *var_name; 
An example pointer "ptr" that holds address of an integer variable or holds address of a memory whose value can
be accessed as integer values through "ptr"
int *ptr;
Pointer Expressions and Pointer Arithmetic
A limited set of arithmetic operations can be performed on pointers
A pointer may be:
incremented ( ++ )
decremented ( — )
an integer may be added to a pointer ( + or += )
an integer may be subtracted from a pointer ( – or -= )
Pointer arithmetic is meaningless unless performed on an array
Note : Pointers contain addresses. Adding two addresses makes no sense, because there is no idea what it would point to
Subtracting two addresses lets you compute the offset between these two addresses
*/
#include <bits/stdc++.h> 
int main() 
{ 
    // Declare an array 
    int v[3] = {10, 100, 200}; 
  
    // Declare pointer 
    int *ptr; 
  
    // Assign the address of v[0] to ptr 
    ptr = v; 
  
    for (int i = 0; i < 3; i++) 
    { 
        printf("Value of *ptr = %d\n", *ptr); 
        printf("address of ptr = %p\n\n", ptr); 
  
        // Increment pointer ptr by 1 
        ptr++; 
    } 
} 
/*
Output:
Value of *ptr = 10
address of ptr = 0x7ffcae30c710
Value of *ptr = 100
address of ptr = 0x7ffcae30c714
Value of *ptr = 200
address of ptr = 0x7ffcae30c718

Array Name as Pointers
An array name acts like a pointer constant. The value of this pointer constant is the address of the first element

*/
void geeks() 
{ 
    // Declare an array 
    int val[3] = { 5, 10, 15}; 
  
    // Declare pointer  
    int *ptr; 
  
    // Assign address of val[0] to ptr
    // We can use ptr=&val[0];(both are same) 
    ptr = val ; 
    cout << "Elements of the array are: "; 
    cout << ptr[0] << " " << ptr[1] << " " << ptr[2]; 
  
    return; 
} 
/*
Output:
Elements of the array are: 5 10 15
Pointers and Multidimensional Arrays
int nums[2][3]  =  { {16, 18, 20}, {25, 26, 27} };
In general, nums[i][j] is equivalent to *(*(nums+i)+j)
pointer notation       array notation          values
*(*nums)               nums[0][0]               16
*(*nums+1)             nums[0][1]               18
*(*nums+2)             nums[0][2]               20
*(*(nums+1))           nums[1][0]               25
*(*(nums+1)+1)         nums[1][1]               26
*(*(nums+1)+2)         nums[1][2]               27
/*
