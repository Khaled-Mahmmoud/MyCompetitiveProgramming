## Generating subsets
```cpp
vector<int>v,sub;
int n;
vector<vector<int>>res;
void subset(int index=0)
{
    res.push_back(sub);
    for(int i=index; i<n; i++)
    {
        sub.push_back(v[i]);
        subset(i+1);
        sub.pop_back();
    }
}
int main()
{
    cin>>n;
    v.resize(n);
    for(int i=0; i<n; i++)
        cin>>v[i];
    subset();
    for(int i=0; i<res.size(); i++)
    {
        for(int j=0; j<res[i].size(); j++)
            cout<<res[i][j]<<' ';
        cout<<'\n';
    }
    return 0;
}
```
**complexity : O(2^n)**