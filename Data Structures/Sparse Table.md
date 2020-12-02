### Sparse Table 

`Jump powers of 2`

Sparse table is a data structure that can help us answer range queries on a set on static data (i.e. data that does not change regularly).<br>
Sparse table does pre-processing on the data first, then it can answer range queries efficiently.

More formally, sparse table can calculate the answer of **_Q(l, r)_** on an array **_a[i]_** of length **_n_**.<br>
Where **_Q(l, r)_** can be any _duplicate-invariant function_ as (max / min / GCD / LCM)

What I mean by _duplicate-invariant function_ is any function that output the same value for duplicate inputs.<br>
So for example:<br>

| Function                          | Description                                |
| ----------------------------------|:------------------------------------------:|
| _min(2, 3) = min(2, 2, 3, 3) = 2_ | minimum is _duplicate-invariant function_  |
| _(2 + 3) != (2 + 2 + 3 + 3)_      | addition is not _duplicate-invariant_.     |

### Sparse Table Structure
The structure of sparse table is a 2D array **_ST[j][i]_**,<br>
where the **_j_**-th row in the sparse table holds the answer of queries of length **2^j**.

More formally, **_ST[j][i]_** holds the value of **_Q(i, i + (2^j) - 1)_**

We can build the sparse table easily in **_O(n.log(n))_** as follows (having **_Q()_** equals **_min()_** as an example):

```Cpp
const int N = 2e5 + 5, K = 25;
int mn[N][K + 1], lg[N + 1];
void build() 
{
    lg[1] = 0;
    for(int i = 2; i <= n; ++i)
        lg[i] = lg[i / 2] + 1;
    for(int i = 0; i < n; ++i)
        mn[i][0] = arr[i];
    for(int j = 1; j <= K; ++j) 
    {
        for (int i = 0; i + (1 << j) <= n; ++i)
        {
            mn[i][j] = min(mn[i][j - 1], mn[i + (1 << (j - 1))][j - 1]);
        }
    }
}
Complexity : O(n.log(n))
```
### Sparse Table Query
Now in order to calculate any **_Q(l, r)_** we are going to use the _duplicate-invariant_ property to get the answer in **_O(1)_** as follows:

```C++
int get_min(int l, int r) 
{
    int j = lg[r - l + 1];
    return min(mn[l][j], mn[r - (1 << j) + 1][j]);
}
Complexity : O(1)
```

**Array Partition**

[Problem Link](https://codeforces.com/contest/1454/problem/F)
[Solution Link](https://codeforces.com/contest/1454/submission/99503441)


