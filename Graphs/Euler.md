```cpp
// Hierholzer’s Algorithm : O(E)
// Undirected Graph
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
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    void removeEdge(int v,int u)
    {
        adj[v].erase(u);
        adj[u].erase(v);
    }
    void printEulerPathCircuit()
    {

        int odd = 0;
        int oddVertex = 0;
        for(int i=1; i<=vertex; ++i)
        {
            if(sz(adj[i])&1)
            {
                ++odd;
                oddVertex = i;
            }
        }
        if(odd==0)
        {
            cout<<"Euler Circuit: ";
            printEuler(1);
        }
        else if(odd==2)
        {
            cout<<"Euler Path: ";
            printEuler(oddVertex);
        }
        else
            cout<<"Euler Path/Circuit Doesn't Exist"<<endl;
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
        while(!epath.empty())
        {
            cout<<" "<<epath.top()<<" ";
            epath.pop();
        }
    }
};

// Directed Graph
class Hier
{
    int vertex;
    vector<unordered_map<int, int>> adj;
    vector<int> degree;
public:
    Hier(int v)
    {
        vertex = v;
        adj = vector<unordered_map<int, int>>(v + 1);
        degree = vector<int>(v + 1, 0);
    }
    void addEdge(int u, int v)
    {
        adj[u][v] = 1;
        degree[u]++;
        degree[v]--;
    }
    void removeEdge(int u, int v)
    {
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
                cout << "Euler Path/Circuit Doesn't Exist" << endl;
                return;
            }
        }
        if (indeg == 1 && outdeg == 1)
        {
            cout << "Euler Path: ";
            printEuler(start);
        }
        else
        {
            cout << "Euler Curcuit: ";
            printEuler(1);
        }
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
        while (!epath.empty())
        {
            cout<< " " <<epath.top()<< " ";
            epath.pop();
        }
    }
};
```
