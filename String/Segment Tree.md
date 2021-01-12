```cpp
const int N = 4e5 + 5;
int n, m, a[N];
int l[N], r[N];
ll seg[4 * N], lazy[4 * N];
vector<int> g[N];
vector<int> flatten;
void build(int node, int s, int e)
{
    if(s == e)
    {
        seg[node] = (1ll << a[flatten[s]]);
        return;
    }
    int mid = s + e >> 1;
    build(node << 1, s, mid);
    build(node << 1 | 1, mid + 1, e);
    seg[node] = (seg[node << 1] | seg[node << 1 | 1]);
} // O(n)
void propagate(int node, int s, int e)
{
    seg[node] = lazy[node];
    if(s != e)
    {
        lazy[node << 1] = lazy[node];
        lazy[node << 1 | 1] = lazy[node];
    }
    lazy[node] = 0;
} // O(1)
void update(int node, int s, int e, int l, int r, int val)
{
    if(lazy[node])
        propagate(node, s, e);
    if(s > r || e < l)
        return;
    if(l <= s && e <= r)
    {
        lazy[node] = (1ll << val);
        propagate(node, s, e);
        return;
    }
    int mid = s + e >> 1;
    update(node << 1, s, mid, l, r, val);
    update(node << 1 | 1, mid + 1, e, l, r, val);
    seg[node] = (seg[node << 1] | seg[node << 1 | 1]);
} // O(log n) 
ll query(int node, int s, int e, int l, int r)
{
    if(lazy[node])
        propagate(node, s, e);
    if(s > r || e < l)
        return 0;
    if(l <= s && e <= r)
        return seg[node];
    int mid = s + e >> 1;
    return (query(node << 1, s, mid, l, r) | query(node << 1 | 1, mid + 1, e, l, r));
} // O(log n)
```
