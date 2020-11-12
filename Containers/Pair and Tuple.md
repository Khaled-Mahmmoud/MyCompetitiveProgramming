# Pair

Pair is a container that can be used to bind together a two values which may be of different types.

```cpp
pair <int, char> p1;                     // default declaration
pair <int, char> p2 (1, ‘a’);            // declaration and inititialization
pair <int, char> p3 (p2);               // copy of p2
```
We can also initialize a pair using make_pair() function. 
```cpp
p1 = make_pair(2, ‘b’);
```
To access the elements we use keywords.
```cpp
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
# Tuple

A tuple is an object that can hold a number of elements. The elements can be of different data types. The elements of tuples are initialized as arguments in order in which they will be accessed.

```cpp
#include<iostream> 
#include<tuple> 
using namespace std; 
int main() 
{ 
    tuple <char, int, float> geek; 
    geek = make_tuple('a', 10, 15.5); 
    cout<<get<0>(geek)<<" "<<get<1>(geek)<<" "<<get<2>(geek)<<'\n';  // a 10 15.5
    get<0>(geek) = 'b'; 
    get<2>(geek) =  20.5; 
    cout<<get<0>(geek)<<" "<<get<1>(geek)<<" "<<get<2>(geek);  // b 10 20.5
    
    int i_val; 
    char ch_val; 
    float f_val; 
    tuple <int,char,float> tup1(20,'g',17.5);
    tuple <int,char,float> tup2(10,'f',15.5); 
    tup1.swap(tup2); 
    tie(i_val,ch_val,f_val) = tup1;
    cout << i_val << " " << ch_val << " " << f_val;  // 20 g 17.5
    return 0; 
} 
```
