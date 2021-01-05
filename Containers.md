```cpp
int n = 6;
bitset<32> bit;
bit = n;
cout<<bit<<endl;     // 000000000000000000000000000110
for (int i = 0; i < 32; i++)
   cout<<bit[i];    // 011000000000000000000000000000
string s = bit.to_string();
cout<<endl<<s;       // 000000000000000000000000000110
 /*   
<structure>
is a user-defined data type in C/C++
*/
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
/*
<Pair>
is a container that can be used to bind together a two values which may be of different types.
*/
pair <int, char> p1;                     // default declaration
pair <int, char> p2 (1, ‘a’);            // declaration and inititialization
pair <int, char> p3 (p2);               // copy of p2
// We can also initialize a pair using make_pair() function.

p1 = make_pair(2, ‘b’);
// To access the elements we use keywords.

cout << p2.first << ‘ ‘ << p2.second << endl;

#include <utility>
int main()
{
    pair <int, char> p;
    pair <int, char> p1(2, 'b');
    p = make_pair(1, 'a');
    cout << p.first << ' ' <<  p.second << endl;
    cout << p1.first << ' ' << p1.second << endl;
    return 0;
}
```
