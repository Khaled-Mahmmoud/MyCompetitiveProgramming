```cpp
int n = 6;
bitset<32> bit;
bit = n;
cout<<bit<<endl;     // 000000000000000000000000000110
for (int i = 0; i < 32; i++)
   cout<<bit[i];    // 011000000000000000000000000000
string s = bit.to_string();
cout<<endl<<s;       // 000000000000000000000000000110
    
// A structure is a user-defined data type in C/C++
struct myproject
{
    // Data Members 
    int roll; 
    int age; 
    int marks; 
      
    // Member Functions 
    void printDetails() 
    { 
         cout<<"Roll = "<<roll<<"\n"; 
         cout<<"Age = "<<age<<"\n"; 
         cout<<"Marks = "<<marks; 
    } 
};
// Declare structure variables
struct Point 
{ 
   int x, y; 
} p1;  // The variable p1 is declared with 'Point'
// OR
struct Point 
{ 
   int x, y; 
};  
int main() 
{ 
   Point p1;  // The variable p1 is declared like a normal variable 
}
// Access structure elements
struct Point 
{ 
    int x, y; 
}; 
int main() 
{ 
    Point p1 = { 0, 1 }; 
    // Accessing members of point p1 
    p1.x = 20; 
    cout << p1.x << " " << p1.y; // 20  1
}
// Array of structures
struct Point
{ 
    int x, y; 
}; 
int main() 
{ 
    // Create an array of structures 
    Point arr[10]; 
    // Access array members 
    arr[0].x = 10; 
    arr[0].y = 20; 
    cout << arr[0].x << " " << arr[0].y; 
    return 0; 
} 

```
