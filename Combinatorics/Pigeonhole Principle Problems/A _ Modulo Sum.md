# Modulo Sum

You are given a sequence of numbers a1, a2, ..., an, and a number m.

Check if it is possible to choose a non-empty subsequence aij such that the sum of numbers in this subsequence is divisible by m.

**Input** :
The first line contains two numbers, n and m (1 ≤ n ≤ 106, 2 ≤ m ≤ 103) — the size of the original sequence and the number such that sum should be divisible by it.

The second line contains n integers a1, a2, ..., an (0 ≤ ai ≤ 109).

**Output** :
In the single line print either "YES" (without the quotes) if there exists the sought subsequence, or "NO" (without the quotes), if such subsequence doesn't exist.

**Examples**


input 

3 5

1 2 3

output : YES

input

1 6

5

output : NO

input

4 6

3 1 1 3

output : YES

input

6 6

5 5 5 5 5 5

output : YES

**Note**

In the first sample test you can choose numbers 2 and 3, the sum of which is divisible by 5.

In the second sample test the single non-empty subsequence of numbers is a single number 5. Number 5 is not divisible by 6, that is, the sought subsequence doesn't exist.

In the third sample test you need to choose two numbers 3 on the ends.

In the fourth sample test you can take the whole subsequence.

**Solution**

Let's consider two cases: n > m and n ≤ m.

If n > m, let's look at prefix sums. By pigeonhole principle, there are two equals sums modulo m. Assume Slmodm = Srmodm. Then the sum on segment [l + 1, r] equals zero modulo m, that means the answer is definitely "YES".

If n ≤ m, we'll solve this task using dynamic programming in O(m^2) time. Assume can[i][r] means if we can achieve the sum equal to r modulo m using only first i - 1 items. The updates in this dynamic programming are obvious: we either take number ai and go to the state can[i + 1][(r + ai) mod m] or not, then we'll get to the state can[i + 1][r].

```cpp
vector<int>v;int dp[1009][1009];
int m;
bool subset(int n,int sum,bool x)
{
    if(!sum&&x)return true;
    if(!n)return false;
    int &rt = dp[n][sum];
    if(~rt)return rt;
    return rt = subset(n-1,sum%m,x)||subset(n-1,(sum+v[n-1])%m,true);
}
int main()
{
    int n;
    cin>>n>>m;
    v.resize(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        v[i] = v[i] % m;
    }
    memset(dp,-1,sizeof dp);
    if(n>m)
        cout<<"YES";
    else
    {
        if(subset(n,0,0))
            cout<<"YES";
        else
            cout<<"NO";
    }
    return 0;
}
```
