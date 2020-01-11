// for implementation O(N * L) Where n is number of words and L is average length of strings
// for insert OR search OR erase O(L) Where L length of a word
#include <bits/stdc++.h>
#define ll long long
#define N 27
using namespace std;
struct node
{
    node* edge[N]={};
    int cnt=0,en=0;
};
class trie
{
    node* root;
    int sz=0,d=0;

public:
    trie()
    {
        root=new node();
        sz=d=0;
    }
    ~trie()
    {
        destroy(root);
    }
    void clear()
    {
        destroy(root);
        root = new node();
        sz=d=0;
    }
    void insert(const char* s)
    {
        node* cur = root;
        for(int i=0;s[i];i++)
        {
            cur->cnt++;int c=s[i]-'a';
            if(cur->edge[c]==nullptr)
            {
                cur->edge[c]=new node();
                sz++;
            }
            cur=cur->edge[c];
        }
        cur->cnt++;
        d+=(++cur->en==1);
    }
    void remove(const char* s)
    {
        node* cur = root;
        for(int i=0;s[i];i++)
        {
            cur->cnt--;int c=s[i]-'a';
            node* nx = cur->edge[c];
            if(nx->cnt==1)
            {
                destroy(nx);
                d--;
                cur->edge[c]=nullptr;
                return;
            }
            cur = nx;
        }
        cur->cnt--;
        cur->en--;
    }
    int search(const char* str)const
    {
        node* cur = reach(str);
        return cur != nullptr ? cur->en: 0;
    }
    int getprefix(const char* str)const
    {
        node* cur = reach(str);
        return cur != nullptr ? cur->cnt: 0;
    }
    int getdistinct() const
    {
        return d;
    }
private:
    node* reach(const char* s)const
    {
        node* cur = root;
        for(int i=0;s[i];i++)
        {
            int c=s[i]-'a';
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
        {
            destroy(root->edge[i]);
        }
        delete root;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
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
