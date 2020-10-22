# Constructing the Array

[Problem Link](https://codeforces.com/problemset/problem/1353/D)

[Tutorial Link](https://codeforces.com/blog/entry/77373)

```cpp
#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct cmp
 {
	bool operator() (const pair<int, int> &a, const pair<int, int> &b) const  // notice you should to use struct cmp ,const , & and please save this for me
	{
		int lena = a.second - a.first + 1;
		int lenb = b.second - b.first + 1;
		if (lena == lenb) return a.first < b.first;
		return lena > lenb;
	}
};
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    int t;cin>>t;while(t--)
    {
        int n;cin>>n;
        vector<int>v(n);
        set<pair<int,int>,cmp>st;
        st.insert({0,n-1});
        for(int i = 1; i <= n; ++i)
        {
            pair<int, int> cur = *st.begin();
			st.erase(st.begin());
			int id = (cur.first + cur.second) / 2;
			v[id] = i;
			if (cur.first < id) st.insert({cur.first, id - 1});
			if (id < cur.second) st.insert({id + 1, cur.second});
        }
        for (auto z:v) cout << z << " ";
        cout<<"\n";
    }
    return 0;
}
```
