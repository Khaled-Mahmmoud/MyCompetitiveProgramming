# Statues

[Problem Link](https://codeforces.com/contest/129/problem/C)

[Tutorial Link](https://codeforces.com/blog/entry/3219)

```cpp
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    char c[8][8];int q = 0;
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
        cin>>c[i][j];
    set<pair<int,int>>st;
    st.insert({7,0});
    if(c[6][0]=='.')st.insert({6,0});
    if(c[7][1]=='.')st.insert({7,1});
    if(c[6][1]=='.')st.insert({6,1});

    while(q++<8){
        for(int j=0;j<8;j++)
            for(int i=7;i>=0;i--){
            if(i==7&&c[i][j]=='S')
            c[i][j] = '.';
            if(c[i][j]!='S'&&i>0&&c[i-1][j]=='S')
                c[i][j] = 'S',c[i-1][j] = '.';}

        set<pair<int,int>>st1;
        for(auto z:st){
            int i = z.first, j = z.second;
            if(c[i][j]=='S')
                continue;
            st1.insert(z);
            if(i>0&&c[i-1][j]!='S')
            st1.insert({i-1,j});
            if(i<7&&c[i+1][j]!='S')
            st1.insert({i+1,j});
            if(j>0&&c[i][j-1]!='S')
            st1.insert({i,j-1});
            if(j<7&&c[i][j+1]!='S')
            st1.insert({i,j+1});

            if(i>0&&j>0&&c[i-1][j-1]!='S')
            st1.insert({i-1,j-1});
            if(i<7&&j<7&&c[i+1][j+1]!='S')
            st1.insert({i+1,j+1});
            if(j>0&&i<7&&c[i+1][j-1]!='S')
            st1.insert({i+1,j-1});
            if(j<7&&i>0&&c[i-1][j+1]!='S')
            st1.insert({i-1,j+1});
        }
        st = st1;
    }
    cout<<(st.size()?"WIN":"LOSE");
    return 0;
}
```
