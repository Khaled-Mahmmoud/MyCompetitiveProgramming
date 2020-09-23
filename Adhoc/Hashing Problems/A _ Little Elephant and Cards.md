# Little Elephant and Cards

[Problem Link](https://codeforces.com/contest/205/problem/D)

```cpp
int main()
{
    int n;
    cin>>n;
    map<string,int>mx,my;
    map<string,bool>flag;
    int need = ceil((float)n/2);
    int a[n],b[n],ans = INT_MAX;
    string x,y;
    for(int i=0; i<n; i++)
    {
        cin>>a[i]>>b[i];
        x = to_string(a[i]);
        y = to_string(b[i]);
        if(x==y)
            mx[x]++;
        else
        {
            mx[x]++;
            my[y]++;
        }
    }
    for(int i=0; i<n; i++)
    {
        x = to_string(a[i]);
        if(!flag[x])
        {
            flag[x] = true;
            if(mx[x]+my[x]>=need)
            {
                int m = need;
                m-=mx[x];
                if(m>0)
                    ans = min(ans,m);
                else
                    ans = 0;
            }
        }

        y = to_string(b[i]);
        if(!flag[y])
        {
            if(mx[y]+my[y]>=need)
            {
                int m = need;
                m-=mx[y];
                if(m>0)
                    ans=min(ans,m);
                else
                    ans=0;
            }
        }
    }
    if(ans==INT_MAX)
        cout<<-1;
    else
        cout<<ans;
    return 0;
```

Time Complexity : O(nlogn)

The Idea of Solution : that we use `m["485697823"]` instead of `m[485697823]` that gives time limited
