# Pebble Solitaire

`Bitwise dp`

[Problem Link](https://vjudge.net/problem/UVA-10651)

```cpp
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int setbit(int num,int idx){return (num|(1<<idx));}
int clearbit(int num,int idx){return (num&~(1<<idx));}
bool getbit(int num,int idx){return ((num>>idx)&1);}
int dp[1<<12];
int solve(int mask)
{
    int &rt = dp[mask];
    if(~rt)
        return dp[mask];
    rt = 0;
    for(int i=0;i<12-2;i++)
    {
        if(getbit(mask,i)&&getbit(mask,i+1)&&!getbit(mask,i+2))
        {
            int tmask = mask;
            tmask = clearbit(tmask,i);
            tmask = clearbit(tmask,i+1);
            tmask = setbit(tmask,i+2);
            rt = max(rt,1+solve(tmask));
        }
        if(!getbit(mask,i)&&getbit(mask,i+1)&&getbit(mask,i+2))
        {
            int tmask = mask;
            tmask = setbit(tmask,i);
            tmask = clearbit(tmask,i+1);
            tmask = clearbit(tmask,i+2);
            rt = max(rt,1+solve(tmask));
        }
    }
    return rt;
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int t;cin>>t;while(t--){
        string str;cin>>str;
        int mask = 0,cnt = 0;
        for(int i=0;str[i];i++)
            if(str[i]=='o'){
                mask = setbit(mask,i);
                cnt++;
            }
       memset(dp,-1,sizeof dp);
       cout<<cnt-solve(mask)<<'\n';
    }
    return 0;
}
```
### Better Solution
```cpp
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int dp[1<<12];
typedef bitset<12> MASK;
int solve(MASK mask)
{
    int &rt = dp[mask.to_ulong()];
    if(~rt)
        return rt;
    rt = 0;
    for(int i=0;i<12-2;i++)
    {
        if(mask[i]&&mask[i+1]&&!mask[i+2])
        {
            MASK tmask = mask;
            tmask[i] = tmask[i+1] = 0;
            tmask[i+2] = 1;
            rt = max(rt,1+solve(tmask));
        }
        if(!mask[i]&&mask[i+1]&&mask[i+2])
        {
            MASK tmask = mask;
            tmask[i] = 1;
            tmask[i+1] = tmask[i+2] = 0;
            rt = max(rt,1+solve(tmask));
        }
    }
    return rt;
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int t;cin>>t;while(t--){
        string str;cin>>str;
        int cnt = 0;MASK mask;
        for(int i=0;str[i];i++)
            if(str[i]=='o'){
                mask[i] = 1;
                cnt++;
            }
       memset(dp,-1,sizeof dp);
       cout<<cnt-solve(mask)<<'\n';
    }
    return 0;
}
```

# Kefa and Dishes

`Bitwise dp`

[Problem Link](https://codeforces.com/contest/580/problem/D)

```cpp
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
ll v[19],c[19][19],dp[1<<19][19];
ll solve(int cur,int mask)
{
    if(__builtin_popcount(mask)==m)
        return 0;
    ll &rt = dp[mask][cur];
    if(~rt)
        return rt;
    for(int i=0;i<n;i++)
    {
        if(mask&(1<<i))
            continue;
        int tmask = mask | (1<<i);
        rt = max(rt,v[i]+c[cur][i]+solve(i,tmask));
    }
    return rt;
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int k;
    cin>>n>>m>>k;
    for(int i=0;i<n;i++)
        cin>>v[i];
    while(k--)
    {
        int u,v,ci;
        cin>>u>>v>>ci;
        u--;v--;
        c[u][v] = ci;
    }
    memset(dp,-1,sizeof dp);
    cout<<solve(n,0);
    return 0;
}
```

# Antimatter Ray Clearcutting 

`Bitwise dp` `Geometry`

[Problem Link](https://vjudge.net/problem/UVA-11008)

```cpp
#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool getbit(int n,int idx){return ((n>>idx)&1);}
int setbit(int n,int idx){return (n|(1<<idx));}
int n,m;
int c[20][20];
int x[20],y[20],dp[1<<17];
int cntbit(int n)
{
    int res = 0;
    while(n)
    {
        if(n&1)
            res++;
        n>>=1;
    }
    return res;
}
int solve(int mask)
{
    if(cntbit(mask)>=m)
        return 0;
    if(cntbit(mask)>=m-1)
        return 1;
    int &rt = dp[mask];
    if(~rt)
        return rt;
    rt = 100;
    for(int i=0;i<n;i++)
        if(!getbit(mask,i))
            for(int j=i+1;j<n;j++)
                if(!getbit(mask,j))
                {
                    int tmask = mask | c[i][j];
                    rt = min(rt,1+solve(tmask));
                }
    if(rt==100)
        rt = 1;
    return rt;
}
void build()
{
    for(int i=0; i<n; i++)
        for(int j=i+1; j<n; j++)
        {
            int temp = 0;
            temp = setbit(temp,i);
            temp = setbit(temp,j);
            for(int k=j+1; k<n; k++)
            {
                // Cross Product
                int x1 = x[j] - x[i];
                int y1 = y[j] - y[i];
                int x2 = x[k] - x[i];
                int y2 = y[k] - y[i];
                if(x1*y2==x2*y1)
                    temp = setbit(temp,k);
            }
            c[i][j] = temp;
        }
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int t;
    cin>>t;
    for(int k=1; k<=t; k++)
    {
        cin>>n>>m;
        for(int i=0; i<n; i++)
            cin>>x[i]>>y[i];
        build();
        memset(dp,-1,sizeof dp);
        cout<<"Case #"<<k<<":\n";
        cout<<solve(0)<<'\n';
        if(k<t)
            cout<<'\n';
    }
    return 0;
}
```

# Minimax Problem

`Binary Search` `Bitwise dp`

[Problem Link](https://codeforces.com/contest/1288/problem/D)

```cpp
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,a[300005][10];
pair<int,int>check(int x)
{
	int dp[1<<m];
	memset(dp,-1,sizeof dp);
	for(int i=0;i<n;i++)
	{
		int y = 0;
		for(int j=0;j<m;j++)
			if(a[i][j]>=x)
				y |=(1<<j);
		dp[y] = i;
	}
	for(int i=0;i<(1<<m);i++)
		if(~dp[i])
			for(int j=0;j<(1<<m);j++)
				if(~dp[j]&&((i|j)==(1<<m)-1))
					return {dp[i] + 1 , dp[j] + 1};
	return {-1 , -1};
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> n >> m;
	for(int i = 0;i < n;i++)
		for(int j = 0;j < m;j++)
			cin >> a[i][j];
    pair<int,int> ans,x;
    int low=0,high = 1e9,mid;
	while(low<=high)
	{
		mid = (low+high)/2;
        x = check(mid);
		if(~x.first)
			ans = x , low = mid + 1;
		else
			high = mid - 1;
	}
	cout<<ans.first<<" "<<ans.second;
    return 0;
}
```
