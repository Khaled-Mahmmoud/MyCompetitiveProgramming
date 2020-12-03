## Containers 

**Sequence Containers**

Sequence containers implement data structures which can be accessed sequentially
```
1- array            Static contiguous array
2- vector           Dynamic contiguous array
3- deque            Double-ended queue
4- list             Doubly-linked list
5- forward list     Singly-linked list
```
**Associative Containers**

Associative containers implement sorted data structures that can be quickly searched (O(log n) complexity)
```
1- map              Collection of key-value pairs, sorted by keys, keys are unique
2- multimap         Collection of key-value pairs, sorted by keys, keys are multi
3- set              Collection of unique keys, sorted by keys
4- multiset         Collection of multi keys, sorted by keys
```
**Unordered Associative Containers**

Unordered associative containers implement unsorted (hashed) data structures that can be quickly searched 
(O(1) amortized, O(n) worst-case complexity)
```
1- unordered_map           Collection of key-value pairs, hashed by keys, keys are unique
2- unordered_multimap      Collection of key-value pairs, hashed by keys
3- unordered_set           Collection of unique keys, hashed by keys
4- unordered_multiset      Collection of keys, hashed by keys
```
**Container Adaptors**

Container adaptors provide a different interface for sequential containers
```
1- stack                   Adapts a container to provide stack (LIFO data structure) 
2- queue                   Adapts a container to provide queue (FIFO data structure) 
3- priority_queue          Adapts a container to provide priority queue
```

for Associative container(map and unordered_map) supported random access (at,[])

static memory allocation ==>> fixed size ==>>  int a[10]
dynamic memory allocation ==>> size varies ==>>  stack , queue , vector , deque

### Iterators 

An iterator is an object (like a pointer) that points to an element inside the container. We can use iterators to move through
the contents of the container.

Every Container has a iterator and a const_iterator.

set<int>::iterator it;           // access to Container elements OR modify OR assign 

set<int>::const_iterator it;     //access to Container elements (Read_only)

```
container                                   types of iterator supported
------------------------------------------------------------------------
vector                                      Random_Access Iterator
array                                       Random_Access Iterator
deque                                       Random_Access Iterator

map                                         Bidirectional Iterator
multimap                                    Bidirectional Iterator
unoredered_map                              Bidirectional Iterator
unordered_multimap                          Bidirectional Iterator
set                                         Bidirectional Iterator
multiset                                    Bidirectional Iterator
unordered_set                               Bidirectional Iterator
unordered_multiset                          Bidirectional Iterator
list                                        Bidirectional Iterator

forward_list                                Forward Iterator

stack                                       No Iterator Supported
queue                                       No Iterator Supported
priority_queue                              No Iterator Supported
```

Types of iterators : Based upon the functionality of the iterators, they can be classified into five major categories:

**Input Iterators**    ===>>>   They are the weakest of all the iterators and have very limited functionality. They can only be used in 
a single-pass algorithms, i.e.,those algorithms which process the container sequentially such that no element is accessed more than once
int x=*it;

**Output Iterators**   ===>>>   Just like input iterators, they are also very limited in their functionality and can only be used in 
a single-pass algorithm, but not for accessing elements, but for being assigned elements
*it=100;

**Forward Iterator**   ===>>> They are higher in hierarachy than input and output iterators, and contain all the features present in these
two iterators. But, as the name suggests, they also can only move in forward direction and that too one step at a time

**Bidirectional Iterators**   ===>>>  They have all the features of forward iterators along with the fact that they overcome 
the drawback of forward iterators, as they can move in both the directions, that is why their name is bidirectional

**Random-Access Iterators**   ===>>>  They are the most powerful iterators. They are not limited to moving sequentially, as their name 
suggests,they can randomly access any element inside the container. They are the ones whose functionality is same as pointers
