# Trie

### Trie static

insert OR search OR erase **O(L)** Where L length of a word

implementation **O(N * L)** Where n is number of words and L is average length of strings

```cpp

#define N 100009
int sz,d;
vector<int>en(N);vector<int>prefix(N);
vector<vector<int>>node(N,vector<int>(27));
//                                     ^ OR 255 for all characters and digits and symbols
void insert(string s)
{
    int v=0;
    for(int i=0;s[i];i++)
    {
        prefix[v]++;
        int c=s[i]-'a';
        if(!node[v][c]) // if 255 we put node[v][s[i]]
            node[v][c]=++sz;
        v=node[v][c];
    }
    prefix[v]++;
    d+=(++en[v]==1);
}
bool search(string s)
{
    int v=0;
    for(int i=0;s[i];i++)
    {
        int c=s[i]-'a';
        if(!node[v][c])
            return false;
        v=node[v][c];
    }
    return en[v];
}
void remove(string s)
{
    int v=0;
    for(int i=0;i<s[i];i++)
    {
        prefix[v]--;
        int c=s[i]-'a';
        int nx=node[v][c];
        if(prefix[nx]==1)
        {
            node[v][c]=0;
        }
        v=nx;
    }
    prefix[v]--;
    d-=(--en[v]==0);
}
int main()
{
    int n,m;
    cin>>n>>m;
    string x;
    while(n--)
    {
        cin>>x;
        insert(x);
    }
    remove(x);
    while(m--)
    {
        cin>>x;
        cout<<(search(x)?"YES":"NO")<<'\n';
    }
    return 0;
}
```
### Trie dynamic

insert OR search OR erase **O(L)** Where L length of a word

implementation **O(N * L)** Where n is number of words and L is average length of strings

```cpp
#define N 27
struct node
{
    node* edge[N]={};
    int prefix=0,en=0;
};
class trie
{
    node* root = new node();
    int sz=0,d=0;

public:
    void insert(string str)
    {
        node* cur = root;
        for(int i=0;str[i];i++)
        {
            cur->prefix++;
            int c=str[i]-'a';
            if(cur->edge[c]==nullptr)
            {
                cur->edge[c]=new node();
                sz++;
            }
            cur=cur->edge[c];
        }
        cur->prefix++;
        d+=(++cur->en==1);
    }
    void remove(string str)
    {
        node* cur = root;
        for(int i=0;str[i];i++)
        {
            cur->prefix--;
            int c=str[i]-'a';
            node* nx = cur->edge[c];
            if(nx->prefix==1)
            {
                destroy(nx);
                d--;
                cur->edge[c]=nullptr;
                return;
            }
            cur = nx;
        }
        cur->prefix--;
        cur->en--;
    }
    int search(string str)
    {
        node* cur = reach(str);
        return cur != nullptr ? cur->en: 0;
    }
    int getprefix(string str)
    {
        node* cur = reach(str);
        return cur != nullptr ? cur->prefix: 0;
    }
    int getdistinct() const
    {
        return d;
    }
    void clear()
    {
        destroy(root);
        root = new node();
        sz=d=0;
    }
private:
    node* reach(string str)
    {
        node* cur = root;
        for(int i=0;str[i];i++)
        {
            int c=str[i]-'a';
            node* nx = cur->edge[c];
            if(nx==nullptr)
                return nullptr;
            cur = nx;
        }
        return cur;
    }
    void destroy(node* root)
    {
        if(root==nullptr)
            return ;
        for(int i=0;i<N;i++)
            destroy(root->edge[i]);
        delete root;
    }
};
int main()
{
    trie t;
    t.insert("abc");
    t.insert("adc");
    if(t.search("abc"))cout<<"k";       // k
    t.remove("abc");
    t.clear();
    if(t.search("adc"))cout<<"h";      // m
    else cout<<"m";                 
    cout<<t.getdistinct();             // 0
    return 0;
}
