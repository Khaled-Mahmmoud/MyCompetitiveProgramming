# Stirling numbers

### Stirling numbers of Second kind

S(n,k) = number of ways to partition a n objects into k similar boxes

**what is S(5,3) ?**

let's say those 5 objects are 1,2,3,4,5

what are some ways to partition ? we can

box 1: 1,2,3

box 2: 4

box 3: 5

let's write it as 123 / 4 / 5

boxes are **Similar!**

So 123 / 4 / 5 and 4 / 5 / 123 are the same partition, S(5,3) = 25

**Facts**

- S(0,0) = 1
- S(n,0) = 0 for n >= 1
- S(n,1) = 1 for n >= 1
- S(n,n) = 1    each box contains 1 number!
- S(n,n-1) = nCr(n,2) for n >= 1
- S(n,2) = 2^(n-1) - 1
- S(n,k) = S(n-1,k-1) + k * S(n-1,k)


### Stirling numbers of First kind

C(n,k) = number of ways to partition a n objects into k circles

**what is C(5,2) ?**

let's say those 5 objects are 1,2,3,4,5

what are some ways to partition ? we can
```
             1  
circle 1:  2 O 3

circle 2:  4 O 5

Circles are Identical

  1                          1
2 O 3    4 O 5 and 4 O 5   2 O 3   are the same partition


  1                   3
2 O 3    4 O 5 and  1 O 2   4 O 5  are the same partition

  1                   1
2 O 3    4 O 5 and  3 O 2   4 O 5  are Not the same partition

  1             
2 O 3    4 O 5 = (123)(45)

```

**Facts**

- C(n,k) = C(n-1,k-1) + (n-1) * C(n-1,k)
- C(n,n) = 1  n >= 1
- C(0,0) = 1  n >= 1
- C(n,0) = 0  n >= 1


`S(n,k) = (-1)^(n-k) C(n,k)
