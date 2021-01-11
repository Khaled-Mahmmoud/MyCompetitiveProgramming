```cpp
/*
<Binary Indexed Tree> 
- Given an array of integer N, Assume index 0 always will be 0 (NOT in use)
- 2 query types:(1) Add value val to position index. (2) Sum values from 1 to index
- Segment Tree can be used to such problem : O(N) preprocess, O(NlogN) queries, O(nlogn) memory
- BIT has a better memory order (shorter code) :  O(n) memory + O(NlogN) queries
- Integer = Sum of Powers of 2
- Accumulative Sum = Sum of Sub sums
- Recall: 147 = 128 + 16 + 2 + 1
- Think in accumulative sum (1 to 147) = Sum of last 1 number + Sum of next 2 numbers + Sum of next 16 numbers + Sum of next 128 numbers
- Sum(1,147) = Sum(147,147) + Sum(146,145) + Sum(144,129) + Sum(128,1)
- 147 ⇒ positions {147, 146, 144, 128} with ranges {1, 2, 16,128}
- To get starting positions fast? Remove last bit
- 147 = 010010011 [remove last 1 bit]
- 146 = 010010010 [remove last 1 bit]
- 144 = 010010000 [remove last 1 bit]
- 128 = 010000000 [remove last 1 bit]
- 0 = DONE
- How to interpret:
- 147 responsible for range 147 to > 146
- 146 responsible for range 146 to > 144
- 144 responsible for range 144 to > 128
- 146 responsible for range 128 to > 0

Steps
- Create a new array of Length N, name it BIT
- BIT[position] = sum of its responsible range
- Then For each Query
- Sum(147)= BIT(147) + BIT(146) + BIT(144) + BIT(128), That is: 4 steps only to get the answer.
- Sum(144) = BIT(144) + BIT(128)
- Sum(15) = BIT(15) + BIT(14) + BIT(12) + BIT(8), Recall: 1111 = 1111, 1110, 1100, 1000, 0
- Sum(11) = BIT(11) + BIT(10) + BIT(8), Recall 1011: 1011, 1010, 1000, 0
- Sum(7) = BIT(7) + BIT(6) + BIT(4) ⇒ 111, 110, 100, 0
12 = 1100 ⇒ removing last 1 bit ⇒ 1000 = 8, Then parent of 12 ⇒ 8
Notice: we removed bit at position 2 ⇒ 12 covers 2^2 numbers = 12 - 8 = 4
Notice: 8 = 1000 => has 3 trailing zeros. Try to replace each 0 with 1
1001 = 9, 1010 = 10, 1100 = 12
number of trailing zeros = number of children … child remove last bit => go to parent

Get Interval Accumulation
Sum(15) = BIT(15) + BIT(14) + BIT(12) + BIT(8) = 1111 ⇒ 1110 ⇒ 1100 ⇒ 1000 ⇒ 0 = STOP
15 is responsible for 1 number, 14 for 2, 12 for 4, 8 for 8 numbers
*/
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
/*
Updating position
Position 1: Covered by 4 intervals ⇒ 1, 2, 4, 8
Add -3 to 1 ⇒ add -3 to these 4 intervals

Given index, how to get smallest position covering it?
E.g. 1 ⇒ 2 6 ⇒ 8 10 ⇒ 12 13 ⇒ 14
Then 1 goes to 2...2 goes to 4..4 goes to 8 [recursive]
Recall given number idx it covers 2^r values where r is position of “last bit”.
All following numbers cover 8 values
- (0001000, 0101000, 1101000, 1111000, 1001000) ⇒ r = 3 ⇒ 2^3 = 8
- So our focus on “last bit”, NOT before that

Let’s get who covers 4 = 0100
4 has “last bit” at k = 2, When target number enumerate its 2^r, one contains 100
So we need to go at least 1 bit higher than k, E.g. re-set last bit k = 3 ⇒ 1000 ⇒ first one to cover 0100

Let’s get who covers 5 = 0101
k = 0, We need target number to include our 1 at k = 0
The earlier one should exist in smallest coverer number. So again, shift k = 0 1 step to be in its enumeration
E.g. re-set last bit k = 1 ⇒ 110. Note, 1000 also cover 5 Updating position

Let’s get who covers 3 = 0011, “last bit” at k = 0
We need enumeration includes whole 11. So parent need to be a 1 before these 11. E.g. ⇒ 0100

How to get that number easily?
Just add 2^k ⇒ if one or more bits ⇒ shifted. E.g. 100100011100 + 000000000100 = 100100100000

Notice: 8 = 1000 => has 3 trailing zeros. Remove last bit, and add 1, 2, 3...trailing ones
0100 = 4, 0110 = 6, 0111 = 7
number of trailing zeros = number of children
*/
void add(ll idx,ll val)
{
    while(idx<MAX_VAL)
    {
        bit_tree[idx] += val;
        idx += (idx & -idx);
    }
}
/*
Index with cumulative sum
Assume we have array of values >= 0, Accumulate it ⇒ increasing sequence
- Find first index with accumulation >= value
- Given that it is increasing, using binary search is direct
- BIT maintain such accumulation by definition, if all values >= 0
*/
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
// How to get value of indx
int get_value(int idx)
{
    return get_accum(idx) - get_accum(idx-1);
}
```
