## Deque
```cpp
#include<deque>
deque<int> dq = {2,5,7,3}
```
#### Iterators 

dq.begin() / dq.end() / dq.rbegin() / dq.rend() / dq.cbegin() / dq.cend() / dq.crbegin() / dq.crend()   

Complexity : O(1)

#### Element Access

dq.front() / dq.back() / dq.at(pos) / operator[pos] 

#### Capacity

dq.size() / dq.empty()    

dq.resize(n)

If n is smaller than the current container size, the content is reduced to its first n elements, removing those beyond.

If n is greater than the current container size, the content is expanded by inserting at the end as many elements as needed to reach a size of n.

Complexity : Linear on the number of elements inserted / erased 

#### Modifiers

dq.insert(iterator,val) OR dq.insert(iterator,n,val) OR dq1.insert(dq1 iterator,dq2 first iterator,dq2 last iterator)

Complexity : Linear on the number of elements inserted plus the number of elements after position

dq.erase(iterator) OR dq.erase(first iterator , last iterator)

Complexity : Linear on the number of elements erased plus the number of elements after the last element deleted 
(Linear on the size of deque before erase operation)

dq.emplace(iterator,val) || Insert a new element at position of iterator (faster)

Complexity : Linear on the number of elements after position

dq.push_back(val) / dq.push_front(val) / dq.emplace_back(val) / dq.emplace_front(val) / dq.pop_back()  / dq.pop_front() / dq1.swap(dq2) / swap(dq[0],dq[2])    

dq.clear() : Linear in size : Removes all elements from the deque , leaving the deque with a size of 0
