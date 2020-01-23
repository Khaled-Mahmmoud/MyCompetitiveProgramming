/*
https://codeforces.com/contest/1270/problem/B
Tutorial
We will show that if some interesting nonempty subarray exists, then also exists some interesting subarray of length 2
Therefore, the solution is as follows: 
for each i from 1 to n−1 check if |a(i+1) − a(i)| ≥ 2 holds. If this is true for some i,
we have found an interesting subarray of length 2 else such subarray doesn't exist
*/
#include <bits/stdc++.h>
#define ll long long
#define N 27
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;cin>>t;while(t--)
    {
        bool flag=true;
        int n;cin>>n;int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=1;i<n;i++)
        if(abs(a[i]-a[i-1])>=2){cout<<"YES\n"<<i<<' '<<i+1;flag=false;break;}
        if(flag)cout<<"NO";cout<<'\n';
    }
    return 0;
}
