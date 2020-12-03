
### Iterators

s.begin()    || O(1) || Returns an iterator pointing to the first element 

s.end()      || O(1) || Returns an iterator pointing to the last element 

s.rbegin()   || O(1) || Returns a reverse iterator pointing to the last element 

s.rend()     || O(1) || Returns a reverse iterator pointing to the first element 

s.cbegin()   || O(1) || Returns a const_iterator pointing to the first element 

s.cend()     || O(1) || Returns a const_iterator pointing to the last element 

s.crbegin()  || O(1) || Returns a const_reverse_iterator pointing to the last element 

s.crend()    || O(1) || Returns a const_reverse_iterator pointing to the first element 

### Element Access

s.front()    || O(1) || Returns a reference pointing to the first element 

s.back()     || O(1) || Returns a reference pointing to the last element 

s.at(pos)    || O(1) || Returns a reference to the element at position pos (O-Indexed)

operator[pos]|| O(1) || Returns a reference to the element at position pos (O-Indexed)

### Capacity

s.size()     || O(1) || Return length of string

s.length()   || O(1) || Return length of string 

s.max_size() || O(1) || Returns the maximum number of characters that the string can hold

s.empty()    || O(1) || Returns whether the string is empty 

s.clear()    || O(1) || Clear string

s.resize(n)  ||  Change size of string to n size
{
   If n is smaller than the current string size, the content is reduced to its first n elements, removing those beyond
   If n is greater than the current string size, the content is expanded by inserting at the end as many elements as
   needed to reach a size of n (charater inserted is empty character)
   Complexity : linear in the new string length 
}

### Modifiers

**assign**

Assigns a new value to the string , replacing its current contents
```cpp
int main ()
{
    string str;
    string base="The quick brown fox jumps over a lazy dog.";

    str.assign(base);
    cout << str << '\n';  // The quick brown fox jumps over a lazy dog

   str.assign(base,10,9);
   cout << str << '\n';           // "brown fox"
   
   str.assign(base,9);
   cout << str << '\n';           // "The quick"

  str.assign("c-string");
  cout << str << '\n';            // "c-string"
  
  str.assign("pangrams are cool",7);
  cout << str << '\n';            // "pangram"


  str.assign(10,'*');
  cout << str << '\n';         // "**********"

  str.assign<int>(10,0x2D);
  std::cout << str << '\n';         // "----------"

  str.assign(base.begin()+16,base.end()-12);
  cout << str << '\n';         // "fox jumps over"

  return 0;
}
```
Complexity : Linear on initial + final sizes

**insert**

Inserts additional characters into the string right before the character indicated by pos (or p):
```cpp
#include <iostream>
#include <string>
int main ()
{
  std::string str="to be question";
  std::string str2="the ";
  std::string str3="or not to be";
  std::string::iterator it;
  // used in the same order as described above:
  str.insert(6,str2);                 // to be (the )question
  str.insert(6,str3,3,4);             // to be (not )the question
  str.insert(10,"that is cool",8);    // to be not (that is )the question
  str.insert(10,"to be ");            // to be not (to be )that is the question
  str.insert(15,1,':');               // to be not to be(:) that is the question
  it = str.insert(str.begin()+5,','); // to be(,) not to be: that is the question
  str.insert (str.end(),3,'.');       // to be, not to be: that is the question(...)
  str.insert (it+2,str3.begin(),str3.begin()+3); // to be, or not to be: that is the question...
}
```
Complexity : linear in the new string length

**operator+=**

Extends the string by appending additional characters at the end of its current value
```cpp
  std::string name ("John");
  std::string family ("Smith");
  name += " K. ";         // c-string
  name += family;         // string
  name += '\n';           // character
  cout<<name;            // John K. Smith
```
Complexity : linear in the new string length


**append**

Extends the string by appending additional characters at the end of its current value:
```cpp
  std::string str;
  std::string str2="Writing ";
  std::string str3="print 10 and then 5 more";

  // used in the same order as described above:
  str.append(str2);                       // "Writing "
  str.append(str3,6,3);                   // "10 "
  str.append("dots are cool",5);          // "dots "
  str.append("here: ");                   // "here: "
  str.append(10u,'.');                    // ".........."
  str.append(str3.begin()+8,str3.end());  // " and then 5 more"
  str.append<int>(5,0x2E);                // "....."

  std::cout << str << '\n';              // Writing 10 dots here: .......... and then 5 more.....
```
Complexity : linear in the new string length

