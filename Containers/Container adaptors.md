# Container adaptors

### Stack

Stacks are dynamic data structures that follow **the Last In First Out (LIFO)** principle. The last item to be inserted into a stack is the first one to be deleted from it.

For example, you have a stack of trays on a table. The tray at the top of the stack is the first item to be moved if you require a tray from that stack.

**Inserting and deleting elements**

Stacks have restrictions on the insertion and deletion of elements. Elements can be inserted or deleted only from one end of the stack i.e. from the top. The element at the top is called **the top** element. The operations of inserting and deleting elements are called **push()** and **pop()** respectively.

When the top element of a stack is deleted, if the stack remains non-empty, then the element just below the previous top element becomes the new top element of the stack.

For example, in the stack of trays, if you take the tray on the top and do not replace it, then the second tray automatically becomes the top element (tray) of that stack.

Features of stacks

1) Dynamic data structures
2) Do not have a fixed size
3) Do not consume a fixed amount of memory
4) Size of stack changes with each push() and pop() operation. Each push() and pop() operation increases and decreases the size of the stack by 1, respectively.

A stack can be [visualized](https://github.com/Khaled-Mahmmoud/MyCompetitiveProgramming/blob/master/img/Containers/stack.png) as follows:

```cpp
#include <stack>  
stack<object_type>object_name;
sk.empty() // Returns whether the stack is empty // O(1)
sk.size() // Returns the number of elements in the stack // O(1)
sk.top() // Returns a reference to the top element in the stack // O(1)
sk.push(val) // Inserts a new element at the top of the stack // O(1)
sk.pop() // Removes the element on top of the stack // O(1)
sk.emplace(val) // adds a new element at the top of the stack // O(1)
sk1.swap(sk2)  || O(1) || Sawp two container
```

### Queue

```cpp
#include <queue>  
queue<object_type>object_name;
q.empty() // Returns whether the queue is empty // O(1)
q.size() // Returns the number of elements in the queue // O(1)
q.push(val) // Inserts a new element at the end of the queue // O(1)
q.pop() // Removes the "oldest" element in queue// O(1)
q.emplace(val) // adds a new element at the end of the queue // O(1)
q.front() // Returns a reference to the oldest element in the queue // O(1)
q.back() // Returns a reference to the newest element in the queue // O(1)
q1.swap(q2)  || O(1) || Sawp two container
```

### Priority Queue

```cpp
#include <priority_queue>  
priority_queue<object_type,vector<int>>object_name; OR
priority_queue<object_type,deqeue<int>>object_name;
pq.empty() // Returns whether the priority_queue is empty // O(1)
pq.size() // Returns the number of elements in the priority_queue // O(1)
pq.top() // Returns a reference to the top element in the priority_queue // O(1)
pq.push(val) // Inserts a new element at the priority_queue // O(1)
pq.pop() // Removes the element on top of the priority_queue // O(1)
pq.emplace(val) // adds a new element at the priority_queue // O(1)
pq1.swap(pq2)  || O(1) || Sawp two container

priority_queue<int,vector<int>>pq; // all elements of pq stored in ascending order
priority_queue<int,vector<int>,greater<int>>pq; // all elements of pq stored in descending order
```
