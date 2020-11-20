## Container adaptors

#### Stack

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

#### Queue

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

#### Priority Queue

```cpp
#include <priority_queue>  
priority_queue<int,vector<int>>pq; OR
priority_queue<int,deqeue<int>>pq;
pq.empty() // O(1)
pq.size() // O(1)
pq.top() // O(1)
pq.push(val) // O(1)
pq.pop() // O(1)
pq.emplace(val) // O(1)
pq1.swap(pq2)  // O(1) 

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
