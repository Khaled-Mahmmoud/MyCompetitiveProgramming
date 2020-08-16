# Monk at the Graph Factory

Our Code Monk recently learnt about Graphs and is very excited!

He went over to the Graph-making factory to watch some freshly prepared graphs. Incidentally, one of the workers at the factory was ill today, so Monk decided to step in and do her job.

The Monk's Job is to Identify whether the incoming graph is a tree or not. He is given N, the number of vertices in the graph and the degree of each vertex.

Find if the graph is a tree or not.

Input:
First line contains an integer N, the number of vertices.
Second line contains N space-separated integers, the degrees of the N vertices.

Output:
Print "Yes" (without the quotes) if the graph is a tree or "No" (without the quotes) otherwise.

Constraints:

1 ≤ N ≤ 100

1 ≤ Degreei ≤ 1000

input : 

3

1 2 1

ouput : Yes

**Explanation**

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
