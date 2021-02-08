```cpp
/*
Trie
insert OR search OR erase O(L) Where L length of a word
implementation O(N * L) Where n is number of words and L is average length of strings
*/
// Trie static
#define N 100009
int sz,d;
vector<int>en(N);vector<int>prefix(N);
vector<vector<int>>node(N,vector<int>(27));
//                                     ^ OR 255 for all characters and digits and symbols
void insert(string s)
{
    int cur=0;
    for(int i=0;s[i];i++)
    {
        prefix[cur]++;
        int c=s[i]-'a';
        if(!node[cur][c]) // if 255 we put node[cur][s[i]]
            node[cur][c]=++sz;
        cur=node[cur][c];
    }
    prefix[cur]++;
    d+=(++en[cur]==1);
}
bool search(string s)
{
    int cur=0;
    for(int i=0;s[i];i++)
    {
        int c=s[i]-'a';
        if(!node[cur][c])
            return false;
        cur=node[cur][c];
    }
    return en[cur];
}
void remove(string s)
{
    int cur=0;
    for(int i=0;i<s[i];i++)
    {
        prefix[cur]--;
        int c=s[i]-'a';
        int nx=node[cur][c];
        if(prefix[nx]==1)
        {
            node[cur][c]=0;
        }
        cur=nx;
    }
    prefix[cur]--;
    d-=(--en[cur]==0);
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
// Trie dynamic
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
```
