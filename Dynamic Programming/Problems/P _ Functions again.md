# Functions again

Something happened in Uzhlyandia again... There are riots on the streets... Famous Uzhlyandian superheroes Shean the Sheep and Stas the Giraffe were called 
in order to save the situation. Upon the arriving, they found that citizens are worried about maximum values of the Main Uzhlyandian Function f.

which is defined as follows: `f(l,r) = sum(i=l,r-1) | a[i] - a[i+1] | . (-1)^i-l`

In the above formula, 1 ≤ l < r ≤ n must hold, where n is the size of the Main Uzhlyandian Array a, and |x| means absolute value of x. 
But the heroes skipped their math lessons in school, so they asked you for help. 

Help them calculate the maximum value of f among all possible values of l and r for the given array a.

**Input**

The first line contains single integer n (2 ≤ n ≤ 10^5) — the size of the array a.

The second line contains n integers a 1, a 2, ..., a n (-10^9 ≤ a[i] ≤ 10^9) — the array elements.

**Output**

Print the only integer — the maximum value of f.

input

5

1 4 2 3 1

output

3

input

4

1 5 4 7

output

6

**Note**

In the first sample case, the optimal value of f is reached on intervals [1, 2] and [2, 5].

In the second case maximal value of f is reachable only on the whole array.

```cpp
long long dp[100009][2];
long long a[100009];
int main()
{
    int n;
    cin>>n;
    vector<long long> v(n);
    for(int i = 0; i < n; i++)
    {
        cin>>v[i];
        if(i)
            a[i-1] = abs(v[i] - v[i-1]);
    }
    n--;
    dp[n][0] = dp[n][1] = 0;
    long long res = 0;
    for(int i = n-1; i >=0; i--)
    {
        dp[i][0] = a[i] + max(0ll,dp[i+1][1]);
        res = max(res,dp[i][0]);
        dp[i][1] = -a[i] + max(0ll,dp[i+1][0]);
    }
    cout<<res;
    return 0;
}
```
