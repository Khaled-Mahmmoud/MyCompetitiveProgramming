/*
you are given an array of n integers
Your task is to calculate the minimum number of integers you need to remove so that the greatest common divisor of the remaining integers 
is bigger than that of all integers
codeforces problem link : https://codeforces.com/problemset/problem/1034/A

Solution 
First we divide all numbers by GCD of them. Then we should find a subset with maximum number of integers GCD of which is bigger than 1
We can enumerate a prime p that GCD of the remaining integers can be divided by. And the number of integers can be divided by p is 
the maximum size of the subset
We can use Sieve of Euler to factor all integers Then we find the prime that can divide most integers . The answer is n minus the number 
of integers can be divided by this prime. If all integers are 1 (after dividing their GCD), there is no solution.

*/

#include <bits/stdc++.h>
#define ll long long
#define N  15000009
using namespace std;
int gcd(int a,int b)
{
    if(!b)return a;
    return gcd(b,a%b);
}
vector<int>spf(N);
void sieve()
{
    for(int i=0;i<N;i++)
        if(i&1)spf[i]=i;else spf[i]=2;
    for(int i=3;i<=sqrt(N);i+=2)
    if(spf[i]==i)
        for(int j=i*i;j<N;j+=i)
        if(spf[j]==j)spf[j]=i;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);sieve();
    map<int,int>m;
    int n,g=0;cin>>n;int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i],g=gcd(g,a[i]);
    for(int i=0;i<n;i++)a[i]/=g;
    for(int i=0;i<n;i++)
    {
        vector<int>res;
        while(a[i]!=1)
        {
            res.push_back(spf[a[i]]);
            a[i]/=spf[a[i]];
        }
        int x=res.size();  // there was 18 wrong answer bacause of RN ( random number)
        res.push_back(-1);
        for(int j=0;j<x;j++)
            if(res[j]!=res[j+1])
            m[res[j]]++;

    }
    if(m.empty())cout<<-1;
    else
    {
        int cnt=0;
        for(auto x:m)
        {
            cnt=max(cnt,x.second);
        }
        cout<<n-cnt;
    }
    return 0;
}
