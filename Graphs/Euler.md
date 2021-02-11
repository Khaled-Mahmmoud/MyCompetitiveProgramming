```cpp
class Hier
{
    int vertex;
    vector<unordered_map<int,int>> adj;
public:
    Hier(int v)
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
```
