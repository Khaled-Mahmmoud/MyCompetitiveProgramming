
```cpp
int n;
vector<int>v,sub;
vector<vector<int>>res;
void subset(int idx)
{
    if(idx==n)
    {
        res.push_back(sub);
        return;
    }
    sub.push_back(v[idx]);
    subset(idx+1);
    sub.pop_back();
    subset(idx+1);
}
int main()
{
    cin>>n;
    v.resize(n);
    for(int i=0; i<n; i++)
        cin>>v[i];
    subset(0);
    sort(res.begin(),res.end());
    for(int i=0; i<res.size(); i++)
    {
        for(int j=0; j<res[i].size(); j++)
            cout<<res[i][j]<<' ';
        cout<<'\n';
    }
    return 0;
}
// complexity : O(2^n)
````