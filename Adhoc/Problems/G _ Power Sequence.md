# Power Sequence

Let's call a list of positive integers a[0],a[1],...,a[n−1] a power sequence if there is a positive integer c, so that for every 0 ≤ i ≤ n−1 then ai = c^i

Given a list of n positive integers a[0],a[1],...,a[n−1], you are allowed to:

- Reorder the list (i.e. pick a permutation p of {0,1,...,n−1} and change a[i] to a[p[i]]), then
- Do the following operation any number of times: pick an index i and change a[i] to a[i]−1 or a[i]+1 (i.e. increment or decrement ai by 1) with a cost of 1.

Find the minimum cost to transform a[0],a[1],...,a[n−1] into a power sequence.

Input :
The first line contains an integer n (3 ≤ n ≤ 10^5).

The second line contains n integers a[0],a[1],...,a[n−1] (1 ≤ a[i] ≤ 10^9).

Output : 
Print the minimum cost to transform a[0],a[1],...,a[n−1] into a power sequence.

input

3

1 3 2

output

1

input

3

1000000000 1000000000 1000000000

output

1999982505

Note : In the first example, we first reorder {1,3,2} into {1,2,3}, then increment a2 to 4 with cost 1 to get a power sequence {1,2,4}.

```cpp
using namespace std;
int main()
{
    int n;cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    long long ans = 1e18;
    for(long long i=1;i*n<=10000000;i++)
    {
        long long res = 0,p = 1;
        bool flag = false;
        for(int j=0;j<n;j++)
        {
            if(p>1e10)
                flag = true;
            res += abs(a[j]-p);
            p = p * i;
        }
        if(flag)
            continue;
        ans = min(ans,res);
    }
    cout<<ans;
    return 0;
}
```
