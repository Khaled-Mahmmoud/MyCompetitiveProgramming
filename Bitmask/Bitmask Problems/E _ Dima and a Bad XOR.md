# Dima and a Bad XOR

[Problem Link](https://codeforces.com/contest/1151/problem/B)

[Tutorial Link](https://codeforces.com/blog/entry/66602)

```cpp
#define ll long long
int n,m;
int arr[509][509];
void print(int id,int x)
{
    cout<<"TAK"<<endl;
    for(int i=0; i<n; i++)
        if(i == id)
            cout<<x<<" ";
        else
            cout<<1<<" ";
    cout<<endl;
    exit(0);
}
int main()
{
    cin>>n>>m;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>arr[i][j];

    int Xor = 0;
    for(int i=0; i<n; i++)
        Xor ^= arr[i][0];

    if(Xor > 0)
        print(-1,-1);

    for(int i=0; i<n; i++)
        for(int j=1; j<m; j++)
            if(arr[i][j] != arr[i][0])
                print(i,j+1);

    cout<<"NIE"<<endl;
    return 0;
}
```
