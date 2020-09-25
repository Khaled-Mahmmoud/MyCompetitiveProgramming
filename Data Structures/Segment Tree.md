# Segment Tree

**Segment Tree** is used in cases where there are multiple range queries on array and modifications of elements of the same array. 
For example, finding the sum of all the elements in an array from indices L to R, or finding the minimum (famously known as Range Minumum Query problem) 
of all the elements in an array from indices L to R. These problems can be easily solved with one of the most versatile data structures, Segment Tree.

**What is Segment Tree?** 

Segment Tree is a basically a **binary tree** used for storing the intervals or segments. Each node in the Segment Tree represents an interval. 
Consider an array A of size N and a corresponding Segment Tree T:

1) The root of T will represent the whole array `A[0 : N-1]`.
2) Each leaf in the Segment Tree T will represent a single element A[i] such that 0 <= i <= N-1.
3) The internal nodes in the Segment Tree T represents the union of elementary intervals A[i : j] where 0 <= i < j <= N-1.

The Segment Tree of [array A of size 7](https://github.com/Khaled-Mahmmoud/MyCompetitiveProgramming/blob/master/img/Tree/segment%20tree%20size%207.jpg)

The Segment tree represented as [linear array](https://github.com/Khaled-Mahmmoud/MyCompetitiveProgramming/blob/master/img/Tree/segment%20tree%20linear%20array.jpg)

The root of the Segment Tree is broken down into [two half intervals](https://github.com/Khaled-Mahmmoud/MyCompetitiveProgramming/blob/master/img/Tree/two%20half%20intervals.png) or segments and the two children of the root 
in turn represent the `A[0 : (N-1)/2]` and `A[(N-1)/2+1 : (N-1)]`. So in each step, the segment is divided into half and the two children represent those two halves.
So the height of the segment tree will be Log2 N. There are N leaves representing the `N` elements of the array. The number of internal nodes is `N-1`. 
So, a total number of nodes are `2 * N - 1`.

Once the Segment Tree is built, its structure cannot be changed. We can update the values of nodes but we cannot change its structure.
Segment tree provides two operations:

1) **Update** : To update the element of the array A and reflect the corresponding change in the Segment tree.
2) **Query** : In this operation we can query on an interval or segment and return the answer to the problem (say minimum/maximum/summation in the particular segment).

### Example

Given an array A of size N and some queries. There are two types of queries:

Update : Given Idx and Val, update array element A[Idx] as A[Idx] = A[Idx] + Val.

Query : Given L and R return the value of `A[L]+A[L+1]+A[L+2]+....+A[R-1]+A[R]` such that 0 <= L <= R <= N-1

**Naive Algorithm** :
This is the most basic approach. For every query, run a loop from L to R and calculate the sum of all the elements. So each query will take O(n) time.
A[Idx] += Val will update the value of the element. Each update will take O(1).
This algorithm is good if the number of queries are very low compared to updates in the array.

**Using Segment Tree** :
First, figure what needs to be stored in the Segment Tree's node. The question asks for summation in the interval from L to R, so in each node, 
sum of all the elements in that interval represented by the node. 
```cpp
void build(int node, int start, int end)
{
    if(start == end)
    {
        // Leaf node will have a single element
        tree[node] = A[start];
        return;
    }
    else
    {
        int mid = (start + end) / 2;
       
        build(2*node, start, mid);       // Recurse on the left child
        
        build(2*node+1, mid+1, end);     // Recurse on the right child
        
        tree[node] = tree[2*node] + tree[2*node+1];     // Internal node will have the sum of both of its children
    }
}
```
As shown in the code above, start from the root and recurse on the left and the right child until a leaf node is reached. 
From the leaves, go back to the root and update all the nodes in the path. **node** represents the current node that is being processed.
Since Segment Tree is a binary tree. **2 * node** will represent the left node and **2 * node + 1** will represent the right node. **start** and **end** represents
the interval represented by the node. (Time Complexity of **build()** is O(n). There are total 2n-1 nodes, and value of every node is calculated only once in tree construction).

[Segment tree for A = {1,3,5,7,9,11}](https://github.com/Khaled-Mahmmoud/MyCompetitiveProgramming/blob/master/img/Tree/segment%20tree%20for%20A.jpg)


To update an element, look at the interval in which the element is present and recurse accordingly on the left or the right child.
```cpp
void update(int node, int start, int end, int idx, int val)
{
    if(start == end)
    {
        // Leaf node
        A[idx] += val;
        tree[node] += val;
        return;
    }
    else
    {
        int mid = (start + end) / 2;
        if(idx <= mid)
        {
            // If idx is in the left child, recurse on the left child
            update(2*node, start, mid, idx, val);
        }
        else
        {
            // if idx is in the right child, recurse on the right child
            update(2*node+1, mid+1, end, idx, val);
        }
        // Internal node will have the sum of both of its children
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}
```
Time Complexity of update will be O(log n).

To query on a given range, check 3 conditions as [diagram](https://github.com/Khaled-Mahmmoud/MyCompetitiveProgramming/blob/master/img/Tree/segment%20tree%20query.png).

1) Range represented by a node is completely inside the given range
2) Range represented by a node is completely outside the given range
3) Range represented by a node is partially inside and partially outside the given range **OR** the given range is completely inside Range represented by a node

If the range represented by a node is completely outside the given range, simply return 0. If the range represented by a node is completely within the given range, 
return the value of the node which is the sum of all the elements in the range represented by a node. 
And if the range represented by a node is partially inside and partially outside the given range or the given range is completely inside Range represented by a node, return sum of the left child and the right child. 

```cpp
int query(int node, int start, int end, int l, int r)
{
    if(start >= l and end <= r)
    {
        // range represented by a node is completely inside the given range
        return tree[node];
    }
    if(start > r || end < l)
    {
        // range represented by a node is completely outside the given range
        return 0;
    }
    // range represented by a node is partially inside and partially outside the given range
    // or or the given range is completely inside Range represented by a node
    int mid = (start + end) / 2;
    return query(2*node, start, mid, l, r) + query(2*node+1, mid+1, end, l, r);
}
```
Time Complexity of query will be O(log n).
