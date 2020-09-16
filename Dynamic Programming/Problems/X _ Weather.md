# Weather

[Problem Link](https://codeforces.com/contest/234/problem/C)

```cpp
int main()
{
    int n;
    cin>>n;
    int arr[n+1],pos[n+1],neg[n+1];

    for(int i=1; i<=n; i++)
        cin>>arr[i];

    pos[0]=0;
    neg[0]=0;

    for(int i=1; i<=n; i++)
    {
        neg[i] = neg[i-1] + (arr[i]<0);
        pos[i] = pos[i-1] + (arr[i]>0);
    }
    
    int ans=INT_MAX;
    for(int i=1; i<n; i++)
        ans=min(ans,n-(neg[i]-pos[i]+pos[n]));
        
    // notice for this code,there must be positive and negative temperature values, for otherwise we use
    // for(int i=0; i<=n; i++)
    //     ans=min(ans,n-(neg[i]-pos[i]+pos[n]));
    
    cout<<ans;
    return 0;
}
```
