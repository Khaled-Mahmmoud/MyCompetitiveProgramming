## Vector

```cpp
#include<vector>
vector<int> v (10,5) ;
vector<int> v = {2,4,5,9} ;
```


### Iterators 

v.begin() / v.end() / v.rbegin() / v.rend() / v.cbegin() / v.cend()  / v.crbegin()  / v.crend()    

Complexity : O(1)

### Element Access 

v.front() / v.back() / v.at(pos) / operator[pos] 

Complexity : O(1)

### Capacity 

v.size() / v.max_size() / v.empty()    

Complexity : O(1)

v.resize(n) : 

If n is smaller than the current container size, the content is reduced to its first n elements, removing those beyond.
   
If n is greater than the current container size, the content is expanded by inserting at the end as many elements as needed to reach a size of n
   
Complexity : Linear on initial + final sizes

### Modifiers 


v.assign(n,val) OR v1.assign(v2 first iterator ,v2 last iterator)

Complexity : Linear on initial + final sizes



v.insert(iterator,val) OR v.insert(iterator,n,val) OR v1.insert(v1 iterator,v2 first iterator,v2 last iterator)

Complexity : Linear on the number of elements inserted plus the number of elements after position



v.erase(iterator) OR v.erase(first iterator , last iterator)

**Erasing** an element in a vector is O(n) since once you remove the element you still need to shift all successive elements to fill the gap created. 
If a vector has n elements, then at the worst case you will need to shift n-1 elemets, hence the **complexity is O(n)**


v.emplace(iterator,val) : Insert a new element at position of iterator (faster)

Complexity : Linear on the number of elements after position


v.push_back(val) : O(1) : Add element at the end 


v.emplace_back(val) : O(1) : Add element at the end   (faster)



v.pop_back() : O(1) : Delete the last element 



v1.swap(v2) : O(1) : Sawp two container


swap(v[0],v[2]) : O(1) : Sawp two elements


v.clear() : Linear in size : Removes all elements , leaving the vector with a size of 0

### Member functions 

v1.operator=(v2) OR v1 = v2 : Linear in size : Assigns new contents , replacing its current contents, and modifying its size. 

## vector of boolean

```cpp
vector<bool>v;
```
like vector, emplace, and emplace_back, add to

v.flip() : Flips all values : Linear in size 

## Deque
```cpp
#include<deque>
deque<int> dq = {2,5,7,3}
```
### Iterators 

dq.begin() / dq.end() / dq.rbegin() / dq.rend() / dq.cbegin() / dq.cend() / dq.crbegin() / dq.crend()   

Complexity : O(1)

### Element Access

dq.front() / dq.back() / dq.at(pos) / operator[pos] 

### Capacity

dq.size() / dq.empty()    

dq.resize(n)

If n is smaller than the current container size, the content is reduced to its first n elements, removing those beyond.

If n is greater than the current container size, the content is expanded by inserting at the end as many elements as needed to reach a size of n.

Complexity : Linear on the number of elements inserted / erased 

### Modifiers

dq.insert(iterator,val) OR dq.insert(iterator,n,val) OR dq1.insert(dq1 iterator,dq2 first iterator,dq2 last iterator)

Complexity : Linear on the number of elements inserted plus the number of elements after position

dq.erase(iterator) OR dq.erase(first iterator , last iterator)

Complexity : Linear on the number of elements erased plus the number of elements after the last element deleted 
(Linear on the size of deque before erase operation)

dq.emplace(iterator,val) || Insert a new element at position of iterator (faster)

Complexity : Linear on the number of elements after position

dq.push_back(val) / dq.push_front(val) / dq.emplace_back(val) / dq.emplace_front(val) / dq.pop_back()  / dq.pop_front() / dq1.swap(dq2) / swap(dq[0],dq[2])    

dq.clear() : Linear in size : Removes all elements from the deque , leaving the deque with a size of 0
