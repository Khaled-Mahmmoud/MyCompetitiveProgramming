#include <bits/stdc++.h>
#define ll long long
#define N 100000
using namespace std;
void fast()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
}
int pred()
{
    static int i=0;
     return ++i;
}
int main()
{
    fast();
    vector<int>v={34,89,23,52};
    generate(v.begin(),v.end(),pred); // 2 3 3 2
    for(int z:v)cout<<z<<' ';
    return 0;
}
