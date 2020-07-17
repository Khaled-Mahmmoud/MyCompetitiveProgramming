# Failure Function

failure function expresses longest proper prefix that is a suffix

Time Complexity O(m)

```cpp
vector<int>getprefix(string pat)
{
    int m=pat.size();
    vector<int>prefix(m);
    for(int i=1,k=0;i<m;i++)
    {
        while(k>0&&pat[i]!=pat[k])
            k=prefix[k-1];
        if(pat[i]==pat[k])
            prefix[i]=++k;
        else
            prefix[i]=k;
    }
    return prefix;
}
int main()
{
    string pat;cin>>pat;
    vector<int>prefix=getprefix(pat);
    for(int i=0;i<prefix.size();i++)
        cout<<prefix[i]<<' ';
    return 0;
}
```
