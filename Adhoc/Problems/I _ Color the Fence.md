# Color the Fence

[Problem Link](https://codeforces.com/contest/349/problem/B)

```cpp
long long v,len,rem,arr[10],low=1e6,num;
int main()
{
    cin >> v;
    for(int i = 1;i<=9;i++)
    {
        cin >> arr[i];
        if(arr[i]<low)
            low = arr[i],num = i;
    }
    len = v/low,rem = v%low;
    if(!v || !len)
        return cout << -1,0;
    vector<long long>ans;
    while(len--)
        ans.push_back(num);
    for(auto &i:ans)
        for(int j = 9;j>num;j--)
            if(arr[j]-arr[i]<=rem)
            {
                rem-=(arr[j]-arr[i]),i = j;
                break;
            }
    for(auto i:ans)
        cout << i;
    return 0;
}
```
