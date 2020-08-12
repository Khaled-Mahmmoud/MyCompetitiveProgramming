
********************** lower_bound *************************

Returns an iterator pointing to the first element in the range [first,last] which greater than or equal val
if no such element , it's return iterator pointing to the end of the range
```cpp
auto it =lower_bound(first,last,val)   OR   auto it =lower_bound(first,last,val,pred)
```
Complexity : log2(N) where N is the distance between first and last

********************** upper_bound *************************

Returns an iterator pointing to the first element in the range [first,last] which compares greater than val
if no such element , it's return iterator pointing to the end of the range

```cpp
    vector<int>v={2,3,4,5,6};
    auto it = v.begin();
    it++;it++;it++;
    auto in=lower_bound(v.begin(),it,9);
    cout<<*in;                                  // 5
    auto it = upper_bound(first,last,val)   OR   auto it = upper_bound(first,last,val,pred)
```

Complexity : log2(N) where N is the distance between first and last

********************** binary_search *************************

Returns true if any element in the range [first,last] is equivalent to val, and false otherwise.
```cpp
binary_search(first,last,val)   OR  binary_search(first,last,val,pred)
```
Complexity :  the distance between first and last

********************** min *************************
```cpp
min(a,b) OR min(a,b,cmp)          O(1)
```
Returns the smallest of a and b. If both are equivalent, a is returned.

********************** max *************************
```cpp
max(a,b) OR max(a,b,cmp)          O(1)
```
Returns the largest of a and b. If both are equivalent, a is returned.

********************** min_element *************************
```cpp
min_element(first,last) OR min_element(first,last,cmp)
```
Returns an iterator pointing to the element with the smallest value in the range [first,last].
```cpp
int a[7] = {8,9,2,5,1,6,2}
cout<<*min_element(a,a+7); // 1
```
Complexity :  the distance between first and last.

********************** max_element *************************
```cpp
max_element(first,last) OR max_element(first,last,cmp)
```
Returns an iterator pointing to the element with the largest value in the range [first,last].

Complexity :  the distance between first and last


****************** find *****************

Searches the container for an element equivalent to val and returns an iterator to it if found
otherwise it returns an iterator to container::end.

```cpp
it = s.find(3) // where s is set
it = find(v.begin,v.end(),3)  // where v is vector
```
Complexity : linear for sequence conainers
Logarithmic for associative and unordered_associative containers 

How to find the pair in the set using first element of the pair only?
```cpp
set < pair<int,int> >st;
st.insert(make_pair(1,2));
st.insert(make_pair(4,5));
st.insert(make_pair(7,8));

auto it = find_if(st.begin(),st.end(),[](const pair<int,int>& p ){ return p.first == 1;});
```

****************** reverse *****************

Reverses the order of the elements in the range [first,last]
```cpp
  vector<int> myvector;
  for(int i=1; i<10; ++i) myvector.push_back(i);   // 1 2 3 4 5 6 7 8 9
  reverse(myvector.begin(),myvector.end());   // 9 8 7 6 5 4 3 2 1
```
Complexity : Linear in half the distance between first and last : Swaps elements.
