// for implementation O(N * L) Where n is number of words and L is average length of strings
// for insert OR search OR erase O(L) Where L length of a word
#include <bits/stdc++.h>
#define ll long long
#define N 100009
using namespace std;
int sz,d;
vector<int>en(N);vector<int>cnt(N);
vector<vector<int>>node(N,vector<int>(27));
//                                     ^ OR 255 for all characters and digits and symbols
void insert(string s)
{
    int v=0;
    for(int i=0;s[i];i++)
    {
        cnt[v]++;
        int c=s[i]-'a';
        if(!node[v][c]) // if 255 we put node[v][s[i]]
            node[v][c]=++sz;
        v=node[v][c];
    }
    cnt[v]++;
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
        cnt[v]--;
        int c=s[i]-'a';
        int nx=node[v][c];
        if(cnt[nx]==1)
        {
            node[v][c]=0;
        }
        v=nx;
    }
    cnt[v]--;
    d-=(--en[v]==0);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
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
