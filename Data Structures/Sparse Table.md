### Sparse Table

Sparse table is a data structure that can help us answer range queries on a set on static data (i.e. data that does not change regularly).<br>
Sparse table does pre-processing on the data first, then it can answer range queries efficiently.

More formally, sparse table can calculate the answer of **_Q(l, r)_** on an array **_a[i]_** of length **_n_**.<br>
Where **_Q(l, r)_** can be any _duplicate-invariant function_ as...
- max
- min
- GCD
- LCM

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
// LOG is a pre-computed array where LOG[i] = floor(log2(i))

LOG[1] = 0;
for (int i = 2; i <= n; ++i)
    LOG[i] = LOG[i / 2] + 1;
    
for (int j= 0; j < n; j++) 
{
    ST[0][j] = a[j];
}
for (int i = 1; (1 << i) <= n; i++) 
{
    for (int j = 0; (j + (1 << i)) <= n; j++) 
    {
        int x = ST[i - 1][j];
        int y = ST[i - 1][j + (1 << (i - 1))];

        ST[i][j] = min(x, y);
    }
}
Complexity : O(n.log(n))
```
### Sparse Table Query
Now in order to calculate any **_Q(l, r)_** we are going to use the _duplicate-invariant_ property to get the answer in **_O(1)_** as follows:

```C++

int g = LOG[r - l + 1];

int x = ST[g][l];
int y = ST[g][r - (1 << g) + 1];

return min(x, y);
Complexity : O(1)
```

### Sparse table Problems

**Array Partition**

[Problem Link](https://codeforces.com/contest/1454/problem/F)
[Solution Link](https://codeforces.com/contest/1454/submission/99503441)
