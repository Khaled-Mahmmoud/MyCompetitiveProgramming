# Longest Regular Bracket Sequence

[Problem Link](https://codeforces.com/contest/5/problem/C)

[Tutorial Link](https://codeforces.com/blog/entry/213)

```cpp
int main()
{
    string str;
    cin>>str;
    stack<pair<int,char>>st;
    int d[str.size()],c[str.size()];
    memset(d,-1,sizeof d);
    memset(c,-1,sizeof c);
    for(int i=0;i<str.size();i++)
    {
        if(str[i]==')')
        {
            if(st.empty())
                continue;
            else
            {
                pair<int,char> p = st.top();
                d[i] = p.first;
                c[i] = d[i];
                if(d[i]-1>=0&&c[d[i]-1]!=-1)
                    c[i] = c[d[i] - 1];
                st.pop();
            }
        }
        else
            st.push({i,str[i]});
    }
    int mx = 0,cnt = 0;
    for(int i=0;i<str.size();i++)
    {
        if(c[i]!=-1&&mx<i - c[i]+1)
            mx = i-c[i]+1;
    }
    for(int i=0;i<str.size();i++)
    {
        if(c[i]!=-1&&mx == i-c[i]+1)
            cnt++;
    }
    if(mx == 0)
        cout<<mx<<' '<<1;
    else
    cout<<mx<<' '<<cnt;
    return 0;
}
```
