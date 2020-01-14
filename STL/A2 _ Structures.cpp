
// How to access structure elements?
// Structure members are accessed using dot (.) operator

#include <iostream> 
using namespace std; 
  
struct Point { 
    int x, y; 
}; 
  
int main() 
{ 
    struct Point p1 = { 0, 1 }; 
  
    // Accessing members of point p1 
    p1.x = 20; 
    cout << p1.x << " " << p1.y; // 20  1
  
    return 0; 
}
// What is an array of structures?
// Like other primitive data types, we can create an array of structures.

#include <iostream> 
using namespace std; 
  
struct Point { 
    int x, y; 
}; 
  
int main() 
{ 
    // Create an array of structures 
    struct Point arr[10]; 
  
    // Access array members 
    arr[0].x = 10; 
    arr[0].y = 20; 
  
    cout << arr[0].x << " " << arr[0].y; 
    return 0; 
} 

What is a structure pointer?
Like primitive types, we can have pointer to a structure. If we have a pointer to structure, members are accessed using
arrow ( -> ) operator instead of the dot (.) operator

#include <iostream> 
using namespace std; 
  
struct Point { 
    int x, y; 
}; 
  
int main() 
{ 
    struct Point p1 = { 1, 2 }; 
  
    // p2 is a pointer to structure p1 
    struct Point* p2 = &p1; 
  
    // Accessing structure members using structure pointer 
    
    cout << p2->x << " " << p2->y;       //    1   2
    return 0; 
}
