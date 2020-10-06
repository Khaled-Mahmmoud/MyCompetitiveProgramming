# Phoenix and Beauty

[Problem Link](https://codeforces.com/problemset/problem/1348/B)

[Tutorial Link](https://codeforces.com/blog/entry/76555)

```cpp
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin>>N>>K;
        set<int>s;
        for (int i=0; i<N; i++)
        {
            int a;
            cin>>a;
            s.insert(a);
        }
        //if more than K distinct numbers, print -1
        if (s.size()>K)
            cout<<-1;

        else
        {
            cout<<N*K<<endl;
            for (int i=0; i<N; i++)
            {
                //print the distinct numbers
                for (int b:s)
                    cout<<b<<' ';
                //print the extra 1s
                for (int j=0; j<K-(int)s.size(); j++)
                    cout<<1<<' ';
            }
        }
        cout<<endl;
    }
    return 0;
}
```
