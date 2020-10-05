# Guess the Array

[Problem Link](https://codeforces.com/contest/727/problem/C)

```cpp
#include <bits/stdc++.h>
using namespace std;
int a[5003];
int arr[5003];
int main()
{
    // not to use ios::syn....
    int n ;
    cin >> n ;
    for ( int i = 2 ; i <= n ; i++ )
    {
        cout << "? " << 1 << " " << i << endl;
        fflush(stdout); // use this after each printed line
        cin >> a[i] ;
    }
    int x;
    cout << "? 2 3" << endl;fflush(stdout);
    cin >> x ;
    int tmp = a[2] + a[3] - x;
    tmp >>= 1 ;
    arr[1] = tmp ;
    for ( int i = 2 ; i <= n ; i++ )
        arr[i] = a[i] - arr[1] ;
    cout<< "!" ;
    for ( int i = 1 ; i <= n ; i++ )
        cout<<' '<< arr[i]; // not to use cout<<arr[i]<<' ';
    fflush(stdout);
    return 0;
}
```
