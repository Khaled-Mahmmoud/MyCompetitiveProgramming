```cpp
// Dirct Graph
// https://open.kattis.com/problems/catenyms
vector<vector<pair<int, int>>> adj;
vector<int> res, vis;
void euler(int node)
{
    for (auto &it : adj[node])
    {
        if (vis[it.second])
            continue;
        vis[it.second] = true;
        euler(it.first);
        res.push_back(it.second);
    }
}
void solve()
{
    int n;
    cin >> n;
    vis = vector<int>(n);
    res = vector<int>();
    adj = vector<vector<pair<int, int>>>(26);
    vector<string> v(n);
    vector<int> deg(26);
    for (auto &it : v)
        cin >> it;
    sort(v.begin(),v.end());
    int st = 26;
    for (int i = 0; i < n; i++)
    {
        int a = v[i][0] - 'a', b = v[i].back() - 'a';
        deg[a]++;
        deg[b]--;
        adj[a].push_back( { b, i });
        st = min( { st, a, b });
    }
    bool valid = true;
    int odd = 0;
    for (int i = 0; i < 26; i++)
    {
        if (deg[i] == 1)
        {
            odd++;
            st = i;
        }
        else if (abs(deg[i]) > 1)
            valid = false;
    }
    if (odd > 1)
        valid = false;
    euler(st);
    if (sz(res) != n)
        valid = false;
    if (valid)
    {
        reverse(res.begin(),res.end());
        for (int i = 0; i < n; i++)
            cout << v[res[i]] << ".\n"[i + 1 == n];
    }
    else
        cout << "***\n";
}
```
