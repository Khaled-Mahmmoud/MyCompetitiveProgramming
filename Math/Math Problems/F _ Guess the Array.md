# Guess the Array

[Problem Link](https://codeforces.com/contest/727/problem/C)

```cpp
int a[5003];
int arr[5003];
int main()
{
    int n ;
    cin >> n ;
    for ( int i = 2 ; i <= n ; i++ )
    {
        cout << "? " << 1 << " " << i << endl;
        cin >> a[i] ;
    }
    int x;
    cout << "? 2 3" << endl;
    cin >> x ;
    int tmp = a[2] + a[3] - x;
    tmp >>= 1 ;
    arr[1] = tmp ;
    for ( int i = 2 ; i <= n ; i++ )
        arr[i] = a[i] - arr[1] ;
    cout << "! " ;
    for ( int i = 1 ; i <= n ; i++ )
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
```
