# Road Construction

A country has n cities. Initially, there is no road in the country. One day, the king decides to construct some roads connecting pairs of cities.
Roads can be traversed either way. He wants those roads to be constructed in such a way that it is possible to go from each city to any other city 
by traversing at most two roads. You are also given m pairs of cities — roads cannot be constructed between these pairs of cities.

Your task is to construct the minimum number of roads that still satisfy the above conditions. The constraints will guarantee that this is always possible.

Input : 
The first line consists of two integers n and m.

Then m lines follow, each consisting of two integers a i and b i (1 ≤ a i, b i ≤ n, a i ≠ b i),
which means that it is not possible to construct a road connecting cities a i and b i. Consider the cities are numbered from 1 to n.

It is guaranteed that every pair of cities will appear at most once in the input.

Output :
You should print an integer s: the minimum number of roads that should be constructed, in the first line.
Then s lines should follow, each consisting of two integers a i and b i (1 ≤ a i, b i ≤ n, a i ≠ b i), 
which means that a road should be constructed between cities a i and b i.

If there are several solutions, you may print any of them.

input

4 1

1 3

output

3

1 2

4 2

2 3

**Solution**

The constraints can be satisfied if and only if the graph is a [star graph](https://github.com/Khaled-Mahmmoud/MyCompetitiveProgramming/blob/master/img/Graph/Star%20graph.png), Since m < n/2, there exists at least one node that is not incident to any edge of m edges.

```cpp
int main()
{
    int n,m;
    cin>>n>>m;
    int a[n+1]={};
    int x,y;
    while(m--)
    {
        cin>>x>>y;
        a[x] = 1;
        a[y] = 1;
    }
    for(int i=1;i<=n;i++)
        if(!a[i]){x = i;break;}
    cout<<n-1<<'\n';
    for(int i=1;i<=n;i++)
        if(x!=i)
        cout<<x<<' '<<i<<'\n';
    return 0;
}

```
