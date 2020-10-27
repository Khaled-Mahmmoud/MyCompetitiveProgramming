# Maximum LCM of three <= n

the maximum possible LCM of three not necessarily distinct positive integers that are not greater than n.

n <= 10^6

**Solution**

Now there are two cases: When n is odd, the answer is obviously n(n-1)(n-2). When n is even, we can still get at least (n-1)(n-2)(n-3), so these three numbers in the optimal answer would not be very small compared to n. So we can just iterate every 3 number triple in [n-50,n] and update the answer.

```cpp
#include <bits/stdc++.h>
#define ll long long
#define N  1000000
using namespace std;
vector<int>d(N);
int main()
{
    ll n;cin>>n;
    if(n<3)cout<<n;
    else if(n%2)cout<<n*(n-1)*(n-2);
    else if(n%3==0)cout<<(n-1)*(n-2)*(n-3);
    else cout<<n*(n-1)*(n-3);
    return 0;
}
```
