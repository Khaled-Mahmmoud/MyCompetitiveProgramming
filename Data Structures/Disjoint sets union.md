```cpp
const int N = 1000;
int p[N];
vector<int>siz;
int find(int u) 
{
    if (p[u] == u)
        return u;
    return p[u] = find(p[u]);
}
int main() 
{
    int n,m;
    cin>>n>>m;
    int cnt = n; 
    siz.resize(n);
    for (int i=0;i<n;i++)
        p[i] = i;
    while(m--) 
    {
        int a,b;
        cin>>a>>b;

        a = find(a);
        b = find(b);

        if(a != b) 
        {
            cnt--;
            siz[b] += siz[a];
            p[a] = b;
        }
    }
    return 0;
}
```
