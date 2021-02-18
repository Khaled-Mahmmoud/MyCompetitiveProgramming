```cpp
int k;
int jose(int n)
{
    if (!n)
        return n;
    return (jose(n-1)+k) % n;
}
void josephus()
{
    int n;
    cin>>n>>k;
    cout<<jose(n)+1;
}
```
