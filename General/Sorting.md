### Sorting

```cpp
// a vector as can be sorted as follows:
sort(v.begin(),v.end());   // O(nlogn)

// a reverse order is possible as follows:
sort(v.rbegin(),v.rend());
sort(v.begin(),v.end(),greater<int>())


// An ordinary array a can be sorted as follows:
sort(a,a+n);  

// a reverse order is possible as follows:
sort(a,a+n,greater<int>());

// but if there 
long long a[n];
// we can sort it by:
sort(a,a+n,greater<long long>());


//The following code sorts the string s:
string s = "monkey";
sort(str.begin(), str.end());

// a reverse order is possible as follows:
sort(str.rbegin(),str.rend());          OR 
sort(str.begin(),str.end(),greater<char>())
```
Pairs (pair) are sorted primarily according to their first elements (first).
However, if the first elements of two pairs are equal, they are sorted according to
their second elements (second)
```cpp
vector<pair<int,int>> v;
v.push_back({1,5});
v.push_back({2,3});
v.push_back({1,2});
sort(v.begin(), v.end());
```
After this, the order of the pairs is (1,2), (1,5) and (2,3).

In a similar way, tuples (tuple) are sorted primarily by the first element, secondarily by the second element, etc.
```cpp
vector<tuple<int,int,int>> v;
v.push_back(make_tuple(2,1,4));
v.push_back(make_tuple(1,5,3));
v.push_back(make_tuple(2,1,3));
sort(v.begin(), v.end());
After this, the order of the tuples is (1,5,3), (2,1,3) and (2,1,4)
```
**Comparison functions**

to give an external comparison function to the sort function
```cpp
bool pred(string a, string b)
{
    return a < b;
}
sort(v.begin(), v.end(), pred);
```
### How to sort a pair increasing based on first element then decreasing based on second element?

```cpp
bool pred(pair<int, int> a, pair<int, int> b)
{
    if (a.first != b.first)
    {
        return a.first < b.first;
    }
    return a.second > b.second;
}
vector<pair<int,int>>v;
sort(v.begin(), v.end(), pred);
```
### How to declare a set based on specified sorting ?
```cpp
struct cmp
 {
     // notice you should to use (struct cmp, const, &)
     bool operator() (const pair<int, int> &a, const pair<int, int> &b) const  
     {
	 // code
     }
};
set<pair<int,int>,cmp>st;
```
### How to sort an array of structures

this sort is increasing based on first element then decreasing based on second element

```cpp
struct qu
{
    int l, r;
    qu() {}
    // notice you should to put < instead of (), also notice that rhs instead of b
    bool operator<(const qu &rhs) const
    {
        if(l==rhs.l)
        {
            return r > rhs.r;
        }
        return l < rhs.l;
    }
};
qu q[200010];
int main()
{
    int t;cin>>t;
    for(int i=0;i<t;i++)
        cin>>q[i].l>>q[i].r;
    sort(q,q+t);
    cout<<'\n';
    for(int i=0;i<t;i++)
        cout<<q[i].l<<' '<<q[i].r<<'\n';
    return 0;
}
```
To sort a range[l,r] of string where 1<=l<=r<=str.size()
```cpp
sort(&str[l-1], &str[r]);
sort(str.begin() + l - 1, str.begin() + r);
```
### Radix Sort
```cpp
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n, v[100000], t[100000];
void sort()
{
    int f[10] = {};
    int p10 = 1;
    for (int it = 0; it < 10; ++it)
    {
        for (int i = 0; i < n; ++i)
            ++f[v[i] / p10 % 10];
        for (int i = 1; i < 10; ++i)
            f[i] += f[i - 1];
        for (int i = n - 1; i >= 0; --i)
            t[--f[v[i] / p10 % 10]] = v[i];
        for (int i = 0; i < n; ++i)
            v[i] = t[i];
        for (int i = 0; i < 10; ++i)
            f[i] = 0;
        p10 *= 10;
    }
}
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    sort();
    for (int i = 0; i < n; ++i)
        cout << v[i] << " ";
    cout << endl;
    return 0;
}
```
