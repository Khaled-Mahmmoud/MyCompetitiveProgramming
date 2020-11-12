# Container adaptors

### Stack

Stacks are dynamic data structures that follow **the Last In First Out (LIFO)** principle. The last item to be inserted into a stack is the first one to be deleted from it.

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

Queues are data structures that follow **the First In First Out (FIFO)** i.e. the first element that is added to the queue is the first one to be removed.

Elements are always added to the back and removed from the front.


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

priority queue is an abstract data type similar to a regular queue or stack data structure in which each element additionally has a "priority" associated with it. In a priority queue, an element with high priority is served before an element with low priority.

```cpp
#include <priority_queue>  
priority_queue<object_type,vector<int>>object_name; OR
priority_queue<object_type,deqeue<int>>object_name;
pq.empty() // Returns whether the priority_queue is empty // O(1)
pq.size() // Returns the number of elements in the priority_queue // O(1)
pq.top() // Returns a reference to the top element in the priority_queue(refers to rightmost element) // O(1)
pq.push(val) // Inserts a new element at the priority_queue // O(1)
pq.pop() // Removes the element on top of the priority_queue // O(1)
pq.emplace(val) // adds a new element at the priority_queue // O(1)
pq1.swap(pq2)  || O(1) || Sawp two container

priority_queue<int,vector<int>>pq; // all elements of pq stored in ascending order
priority_queue<int,vector<int>,greater<int>>pq; // all elements of pq stored in descending order
priority_queue<int,vector<int>,less<int>>pq; // all elements of pq stored in ascending order

struct comp
{
    bool operator()(const int& l,const int& r)const
    {
        return l > r;
    }
};
priority_queue<int,vector<int>,comp>pq;
```
