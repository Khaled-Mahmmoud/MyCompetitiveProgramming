/*

codeforces problem link : https://codeforces.com/contest/235/problem/A
*/
#include <bits/stdc++.h>
#define ll long long
#define N  1000000
using namespace std;
vector<int>d(N);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    ll n;cin>>n;
    if(n<3)cout<<n;
    else if(n%2)cout<<n*(n-1)*(n-2);
    else if(n%3==0)cout<<(n-1)*(n-2)*(n-3);
    else cout<<n*(n-1)*(n-3);
    return 0;
}
