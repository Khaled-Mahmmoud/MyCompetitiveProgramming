```cpp
/*
<Sparse Table>
Sparse table is a data structure that can help us answer range queries on a set on static data
More formally, sparse table can calculate the answer of Q(l, r) on an array a[i] of length n
Where Q(l, r) can be any _duplicate-invariant function_ as (max / min / GCD / LCM)
What I mean by _duplicate-invariant function_ is any function that output the same value for duplicate inputs.
| Function                          | Description                              |
| min(2, 3) = min(2, 2, 3, 3) = 2   | minimum is duplicate-invariant function  |
| (2 + 3) != (2 + 2 + 3 + 3)        | addition is not duplicate-invariant      |

Sparse Table Structure
The structure of sparse table is a 2D array ST[j][i]
where the j-th row in the sparse table holds the answer of queries of length 2^j
More formally, ST[j][i] holds the value of Q(i, i + (2^j) - 1)
We can build the sparse table easily in O(n.log(n)) as follows (having Q() equals min() as an example):
*/
const int N = 2e5 + 5, K = 25;
int arr[N], mn[N][K + 1], lg[N + 1];
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
// O(n.log(n))
// Sparse Table Query
// Now in order to calculate any Q(l, r) we are going to use the duplicate-invariant property to get the answer in O(1) as follows:

int get_min(int l, int r) 
{
    int j = lg[r - l + 1];
    return min(mn[l][j], mn[r - (1 << j) + 1][j]);
}
// O(1)
```
