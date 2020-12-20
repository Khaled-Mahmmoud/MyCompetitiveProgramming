##  Binary Indexed Tree (Fenwick)

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

**Steps**

- Create a new array of Length N, name it BIT

- BIT[position] = sum of its responsible range

- Then For each Query

- Sum(147)= BIT(147) + BIT(146) + BIT(144) + BIT(128), That is: 4 steps only to get the answer.

- Sum(144) = BIT(144) + BIT(128)

- Sum(15) = BIT(15) + BIT(14) + BIT(12) + BIT(8), Recall: 1111 = 1111, 1110, 1100, 1000, 0

- Sum(11) = BIT(11) + BIT(10) + BIT(8), Recall 1011: 1011, 1010, 1000, 0

- Sum(7) = BIT(7) + BIT(6) + BIT(4) ⇒ 111, 110, 100, 0

![alt text](https://github.com/Khaled-Mahmmoud/MyCompetitiveProgramming/blob/master/img/Tree/fenwick.png)

12 = 1100 ⇒ removing last 1 bit ⇒ 1000 = 8, Then parent of 12 ⇒ 8

Notice: we removed bit at position 2 ⇒ 12 covers 2^2 numbers = 12 - 8 = 4

Notice: 8 = 1000 => has 3 trailing zeros. Try to replace each 0 with 1

1001 = 9, 1010 = 10, 1100 = 12

 number of trailing zeros = number of children … child remove last bit => go to parent
