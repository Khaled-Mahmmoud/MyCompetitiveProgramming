```cpp
/*
2 query types:
Add value val to position index
Sum values from 1 to index
Segment Tree    O(N) preprocess, O(NlogN) queries, O(nlogn) memory
Binary Indexed  O(N) preprocess, O(NlogN) queries, O(N) memory 
*/
const int max_val = 30000;
int bit_tree[max_val];
// return the sum of values in interval [1, idx].
int get(int idx)
{
    int sum = 0;
    while(idx>0)
    {
        sum += bit_tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}// O(log(n))
// Updates an element in the Fenwick tree
void update(ll idx,ll val)
{
    while(idx<max_val)
    {
        bit_tree[idx] += val;
        idx += (idx & -idx);
    }
}// O(log(n))
int get_idx(int accum)
{
    int s = 1, e = MAX_VAL;
    while(s<e)
    {
        int mid_idx = (s+e)/2;
        int val = get(mid_idx);
        if(val>=accum)
            e = mid_idx;
        else
            s = mid_idx + 1;
    }
    return s;
}
int get_value(int idx)
{
    return get(idx) - get(idx-1);
}
Note that the tree is 1-indexed.
```
