```cpp
const int max_val = 30000;
int bit_tree[max_val];
int getAccum(int idx)
{
    int sum = 0;
    while(idx>0)
    {
        sum += bit_tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}
void add(ll idx,ll val)
{
    while(idx<MAX_VAL)
    {
        bit_tree[idx] += val;
        idx += (idx & -idx);
    }
}
int get_idx(int accum)
{
    int s = 1, e = MAX_VAL;
    while(s<e)
    {
        int mid_idx = (s+e)/2;
        int val = get_accum(mid_idx);
        if(val>=accum)
            e = mid_idx;
        else
            s = mid_idx + 1;
    }
    return s;
}
int get_value(int idx)
{
    return get_accum(idx) - get_accum(idx-1);
}
```
