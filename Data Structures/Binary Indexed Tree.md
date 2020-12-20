##  Binary Indexed Tree (Fenwick)

- Given an array of integer N, Assume index 0 always will be 0 (NOT in use)
- 2 query types:(1) Add value val to position index. (2) Sum values from 1 to index
- Segment Tree can be used to such problem : O(N) preprocess, O(NlogN) queries, O(nlogn) memory
- BIT has a better memory order (shorter code) :  O(n) memory + O(NlogN) queries

