# Qualification Rounds

[Problem Link](https://codeforces.com/problemset/problem/868/C)

```cpp
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[100];
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,k,num;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int z=0;
        for(int j=0;j<k;j++){
            cin>>num;
            z*=2;
            z+=num;
        }
        a[z]++;
    }
    int ans=0;
    if(a[ans])ans=1;
    for (int i=0;i<(1<<k);i++)
		for (int j=0;j<(1<<k);j++)
			if(a[i]&&a[j]&&(!(i&j)))ans=1;
	cout<<(ans?"YES":"NO");
    return 0;
}
```
