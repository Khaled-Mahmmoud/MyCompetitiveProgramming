```CPP
__Inclusion Exclusion__
/*
Most of counting involves duplicate counting issue [count item more than once].
Inclusion Exclusion principle is a generic sum rule to solve that
|A ∪ B ∪ C| = |A| + |B| + |C| - |A ∩ B| - |A ∩ C| - |B ∩ C| + |A ∩ B ∩ C|
Enumerate all subsets, Compute each one intersection If odd subset add (include) it If even subset subtract (exclude) it.

How many integers in {1,2 ...,100} are divisible by 2, 3, 5 or 7?
F(2) + F(3) + F(5) + F(7) - F(2, 3) - F(2, 5) - F(2, 7) - F(3, 5) - F(3, 7) - F(5, 7) + F(2, 3, 5) 
+ F(2, 3, 7) + F(2, 5, 7) + F(3, 5, 7) - F(2, 3, 5, 7)
*/
int p[100];
int n,m;ll ans;
vector<int>sub;
ll lcm(ll a,ll b)
{
    return a/__gcd(a,b)*b;
}
void inc_exe(int idx = 0)
{
    if(idx==m)
    {
        if(sub.empty())
            return;
        ll d = sub[0];
        for(int i=1;i<sz(sub);i++)
            d = lcm(d,sub[i]);
        if(sz(sub)&1)
            ans += n/d;
        else
            ans -= n/d;
        return;
    }
    sub.push_back(p[idx]);
    inc_exe(idx+1);
    sub.pop_back();
    inc_exe(idx+1);
}
// Complexity : O(2^n)
```
