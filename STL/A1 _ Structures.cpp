/*
What is a structure?
A structure is a user-defined data type in C/C++. A structure creates a data type that can be used to group items of possibly different 
types into a single type
*/
struct myproject  // where struct is sruct keyword and myproject is structure tag
{
    char name[10];   // member or fields of structure
    int id[5];       // member or fields of structure
    float salary;    // member or fields of structure
};
// How to create a structure ?
// The ‘struct’ keyword is used to create a structure . The general syntax to create a structure is as shown below :

struct structureName{
    member1;
    member2;
    member3;
    .
    .
    .
    memberN;
};

// Structures in C++ can contain two types of members:

// Data Member: These members are normal C++ variables. We can create a structure with variables of different data types in C++.
// Member Functions: These members are normal C++ functions. Along with variables, we can also include functions inside a structure 
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
//  How to declare structure variables?
// A structure variable can either be declared with structure declaration or as a separate declaration like basic types.
// A variable declaration with structure declaration. 
struct Point 
{ 
   int x, y; 
} p1;  // The variable p1 is declared with 'Point' 
  
  
// A variable declaration like basic data types 
struct Point 
{ 
   int x, y; 
};  
  
int main() 
{ 
   struct Point p1;  // The variable p1 is declared like a normal variable 
}
//Note: In C++, the struct keyword is optional before in declaration of a variable
