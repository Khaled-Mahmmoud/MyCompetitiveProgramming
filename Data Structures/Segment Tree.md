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


<p align="center">
  <img width="550" height="400" src="https://github.com/Khaled-Mahmmoud/MyCompetitiveProgramming/blob/master/img/Tree/segment%20tree%20size%207.jpg">
</p>

<p align="center">
  <img width="460" height="330" src="https://github.com/Khaled-Mahmmoud/MyCompetitiveProgramming/blob/master/img/Tree/two%20half%20intervals.png">
</p>

The root of the Segment Tree is broken down into two half intervals or segments and the two children of the root 
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
#define N 100005  
int a[N];	
int tree[2 * N - 1];   // please note that number of nodes = 2*n-1	
                       // there was wrong answer of tree[N] 
                       // It is better to make it tree[4*N]
		     
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
Complexity : O(n)
```
As shown in the code above, start from the root and recurse on the left and the right child until a leaf node is reached. 
From the leaves, go back to the root and update all the nodes in the path. **node** represents the current node that is being processed.
Since Segment Tree is a binary tree. **2 * node** will represent the left node and **2 * node + 1** will represent the right node. **start** and **end** represents
the interval represented by the node. (Time Complexity of **build()** is O(n). There are total 2n-1 nodes, and value of every node is calculated only once in tree construction).


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
Complexity : O(log n)
```

To query on a given range, check 3 conditions as

<p align="center">
  <img width="550" height="400" src="https://github.com/Khaled-Mahmmoud/MyCompetitiveProgramming/blob/master/img/Tree/segment%20tree%20query.png">
</p>

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
Complexity : O(log n)
```

(start + end) / 2 ==>> ((start + end)>>1)

2 * node  ==>> (node<<1)

2 * node + 1 ==>> (node<<1|1)

```cpp
int main()	
{	
    int n,q;
    cin>>n>>q;	
    for(int i=0;i<n;i++)	
        cin>>a[i];	
    build(1,0,n-1);	
    while(q--)	
    {	
        char c;	
        cin>>c;	
        if(c=='u')	
        {	
            int idx,val;	
            cin>>idx>>val;	
            idx--;	
            updata(1,0,n-1,idx,val);	
        }	
        else 	
        {	
            int l,r;	
            cin>>l>>r;	
            l--,r--;	
            cout<<query(1,0,n-1,l,r)<<'\n';	
        }	
    }	
    return 0;	
}
```
--------------------------------------------------------------------------------------------------------------------------------------------------------------

### Segment tree Problems
 
We we have a coordinate space on x-axis from [0 - N].

we are given set of numbers (order is not issue)	e.g.: 20 7 4 9 12.

Queries are as following.
 
a) **HOW many numbers are in given interval**?
 				
E.g In interval [1-3]  = 0	-> Notice, our first element is 4
 				
E.g In interval [0-8]  = 2	-> 4, 7

E.g In interval [6-15] = 3	-> 7, 9, 12

b) **Get Kth item in sorted list**
 
 E.g. get(2) = 7		-> in sorted list 4 7 9 12 20
			
c) **Remove kth item in sorted list**
 				
E.g. remove(5) 		-> 4 7 9 12
		
b) **Insert new element: so we update our list**
				
E.g. insert(16)		-> 4 7 9 12 16 20

**Solution** : The main point in these data structures is idea of `Pre-Processing` before answering Queries.

So how is segment tree constructed? Done as a BINARY tree, each item holds an interval, represents HOW many numbers are in this interval. Leaf nodes represents the main number.

So to have N numbers as leaf, and want to go up layer by later till reach root as a binary tree, we need to go up logN level

Assume we have N = 8, so above is 4, then 2, then 1. So a total number of nodes: 15 = 2^4 -1

How to index them, given initial N values?

How to do the pre-processing?

```cpp
const int N = 2000006;
int interval[2*N-1];	
int S = 0, E = N;
// insert num and return its order (kth in order)
int insert(int num, int s = S, int e = E, int p = 1)  // O(logn)
{	
	interval[p]++;
	if(s == e)	
	        return interval[p];	
	int mid = (s+e) >> 1;
	if(num <= mid)
		return insert(num, s, mid, 2*p);
	return interval[2*p] + insert(num, mid+1, e, 2*p+1);
}
// remove kth element, and return its value
int remove(int kTh, int s = S, int e = E, int p = 1) // O(logn)
{
	interval[p]--;
	if(s == e)	
	    return s;
	int mid = (s+e) >> 1;
	if(interval[2*p] >= kTh)	
	    return remove(kTh, s, mid, 2*p);
	return remove(kTh - interval[2*p], mid + 1, e, 2*p+1);
}
// remove num , return position of deleted val 
int remove(int num, int s = S, int e = E, int p = 1) // O(logn)
{
	interval[p]--;
	if(s == e)	
	    return interval[p] + 1;
	int mid = (s+e) >> 1;
	if(mid >= num)	
	    return remove(num, s, mid, 2*p);
	return interval[2*p] + remove(num , mid + 1, e, 2*p+1);
}
// get value of kth element
int get(int kTh, int s = S, int e = E, int p = 1)
{
	if(s == e)	
	    return s;
	int mid = (s+e) >> 1;
	if(interval[2*p] >= kTh)	
	     return getkTh(kTh, s, mid, 2*p);
	return getkTh(kTh-interval[2*p], mid+1, e, 2*p+1);
}
void displayElements(int s=S, int e=E, int p=1)
{
    int mid = (s+e) >> 1;
    if(s < e)
    {
        displayElements(s, mid, 2*p);
        displayElements(mid+1, e, 2*p+1);
    }
    if(s == e)
    {
        int cnt = interval[p];
        while(cnt--)
            cout<<s<<" ";
    }
}
```
### Lazy Propagation

All problems in the above sections discussed modification queries that only effected a single element of the array each. However the Segment Tree allows applying modification queries to an entire segment of contiguous elements, and perform the query in the same time O(logn).


[Problem Link](https://codeforces.com/contest/620/problem/E)
[Solution Link](https://codeforces.com/contest/620/submission/100289526)
