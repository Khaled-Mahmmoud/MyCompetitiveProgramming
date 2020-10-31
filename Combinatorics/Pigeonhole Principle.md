#  Pigeonhole Principle

Assume we have N=5 boxes and M=6 apples, Distribute apples in boxes in whatever way, There must be 1 box with at least 2 apples.

If you want to avoid duplicate: Put 1 apple per box. Remaining is 1 apple. To put it, one box will have 2 apples.

What if we have 13 apples?

1 box will have at least	⌈13/5⌉ = 3 apples. Generally: ⌈N/M⌉ per a box.

Prove: Among any N positive integers, there	exists 2 whose difference is divisible  by N-1.

Recall: |A-B| % X = 0 IFF A%X = B%X. So, let’s compute % N-1?

Then we have N-1 values, each in range [0 - N-2]. But, we have N numbers, then at least one mode will be duplicate

Given that 2 numbers at least has same % N-1. Then, their difference must be divisible by N-1. Always relate % with Pigeonhole

Case for previous problem: Let A represents array of numbers.

N = 5 and	A = {2, 3, 5, 7, 8}

Compute A % 4 = {2, 3, 1, 3, 0}, 5 numbers, with values [0 - 3].

Pick 2 with same mode - 3 is repeated mode. Then, (3, 7) are the answer
