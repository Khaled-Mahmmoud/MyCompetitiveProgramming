# Om Nom and Spiders

[Problem Link](https://codeforces.com/problemset/problem/436/B)

[Tutorial Link](https://codeforces.com/blog/entry/12680)

```cpp

#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int j=0;
    int n,m,k;
    cin>>n>>m>>k;
    char ar[n][m];
    int br[m];
    memset(br,0,sizeof(br));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>ar[i][j];
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            int cnt = 0;
            if(i>=0&&i<n&&(j+i)>=0&&(j+i)<m)
                cnt += (ar[i][j+i] == 'L');
            if(i>=0&&i<n&&(j-i)>=0&&(j-i)<m)
                cnt += (ar[i][j-i] == 'R');
            if((i-i)>=0&&(i-i)<n&&j>=0&&j<m)
                cnt += (ar[i-i][j] == 'D');
            if(2*i>=0&&2*i<n&&j>=0&&j<m)
                cnt += (ar[2*i][j] == 'U');
            br[j] += cnt;
        }
    for(int j=0; j<m; j++)
        cout<<br[j]<<' ';
    return 0;
}
```
