```cpp
// Dirct Graph	
// https://open.kattis.com/problems/catenyms	
const int N = 2e5 + 10, M = 2 * N, E = 1024 + 5;
int head[N], nxt[M], to[M], n, ne;
int res[M], resSize, deg[N], I[1000], lst[N];
char str[1000][21];
void init()
{
    memset(head, -1, n * sizeof head[0]);
    ne = 0;
}
void addEdge(int f, int t)
{
    to[ne] = t;
    nxt[ne] = head[f];
    head[f] = ne++;
}
void addBiEdge(int u, int v)
{
    addEdge(u, v);
    addEdge(v, u);
}
void Euler(int u)
{
    for (int &e = head[u]; ~e;)
    {
        int x = e;
        e = nxt[e];
        int v = to[x];
        Euler(v);
        res[resSize++] = x;
    }
}
void solve()
{
    int t, m;
    cin>>t;
    while (t--)
    {
        n = 128;
        init();
        fill(deg + 'a', deg + 'z' + 1, 0);
        cin>>m;

        int st = 'z';
        for (int i = 0; i < m; ++i)
        {
            cin>>str[i];
            lst[i] = strlen(str[i]) - 1;
            I[i] = i;
            st = min({st, (int) str[i][0], (int) str[i][lst[i]]});
            deg[(int)str[i][0]]++, deg[(int)str[i][lst[i]]]--;
        }
        sort(I, I + m, [](int a, int b)
        {
            return strcmp(str[a], str[b]) > 0;
        });

        for (int i = 0; i < m; ++i)
        {
            int j = I[i];
            addEdge(str[j][0], str[j][lst[j]]);
        }
        bool ok = 1;
        int cnt1 = 0;
        for (int i = 'a'; i <= 'z'; ++i)
        if(deg[i]==1)
        {
            if(cnt1++)
                ok = 0;
            st = i;
        }
        else if(deg[i]==0||deg[i]==-1)
            continue;
        else
            ok = 0;
        resSize = 0;
        Euler(st);
        ok &= resSize == m;
        if (ok)
        {
            for (int i = resSize - 1; i >= 0; --i)
                cout<<str[I[res[i]]]<<".\n"[!i];
        }
        else
            cout<<"***";
    }
}

// Undirected Graph
// Fence (USACO)
const int N = 2003;
vector<vector<pair<int, int>>> adj_(N);
vector<int> res, vis(N),degree(N);
vector<queue<pair<int,int>>>adj(N);
int isOdd[N];
void euler(int node)
{
    while (sz(adj[node]))
    {
        auto it = adj[node].front();
        adj[node].pop();
        if (vis[it.second])
            continue;
        vis[it.second] = true;
        euler(it.first);
    }
    res.push_back(node);
}
void solve()
{
    int n;
    cin >> n;
    int st = N;
    for (int i = 0; i<n; i++)
    {
        int u,v;
        cin>>u>>v;
        adj_[u].push_back({v,i});
        adj_[v].push_back({u,i});
        isOdd[u] ^= 1;
        isOdd[v] ^= 1;
        st = min(u,v);
    }
    for(int i=0; i<N; i++)
        sort(adj_[i].begin(),adj_[i].end());
    for(int i=0; i<N; i++)
        for(int j=0; j<sz(adj_[i]); j++)
            adj[i].push(adj_[i][j]);
    int cntOdd = count(isOdd, isOdd + N, 1);
    if (cntOdd > 2)
    {
        cout<<-1<<'\n';
        return;
    }
    if (cntOdd)
        st = find(isOdd, isOdd + N, 1) - isOdd;
    euler(st);
    if (sz(res) - 1 != n)
    {
        cout<<-1<<'\n';
        return;
    }
    reverse(res.begin(),res.end());
    for(int i=0; i<sz(res); i++)
        cout<<res[i]<<'\n';
}
```
