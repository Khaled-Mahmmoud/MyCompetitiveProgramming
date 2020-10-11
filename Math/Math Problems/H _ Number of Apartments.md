# Number of Apartments

[Problem Link](https://codeforces.com/contest/1430/problem/A)

```cpp
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;cin>>t;
	while(t--)
	{
	    int n;cin>>n;
		for(int i=0;i<=7;i++)
		for(int j=0;j<=7;j++)
		{
			int tp=n-3*i-5*j;
			if(tp<0||tp%7)
                continue;
			cout<<i<<' '<<j<<' '<<tp/7<<'\n';
			goto here;
		}
        cout<<-1<<'\n';
        here:;
	}
    return 0;
}
```
