# Password

[Problem Link](https://codeforces.com/contest/126/problem/B)

```cpp
vector<int> getprefix(string pat)
{
    int m = pat.size();
    vector<int>prefix(m);
    for(int i=1,len=0;i<m;i++)
    {
        while(len>0&&pat[i]!=pat[len])
            len = prefix[len-1];
        if(pat[i]==pat[len])
            prefix[i] = ++len;
        else
            prefix[i] = len;
    }
    return prefix;
}
int main()
{
    string str,str1;cin>>str;
    vector<int> prefix = getprefix(str);
    int n = str.size();
    if(!prefix[n-1])return cout<<"Just a legend",0;
    for(int i=0;i<n-1;i++)
        if(prefix[i]==prefix[n-1])
           return cout<<str.substr(0,prefix[i]),0;
    if(prefix[prefix[n-1]-1])   // if str = "ppp"
        return cout<<str.substr(0,prefix[prefix[n-1]-1]),0;
    return cout<<"Just a legend",0;
    return 0;
}
```
