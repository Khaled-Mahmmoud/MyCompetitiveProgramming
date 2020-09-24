# Build a graph

[Problem Link](https://www.hackerearth.com/practice/algorithms/graphs/graph-representation/practice-problems/algorithm/build-a-graph-5f5c6b4a/)

**Solution**

Given that no. of edges should be equal to no. of vertices. Lets take cases to understand this:

case 1: If we consider only a single vertex : we can't have self loop(as mentioned in the que) so it is not possible to draw a graph for 1 vertex.

case 2: If we have two vertices then we have an edge b/w two vertices but it is not possible to have two edges as multiple edges are not allowed.

case 3: if we have three vertices then for having a graph with 3 edges it will form a triangle. But all the vertex have degree 2 and none of them are cut-vertex. hence this fails.

case 4: If we have 4 vertices with ( 1 ,2,3 nodes forming a triangle) and (4 th node) attached to lets say (1) then vertex (2&3 ) violates the two condions as they both have degree 2 and neither of them are cut vertex.

case 5: If we have 5 vertices with ( 1 ,2,3 nodes forming a triangle) and (4 th node) attached to lets say (1) and (5th node) attached to lets say (2) then vertex (3 ) violates the two condions as it has degree 2 and is not a cut vertex.

case 6:If we have 6 vertices with ( 1 ,2,3 nodes forming a triangle) and (4 th node) attached to lets say (1) and (5th node) attached to (2) and (6th node) attached to (3) then we can find that each nd every vertex satisfies either of the two condition.

So a graph with 6 vertices satisfies the either of the two conditions.Hence for atleast two connected components we will require equal or greater than 12 vertices .

```cpp
int main()
{
    int n;
    cin>>n;
    if(n>=12) 
       cout<<"Yes";
    else 
       cout<<"No";
    return 0;
}

```