**push_back**

Appends character c to the end of the string, increasing its length by one s.push_back('k')

Generally amortized constant, but up to linear in the new string length.

**pop_back**

Erases the last character of the string, effectively reducing its length by one.

Complexity : constant.


**Swap**

Swap string values 

s1.swap(s2)

Complexity : constant

**replace**

Replaces the portion of the string that begins at character pos and spans len characters
```cpp
  string base="this is a test string.";
  string str2="n example";
  string str3="sample phrase";
  string str4="useful.";

  replace signatures used in the same order as described above:

  Using positions:               
  string str=base;                 "this is a test string."
  str.replace(9,5,str2);           "this is an example string." 
  str.replace(19,6,str3,7,6);      "this is an example phrase." 
  str.replace(8,10,"just a");      "this is just a phrase."     
  str.replace(8,6,"a shorty",7);   "this is a short phrase."    
  str.replace(22,1,3,'!');         "this is a short phrase!!!"  

  Using iterators:                                              
  str.replace(str.begin(),str.end()-3,str3);                       "sample phrase!!!"      
  str.replace(str.begin(),str.begin()+6,"replace");                "replace phrase!!!"     
  str.replace(str.begin()+8,str.begin()+14,"is coolness",7);       "replace is cool!!!"    
  str.replace(str.begin()+12,str.end()-4,4,'o');                   "replace is cooool!!!"  
  str.replace(str.begin()+11,str.end(),str4.begin(),str4.end());   "replace is useful."    
  std::cout << str << '\n';
```
Complexity : linear in the new string length

**erase**

Erases part of the string, reducing its length
```cpp
  std::string str ("This is an example sentence.");
  std::cout << str << '\n';
                                            "This is an example sentence."
  str.erase (10,8);                                    ^^^^^^^^
  std::cout << str << '\n';
                                            "This is an sentence."
  str.erase (str.begin()+9);                          ^
  std::cout << str << '\n';
                                            "This is a sentence."
  str.erase (str.begin()+5, str.end()-9);         ^^^^^
  std::cout << str << '\n';
                                            "This sentence."
```
Complexity : linear in the new string length

**find**

Searches the string for the first occurrence of the sequence specified by its arguments.

Return Value : 
The position of the first character of the first match. If no matches were found, the function returns string::npos.
```cpp
string str = "khaledmahmoudmah",pat = "mah";

if(str.find(pat)!=string::npos)
     cout<<"found";
else
     cout<<"not found";
```
Complexity :  str.size() * pat.size()

### operations

 **substr**
 ```cpp
 std::string str="We think in generalities, but we live in details.";
                                           // (quoting Alfred N. Whitehead)

  std::string str2 = str.substr (3,5);     // "think"

  std::size_t pos = str.find("live");      // position of "live" in str

  std::string str3 = str.substr (pos);     // get from "live" to the end

  std::cout << str2 << ' ' << str3 << '\n';  // think live in details.
```
Complexity : linear in the new string length


**strncmp**

int x = strncmp (str1, str2, num);
str1 : C string to be compared.
str2 : C string to be compared.
num : Maximum number of characters to compare.

Returns an integral value indicating the relationship between the strings:
```
return value                	indicates
   <0	                 the first character that does not match has a lower value in str1 than in str2
    0	                 the contents of both strings are equal
   >0	                 the first character that does not match has a greater value in str1 than in str2
```
```cpp
int x = strncmp ("sol", "kmsol" , 3); return 8
int x = strncmp ("sol", "kmsol" + 2 , 3); return 0
int x = strncmp ("hsol" + 1 , "kmsol" + 2 , 3); return 0

int main() 
{ 
    string su = "Jatin Goyal"; 
  
    transform(su.begin(), su.end(), su.begin(), ::toupper);  // JATIN GOYAL
  
    transform(su.begin(), su.end(), su.begin(), ::tolower);  // jatin goyal
  
    return 0; 
} 
```

To sort a range[l,r] of string where 1<=l<=r<=str.size()
```cpp
sort(&str[l-1], &str[r]);
sort(str.begin() + l - 1, str.begin() + r);
```

To reverse a range[l,r] of string where 1<=l<=r<=str.size()
```cpp
reverse(&str[l-1], &str[r]);
reverse(str.begin() + l - 1, str.begin() + r);
```


