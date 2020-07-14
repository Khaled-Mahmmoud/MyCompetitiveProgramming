# Range Minimum Query

Given an array A of size N, there are two types of queries on this array.

1) qlr In this query you need to print the minimum in the sub-array A[L : R].
2) uxy In this query you need to update A[x] = y.

**Input** 

First line of the test case contains two integers, N and Q, size of array A and number of queries.

Second line contains N space separated integers, elements of A.

Next Q lines contain one of the two queries.

**Output**

For each type 1 query, print the minimum element in the sub-array .

**Contraints**

1 <= N , Q , y , A[i] <= 10^5

1 <= L , R , x <= N

**SAMPLE INPUT**

5 5
1 5 2 4 3
q 1 5
q 1 3
q 3 5
u 3 6
q 1 5

**SAMPLE OUTPUT**
1
1
2
1
