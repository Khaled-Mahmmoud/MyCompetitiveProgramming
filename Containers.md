```cpp
/*
Sequence Containers: array - vector - deque - list - forward list
Associative Containers: map - multimap- set - multiset
Unordered Associative Containers: unordered_map - unordered_multimap - unordered_set - unordered_multiset
Container Adaptors: stack - queue - priority_queue 

Random_Access Iterator: vector - array - deque
Bidirectional Iterator: map - multimap- set - multiset - list 
Bidirectional Iterator: unordered_map - unordered_multimap - unordered_set - unordered_multiset
Forward Iterator: Forward Iterator
No Iterator Supported: stack - queue - priority_queue
*/
int n = 6;
bitset<32> bit;
bit = n;
cout<<bit<<endl;     // 000000000000000000000000000110
for (int i = 0; i < 32; i++)
   cout<<bit[i];    // 011000000000000000000000000000
bit.set();				// 11111111111111111111
bit.flip();				// 00000000000000000000
bit.set(15);				
bit.flip(0);		
bit.set(15, 3);
bit.count();				// Returns the number of bits that are set.
if(x[2] == 0);
x[0] = 1;
string s = bit.to_string();
cout<<endl<<s;       // 000000000000000000000000000110
int x = bit.to_ulong(); // 6 
ll  z = bit.to_ullong(); // 6

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
int main()
{
    pair <int, char> p;
    pair <int, char> p1(2, 'b');
    p = make_pair(1, 'a');
    cout << p.first << ' ' <<  p.second << endl;
    cout << p1.first << ' ' << p1.second << endl;
    return 0;
}
/*
lower_bound: Returns an iterator pointing to the first element in the range [first,last] 
which greater than or equal val if no such element , it's return iterator pointing to the end of the range.
this range should be sorted.
*/
lower_bound(v.begin(),v.end(),x);
vector<pair<int,int>>v;
pair<int,int> p = {fir,sec};
lower_bound(v.begin(),v.end(),{fir,sec});  // Compiler erro
lower_bound(v.begin(),v.end(),p);   // correct
// Complexity : log(n)

/*
upper_bound: Returns an iterator pointing to the first element in the range [first,last] 
which greater than val if no such element , it's return iterator pointing to the end of the range. 
this range should be sorted.
*/
upper_bound(v.begin(),v.end(),x);
vector<pair<int,int>>v;
pair<int,int> p = {fir,sec};
upper_bound(v.begin(),v.end(),{fir,sec});  // Compiler erro
upper_bound(v.begin(),v.end(),p);   // correct
Complexity : log(n) 

// find: Searches the container for an element equivalent to val and returns an iterator to it if found 
otherwise it returns an iterator to container::end
it = s.find(3) // where s is set
it = find(v.begin,v.end(),3)  // where v is vector
// Complexity : linear for sequence conainers and Logarithmic for associative and unordered_associative containers

// How to find the pair in the set using first element of the pair only?
bool pred(const pair<int,int>&p)
{
     return p.first == k;
}
auto it = find_if(st.begin(),st.end(),pred);

cout<<*min_element(a,a+7); // O(n)
cout<<*max_element(v.begin(),v.end()); //O(n)
reverse(myvector.begin(),myvector.end());     // O(n)

fill(a,a+n,8); // O(n)
fill (v.begin(),v.begin(),-5); // O(n)
fill(str.begin(),str.end(),'x'); // O(n)
 


vector<int>v={1,1,2,2,3,3,4,5}; // Array should be sorted
auto it = unique(v.begin(),v.end()); // O(n)
v.resize(it-v.begin());
for(int i=0;i<v.size();i++)
     cout<<v[i]<<' ';     // 1 2 3 4 5

// convert string to lowercase 
transform(str.begin(),str.end(),str.begin(),::tolower); // O(n)
// covert string to uppercase 
transform(str.begin(),str.end(),str.begin(),::toupper); // O(n)

char c = tolower(str[i]);
char c = toupper(str[i]);

sqrt(7) = 2.64575 // Returns the square root of x
cbrt(43) = 3.5033 // Returns the cubic root of x
pow(32.01 , 1.54) =   208.036691 // Returns base raised to the power exponent.


int abs (int n);
long long llabs (long long n);
double fabs (double x);

advance (it,n); // Advances the iterator it by n element positions
// Complexity : Constant for random-access iterators . Otherwise, linear in n.

// Calculates the number of elements between first and last
auto first = v.begin();
auto last = v.end();
cout << distance(first,last);
// Complexity : Constant for random-access iterators . Otherwise, linear in n.


string s = to_string(m); // converts integer/ll/double to string
int m = stoi(s);   // converts string to integer
ll m = stoll(s);   // converts string to ll
double m = stold(s);   // converts string to double


// We can use memset() to set all values as 0 or -1.
memset(a,0,sizeof a); // one-d array or two-d array
memset(str,'-',6);

int val[] = {1,2,3,4,5},result[5];
partial_sum(val, val+5, result); // O(n), for array[] only.
for(int i=0; i<5; i++) 
cout<< result[i] << ' ';  // 1 3 6 10 15

```
