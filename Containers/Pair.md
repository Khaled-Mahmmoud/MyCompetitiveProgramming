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
