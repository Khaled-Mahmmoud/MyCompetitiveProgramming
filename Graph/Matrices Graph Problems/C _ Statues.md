# Statues

[Problem Link](https://codeforces.com/contest/129/problem/C)
```cpp
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 8;
bool vis[N][N][12];
int dx[] = {1, -1, 0, 0, 1, 1, -1, -1, 0};
int dy[] = {0, 0, 1, -1, 1, -1, 1, -1, 0};
vector<pair<int, int>>v;
bool valid(int i, int j, int t)
{
    if(i < 0 || i >= N || j < 0 || j >= N)
        return 0;
    if(vis[i][j][t])
        return 0;
    for(auto &it : v)
        if(make_pair(it.first + t, it.second) == make_pair(i, j) ||
           make_pair(it.first + t - 1, it.second) == make_pair(i, j))
            return 0;
    return 1;
}
bool dfs(int i, int j, int t)
{
    if(t == 10 || (!i && j == N - 1))
        return 1;
    bool ans = 0;
    vis[i][j][t] = 1;
    for(int k = 0;k < 9;++k)
    {
        int new_x = i + dx[k];
        int new_y = j + dy[k];
        if(valid(new_x, new_y, t + 1))
            ans |= dfs(new_x, new_y, t + 1);
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    for(int i = 0;i < N;++i)
    {
        for(int j = 0;j < N;++j)
        {
            char c;
            cin >> c;
            if(c == 'S')
                v.emplace_back(i, j);
        }
    }
    cout << (dfs(N - 1, 0, 0) ? "WIN" : "LOSE");
    return 0;
}
```
