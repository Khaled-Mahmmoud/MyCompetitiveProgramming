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
            cout<<-1<<'\n';
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
            cout<<-1<<'\n';
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
}

// Directed Graph
const int N = (int)1e5 + 9;
queue<int> adj[N];
stack<int> ans;
int deg[N];
void euler(int cur)
{
    while(!adj[cur].empty())
    {
        int a=adj[cur].front();
        adj[cur].pop();
        euler(a);
    }
    ans.push(cur);
}
int solve()
{
    int n,e,start;
    cin>>n>>e;
    for(int i=0; i<e; i++)
    {
        int u,v;
        cin>>u>>v;
        u--,v--;
        adj[u].push(v);
        start = u;
        ++deg[u],--deg[v];
    }
    int in = 0, out = 0;
    for(int i=0; i<n; i++)
    {
        if(deg[i]==1)
            start = i, ++out;
        else if(deg[i]==-1)
            in++;
        else if(deg[i])
            return -1;
    }
    if(out>1||in>1||out!=in)
        return -1;
    euler(start);
    if(e!=sz(ans)-1)
        return -1;
    cout<<"Euler "<<(out?"Path":"Cycle")<<": ";
    while(!ans.empty())
    {
        int x = ans.top();
        ans.pop();
        cout<<x + 1<<' ';
    }
    return 0;
}
```
