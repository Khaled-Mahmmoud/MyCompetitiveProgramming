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
        {
            switch (deg[i])
            {
            case 0:
                break;
            case 1:
                if (cnt1++)
                    ok = 0;
                st = i;
                break;
            case -1:
                break;
            default:
                ok = 0;
                break;
            }
        }
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
const int N = 2e5 + 10, M = 2 * N, E = 1024 + 5;
int head[N], nxt[M], to[M], n, ne, vis[M], vid;
int U[E], V[E], I[E], res[M], resSize;
bool isOdd[N];
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
    for (int &e = head[u]; ~e; )
    {
        int x = e;
        e = nxt[e];
        if (vis[x])
            continue;
        vis[x ^ 1] = 1;
        int v = to[x];
        Euler(v);
    }
    res[resSize++] = u;
}
void solve()
{
    int m;
    n = 501;
    init();
    cin>>m;
    int mn = 501;
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin>>a>>b;
        isOdd[a] ^= 1;
        isOdd[b] ^= 1;
        U[i] = min(a, b);
        mn = min(mn, U[i]);
        V[i] = max(a, b);
        I[i] = i;
    }
    sort(I, I + m, [](int a, int b){
        return tie(U[a], V[a]) < tie(U[b], V[b]);});

    for (int i = m - 1; i >= 0; --i)
        addBiEdge(U[I[i]], V[I[i]]);

    int cntOdd = count(isOdd, isOdd + 501, 1);
    if (cntOdd > 2)
    {
        cout<<-1<<'\n';
        return;
    }

    int st = mn;
    if (cntOdd)
        st = find(isOdd, isOdd + 501, 1) - isOdd;
    resSize = 0;
    Euler(st);
    if (resSize - 1 != m)
    {
        cout<<-1<<'\n';
        return;
    }
    for (int i = resSize - 1; i >= 0; i--)
        cout<<res[i]<<'\n';
}
```
