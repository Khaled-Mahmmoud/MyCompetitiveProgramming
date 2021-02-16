```
Assume we have N=5 boxes and M=6 apples, Distribute apples in boxes in whatever way, There must be 1 box with at least 2 apples.
What if we have 13 apples? one box will have at least ⌈13/5⌉ = 3 apples. Generally: ⌈N/M⌉ per a box.

Prove: Among any N positive integers, there exists 2 whose difference is divisible by N-1.
Recall: |A-B| % X = 0 IFF A%X = B%X. So, let’s compute % N-1?
Then we have N-1 values, each in range [0 - N-2].  But, we have N numbers, then at least one mode will be duplicate. 
Then, their difference must be divisible by N-1. 
N = 5 and A = {2, 3, 5, 7, 8} Compute A % 4 = {2, 3, 1, 3, 0}, 5 numbers, with values [0 - 3].
Pick 2 with same mode -> 3 is repeated mode. Then, (3, 7) are the answer

Prove: For any N positive integers, find the sum of subset of them is divisible N.
Compute Accum array % N. Accum[i] = {A[0] + A[1]...A[i]} % N
If any Accum[i] = 0, we are done. Otherwise, we have N values in [0 - N-1].
Then 2 positions will have same mode. Then getting numbers between them is answer.
Let A represents array of numbers N = 5 and A = {2, 4, 8, 2, 7}, Accumulate: B = {2, 6, 14, 16, 23}
Mode 5: C = {2, 1, 4, 1, 3} Any zeros? (if yes then A[0]+A[1]...A[i] where C[i] % N = 0. ) 
No..remaining 4 values spread on 5 index...one of them must be repeated. 2nd and 4th have mode 1.
Then range from 3rd till 4th is answer: 8, 2
```
