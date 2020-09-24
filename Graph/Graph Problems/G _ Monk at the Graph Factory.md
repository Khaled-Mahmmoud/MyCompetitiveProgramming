# Monk at the Graph Factory

[Problem Link](https://www.hackerearth.com/practice/algorithms/graphs/graph-representation/practice-problems/algorithm/monk-at-the-graph-factory/)

**Solution**

The degree of vertex v in a graph is defined as the number of graph edges that touch the vertex v. Thus, in the given test case vertex 0 has 1 graph edge, vertex 1 has 2 graph edges and vertex 2 has 1 graph edges giving a structure.
```
          1
    /            \
0                   2
```
Now, to solve the problem, you should know that a graph has a total sum of all degree of vertices that is atleast 2 * E, where E is the number of edges. And voila, just use the relevant conditional statement and you are done with the problem.

```cpp
int main()
{
    int n,x,res = 0;cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        res += x;
    }
    if(res == 2 * (n-1))
        cout<<"Yes";
    else
        cout<<"No";
    return 0;
}
```
