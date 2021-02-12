```cpp
// Hierholzer’s Algorithm : O(E)
// Undirected Graph
int e,w;
class Euler
{
    int vertex;
    vector<unordered_map<int,int>> adj;
public:
    Euler(int v)
    {
        vertex = v;
        adj = vector<unordered_map<int,int>>(v+1);
    }
    void addEdge(int u, int v)
    {
        adj[u][v]++;
        adj[v][u]++;
    }
    void removeEdge(int v,int u)
    {
        adj[u][v]--;
        adj[v][u]--;
        if(adj[u][v]==0)
        {
            adj[v].erase(u);
            adj[u].erase(v);
        }
    }
    void printEulerPathCircuit()
    {
        int odd = 0;
        int oddVertex = 0;
        for(int i=1; i<=vertex; ++i)
            if(sz(adj[i])&1)
            {
                ++odd;
                oddVertex = i;
            }
        if(odd==0)
            printEuler(w);
        else if(odd==2)
            printEuler(oddVertex);
        else
            cout<<-1;
    }
    void printEuler(int v)
    {
        stack<int> cpath;
        stack<int> epath;
        cpath.push(v);
        while(!cpath.empty())
        {
            int u = cpath.top();
            if(sz(adj[u])==0)
            {
                epath.push(u);
                cpath.pop();
            }
            else
            {
                cpath.push(adj[u].begin()->first);
                removeEdge(u,adj[u].begin()->first);
            }
        }
        if(e==sz(epath)-1)
            while(!epath.empty())
            {
                cout<<epath.top()<<' ';
                epath.pop();
            }
        else
            cout<<-1;
    }
};
void solve()
{
    int n;
    cin>>n>>e;
    Euler hr(n);
    for(int i=0; i<e; i++)
    {
        int u,v;
        cin>>u>>v;
        w = u;
        hr.addEdge(u,v);
    }
    hr.printEulerPathCircuit();
    cout<<'\n';
}
// Directed Graph
int e,w;
class Euler
{
    int vertex;
    vector<unordered_map<int, int>> adj;
    vector<int> degree;
public:
    Euler(int v)
    {
        vertex = v;
        adj = vector<unordered_map<int, int>>(v + 1);
        degree = vector<int>(v + 1, 0);
    }
    void addEdge(int u, int v)
    {
        adj[u][v]++;
        degree[u]++;
        degree[v]--;
    }
    void removeEdge(int u, int v)
    {
        adj[u][v]--;
        if(adj[u][v]==0)
            adj[u].erase(v);
        degree[u]--;
        degree[v]++;
    }
    void printEulerPathCircuit()
    {
        int start, indeg, outdeg;
        start = -1;
        indeg = outdeg = 0;
        for (int i = 1; i <= vertex; ++i)
        {
            if (degree[i] == -1 && indeg == 0)
                ++indeg;
            else if (degree[i] == 1 && outdeg == 0)
            {
                ++outdeg;
                start = i;
            }
            else if (degree[i] != 0)
            {
                cout<<-1;
                return;
            }
        }
        if (indeg == 1 && outdeg == 1)
            printEuler(start);
        else
            printEuler(w);
    }
    void printEuler(int v)
    {
        stack<int> cpath;
        stack<int> epath;
        cpath.push(v);
        while(!cpath.empty())
        {
            int u = cpath.top();
            if (sz(adj[u])== 0)
            {
                epath.push(u);
                cpath.pop();
            }
            else
            {
                cpath.push(adj[u].begin()->first);
                removeEdge(u, adj[u].begin()->first);
            }
        }
        if(e==sz(epath)-1)
            while (!epath.empty())
            {
                cout<<epath.top()<<' ';
                epath.pop();
            }
        else
            cout <<-1;
    }
};
void solve()
{
    int n;
    cin>>n>>e;
    Euler hr(n);
    for(int i=0; i<e; i++)
    {
        int u,v;
        cin>>u>>v;
        w = u;
        hr.addEdge(u,v);
    }
    hr.printEulerPathCircuit();
    cout<<'\n';
}
```
