# Minimum number of steps

[Problem Link](https://codeforces.com/problemset/problem/804/B)

```cpp
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,k,mod=1000000007;
string str;
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>str;
	for(int i=str.size()-1;i>=0;i--)
		if(str[i]=='b')c++;
		else{
			k+=c;c*=2;k%=mod;c%=mod;
		}
	cout<<k;
    return 0;
}
```
