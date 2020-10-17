# Archer

[Problem Link](https://codeforces.com/contest/312/problem/B)

**Solution** let p=a/b,q=(1-c/d)*(1-a/b). The answer of this problem can be showed as:p*q^0+p*q^1+p*q^2+....

That is the sum of a geometric progression which is infinite but 0<q<1.We can get the limit by the formula:p/(1-q).

```
SmallR, who shoots first can win in the following cases:

1) He shoots the target in the first shot. OR
2) He misses AND his opponent misses AND he shoots the target. OR
3) He misses AND his opponent misses AND he misses AND his opponent misses AND he shoots the target

When there is an OR between 2 events(which lead to same result) happening, it means EITHER of them will lead to the same result, 
so the probability of the result is the SUM OF ALL THESE PROBABILITIES.

the other hand, when there is AND between 2 events, it means that BOTH OF THEM SHOULD HAPPEN TO GET THE DESIRED OUTCOME. So if 
event A happens with probability = 1/2 and event B happens with probability = 1/2 and event C happens when both A and B happen,
then probability of C happening is 1/2 * 1/2 = 1/4, which also makes sense logically. Because C will happen in only 1 out 4 cases, 
when BOTH A and B have happened. You can imagine the 4 cases:

1) A did not happen AND B did not happen => C did not happen
2) A happened AND B did not happen => C did not happen
3) A did not happen AND B happened => C did not happen
4) A happened AND B happened => C happened

So a good rule of thumb is AND means product of probabilities and OR means sum of probabilities.

So now we can get the answer to our problem:

answer = a/b + ( (1-a/b) * (1-c/d) * a/b ) + ( (1-a/b) * (1-c/d) * (1-a/b) * (1-c/d) * a/b )... and so on.

You can sum this up using formula for sum of infinite geometric series.

PS: I know this question was asked 3 years ago, but I hope this helps someone.
```


```cpp
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    double a,b,c,d,p,q;
    cin>>a>>b>>c>>d;
    p = a/b;
    q = (1-c/d)*(1-a/b);
    cout<<fixed<<setprecision(9);
    cout<<p/(1-q);
    return 0;
}
```
