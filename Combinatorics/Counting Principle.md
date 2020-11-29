### Product Rule

How many words of 3 letters of only B, C? easily: 2 x 2 x 2 = 8.

```cpp
int main()
{
    char letters[] = "BC";
    char answer[4];
    answer[3] = '\0';
    for(int i=0;i<2;i++)
    for(int j=0;j<2;j++)
    for(int k=0;k<2;k++)
    {
        answer[0] = letters[i];
        answer[1] = letters[j];
        answer[2] = letters[k];
        cout<<answer<<'\n';
    }
    return 0;
}
```

General rule: |S1| * |S2| * |S3| … * |Sn|

2 ties, 5 jackets, 4 jeans, 2 shoes: Clothings? 2 x 5 x 4 x 2 = 80 dressing styles

How many binary strings of length 10 are palindromes? Answer: 2^5

How many binary strings of length 10 have odd numbers of one? Answer: 2^9

### Sum Rule

words: {bbb,bc, bbc, bcb, bcc, cbb, cbc, ccb, ccc}

How many words either start with bb or c? 2 + 4 [Notice, no intersection between that]

|A ∪ B| = |A| + |B|	=> [A and B are disjoint]

|A ∪ B ∪ C ∪ D ...| = |A| + |B| + |C| + |D| + ...

How many words either start cb or end bc? 2 + 3? **Wrong** there is overlap: {cbb, cbc} + {bc,bbc, cbc} - {cbc}(intersection) = 2 + 3 - 1 = 4


### Inclusion Exclusion

Most of counting involves duplicate counting  issue [count item more than once].

Inclusion Exclusion principle is a generic sum rule to solve that

|A ∪ B ∪ C| = |A| + |B| + |C| - |A ∩ B| - |A ∩ C| - |B ∩ C| + |A ∩ B ∩ C|

2^3 -1 = 7 subsets (exponential)

**General Computations**

- Enumerate all subsets,

- Compute each one intersection

- If odd subset add (include) it

- If even subset subtract (exclude) it]

**How many integers in {1,2 ...,100} are  divisible by 2, 3, 5 or 7?**

How many  divisible by 2? 100 / 2 = 50

How many  divisible by 3? 100 / 3 = 33

How many divisible by 2, 3? 100 / (2*3) = 16

How many divisible by 2, 3, 7? 100 / 42 = 2 => {42, 84}

Answer: compute 2^4 -1 terms = 15 terms

F(2) + F(3) + F(5) + F(7) - F(2, 3) - F(2, 5) - F(2, 7) - F(3, 5) - F(3, 7) - F(5, 7) + F(2, 3, 5) + F(2, 3, 7) + F(2, 5, 7) + F(3, 5, 7) - F(2, 3, 5, 7)

```cpp
int main()
{
    int ans = 0;
    for(int i2=0;i2<2;i2++)
    for(int i3=0;i3<2;i3++)
    for(int i5=0;i5<2;i5++)
    for(int i7=0;i7<2;i7++)
    {
        int d=1,cnt=0;
        if(i2)d*=2,cnt++;
        if(i3)d*=3,cnt++;
        if(i5)d*=5,cnt++;
        if(i7)d*=7,cnt++;
        if(!cnt)
            continue;
        int sign = cnt&1? 1:-1;
        ans += sign * n/d;
    }
    cout<<ans;
}    
```
**Better Code**
```cpp
int primes[4] = {2,3,5,7};
int n = 100;
int inc_exe(int idx=0,int d=1,int sign=-1)
{
    if(idx==4)
    {
        if(d==1)
            return 0;
        return sign * n/d;
    }
    return inc_exe(idx+1,d,sign)+inc_exe(idx+1,d*primes[idx],sign*-1);
}
int main()
{
    cout<<inc_exe();
}
```

How many integers in {1,2 ...,100} are NOT divisible by 2, 3, 5 or 7?
```cpp
int main()
{
    cout<<n - inc_exe();
}
```

### The Division Rule

A food table with 3 chairs. Given 3 persons, in how many ways we can seat them? 1 2 3, 1 3 2, 2 1 3, 2 3 1, 3 1 2, 3 2 1 => 6 ways

Wrong!	123 same as 231 same as 312 [by making 1 shift], So given 1 seating, we can generate 3 similar seatings.

so answer is 6 / 3 = 2 .. or generally n! / n = n-1!, This is true because we just "fixed" who will be the first, and place others in every possible order.

`nPr(circle) = nPr/r`

Division rule: solution = m / d, where each d elements of m are same (e.g. symmetric)

In an 8x8 chess, how many ways to put rock? Product rule: 8 rows x 8 cols = 64 ways.

In an 8x8 chess, how many ways to put 2 rocks, with no shared rows or columns?

First piece has 64 choices.. then 1 row & 1 col are blocked

So we have 7x7= 49 choices for 2nd rock. Total 64 * 49.

Wrong! (0,0), (1,1) same as (1,1), (0,0)

Symmetry of each 2 rocks. Answer: 64 * 49 / 2

