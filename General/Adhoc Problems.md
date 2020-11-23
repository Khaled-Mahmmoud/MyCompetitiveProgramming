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

#### Balanced Bitstring
[Problem Link](https://codeforces.com/contest/1405/problem/C)
[Tutorial Link](https://codeforces.com/blog/entry/82366)

#### Common Divisors
[Problem Link](https://codeforces.com/contest/182/problem/D)
[Solution Link](https://codeforces.com/contest/182/submission/94810395)


