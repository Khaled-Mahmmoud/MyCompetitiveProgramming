#### Find Second largest element
```cpp
int main()
{
    int n,x,mx1=INT_MIN,mx2=INT_MIN;
    cin>>n;
    while(n--)
    {
        cin>>x;
        if(x>mx1)
        {
            mx2 = mx1;
            mx1 = x;
        }
        else if(x>mx2&&x!=mx1)
            mx2 = x;
    }
    cout<<(mx2==INT_MIN)?-1:mx2;
    return 0;
}
```
Complexity : O(n)
