# A Lot of Games

[Problem Link](https://codeforces.com/contest/456/problem/D)

```cpp
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 27;
struct node
{
    node* edge[N]={};
};
class trie
{
public:
    node* root = new node();
    void insert(string str)
    {
        node* cur = root;
        for(int i=0;str[i];i++)
        {
            int c = str[i] - 'a';
            if(cur->edge[c]==nullptr)
                cur->edge[c] = new node();
            cur = cur->edge[c];
        }
    }
    bool check(node* cur,int cnt,bool col)
    {
        bool fg = true,fg2=true;
        for(int i=0;i<N;i++)
            if(cur->edge[i]!=nullptr)
            {
                bool w = check(cur->edge[i],cnt+1,col);
                if(fg2)
                   fg = w; // fg = check(cur->edge[i],cnt+1,col);
                fg2 = false;
                bool k = (cnt&1);
                if(col)
                    k = !k;
                if(k)
                fg |= w;  // fg |= check(cur->edge[i],cnt+1,col);
                else
                fg &= w;  // fg &= check(cur->edge[i],cnt+1,col);
                
                // please don't use above code with comments, it's give time limited
            }
        if(fg2)
        return (cnt&1);
        return fg;
    }
};
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    trie t;
    int n,k;cin>>n>>k;
    while(n--)
    {
        string str;
        cin>>str;
        t.insert(str);
    }
    if(t.check(t.root,0,1)&&(!t.check(t.root,0,0)||k&1))
        cout<<"First";
    else
        cout<<"Second";
    return 0;
}
```
