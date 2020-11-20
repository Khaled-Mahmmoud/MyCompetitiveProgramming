### Prefix sum

One-dimensional array: O(n)

```cpp
int main()
{
    int n;
    cin>>n;
    vector<int>v(n),prefix(n+1);
    
    for(int i=0;i<n;i++)
        cin>>v[i];
        
    for(int i=1;i<=n;i++)
        prefix_sum[i]=prefix[i-1]+v[i-1];
        
    int q;
    cin>>q;
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        cout<<prefix[r]-prefix[l-1]<<endl;
    }
}
```

Two-dimensional array: O(n * m)

```cpp
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{    
    int n,m;
    cin>>n>>m;
    vector<vector<int>>v(n,vector<int>(m));
    vector<vector<int>>prefix_sum(n+1,vector<int>(m+1));
    
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>v[i][j];
            
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            prefix_sum[i][j] = v[i-1][j-1] + prefix_sum[i][j-1] + prefix_sum[i-1][j] - prefix_sum[i-1][j-1];

    int q;
    cin>>q;
    while(q--)
    {
        int r1,c1,r2,c2;
        cin >>r1>>c1;
        cin >>r2>>c2;
        cout <<PrefixSum[r2][c2]-PrefixSum[r2][c1-1]-PrefixSum[r1-1][c2]+PrefixSum[r1-1][c1-1]<<endl;
    }
}

```
