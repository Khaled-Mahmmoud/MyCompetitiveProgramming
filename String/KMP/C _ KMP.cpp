// Time Complexity O(n+m)
#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;
void fast()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
}
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
void kmp(string str,string pat)
{
    int n=str.size(),m=pat.size();
    vector<int>prefix=getprefix(pat);
    for(int i=0,k=0;i<n;i++)
    {
        while(k>0&&str[i]!=pat[k])
            k=prefix[k-1];
        if(str[i]==pat[k])k++;
        if(k==m)
        {
            cout<<i-m+1<<' ';
            k=prefix[k-1];
        }
    }
}
int main()
{
    fast();
    string str,pat;
    cin>>str>>pat;
    kmp(str,pat);
    return 0;
}
