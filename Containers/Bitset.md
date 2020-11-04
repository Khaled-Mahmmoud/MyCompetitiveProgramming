# Bitset
```cpp
#include <bitset>
```
bitset <object_size> object_name;

A bitset stores bits

**Access**

operator[i]   || O(1) || Returns a reference to the element at position i  (O-Indexed)

b.count()     || O(n) || Returns the number of bits in the bitset that are set 

b.size()      || O(1) || Returns the number of bits

bool f = b.test(i)     || O(1) || Returns whether the bit at position pos is set

bool f = b.any()       || O(n) || Returns whether any of the bits is set

bool f = b.none()      || O(n) || Returns whether none of the bits is set

bool f = b.all()       || O(n) || Returns whether all of the bits in the bitset are set


**Bit operations**

**(Sets bits)**

(1) all bits Sets (to one) all bits in the bitset

(2) single bit Sets val as the value for the bit at position pos

pos : Order positions are counted from the rightmost bit, which is order position 0.

Val : Value to store in the bit (Either true or false)

```cpp
   bitset<4> foo;                   // 0000
   cout << foo.set() << '\n';       // 1111   O(n)
   cout << foo.set(2,0) << '\n';    // 1011   O(1)
```

**(Reset bits)**

Resets bits to zero:

(1) all bits Resets (to zero) all bits in the bitset

(2) single bit Resets (to zero) the bit at position pos

pos : Order positions are counted from the rightmost bit, which is order position 0.

```cpp
      bitset<4> foo (string("1011"));
      cout << foo.reset(1) << '\n';    // 1001  O(1)
      cout << foo.reset() << '\n';     // 0000  O(n)
```

**(Flip bits)**

Flips bit values converting zeros into ones and ones into zeros:

(1) all bits Flips all bits in the bitset

(2) single bit Flips the bit at position pos

```cpp
   bitset<4> foo (string("0001"));
   cout << foo.flip(2) << '\n';     // 0101
   cout << foo.flip() << '\n';      // 1010
```

**(to_string)**

Constructs a basic_string object that represents the bits in the bitset as a succession of zeros and/or ones

```cpp
    bitset<4> mybits;          // mybits: 0000
    mybits.set();              // mybits: 1111

    string mystring = mybits.to_string();  //  O(n)
    cout << "mystring: " << mystring << '\n'; // 1111
```

**(to_ulong)**

Returns an unsigned long with the integer value that has the same bits set as the bitset

```cpp
  bitset<4> foo;         // foo: 0000
  foo.set();              // foo: 1111
  cout << foo << " as an integer is: " << foo.to_ulong() << '\n'; // 1111  as an iteger is: 15  O(n)
```

**(to_ullong)**

Returns an unsigned long long with the integer value that has the same bits set as the bitset
```cpp
  bitset<4> foo;         // foo: 0000
  foo.set();              // foo: 1111
  cout << foo << " as a long long is: " << foo.to_ullong() << '\n'; // 1111  as a long long is: 15 O(n)


    bitset<8>bs;
    int x=10;
    bs=x; // OR bs|=x;
    cout<<bs;          00001010
    
```
    
**applicable operators**

```cpp
  std::bitset<4> foo (std::string("1001"));
  std::bitset<4> bar (std::string("0011"));

  std::cout << (foo^=bar) << '\n';       // 1010 (XOR,assign)
  std::cout << (foo&=bar) << '\n';       // 0010 (AND,assign)
  std::cout << (foo|=bar) << '\n';       // 0011 (OR,assign)

  std::cout << (foo<<=2) << '\n';        // 1100 (SHL,assign)
  std::cout << (foo>>=1) << '\n';        // 0110 (SHR,assign)

  std::cout << (~bar) << '\n';           // 1100 (NOT)
  std::cout << (bar<<1) << '\n';         // 0110 (SHL)
  std::cout << (bar>>1) << '\n';         // 0001 (SHR)

  std::cout << (foo==bar) << '\n';       // false (0110==0011)
  std::cout << (foo!=bar) << '\n';       // true  (0110!=0011)

  std::cout << (foo&bar) << '\n';        // 0010
  std::cout << (foo|bar) << '\n';        // 0111
  std::cout << (foo^bar) << '\n';        // 0101
```

```cpp

int main()
{
    int n=6;
    bitset<64> bit;
    bit = n;
    cout<<bit<<endl;    // 0000000000000000000000000000000000000000000000000000000000000110
    for (int i = 0; i < 64; i++)
        cout<<bit[i];    // 0110000000000000000000000000000000000000000000000000000000000000
    string s = bit.to_string();
    cout<<endl<<s;      // 0000000000000000000000000000000000000000000000000000000000000110
}
```
