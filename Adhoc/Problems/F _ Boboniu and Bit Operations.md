# Boboniu and Bit Operations

Boboniu likes bit operations. He wants to play a game with you.

Boboniu gives you two sequences of non-negative integers a[1],a[2],…,a[n] and b[1],b[2],…,b[m].

For each i (1 ≤ i ≤ n), you're asked to choose a j (1 ≤ j ≤ m) and let c[i] = a[i] & b[j], where & denotes the bitwise AND operation. 
Note that you can pick the same j for different i's.

Find the minimum possible c[1]|c[2]| ..... |c[n], where | denotes the bitwise OR operation.

**Input**

The first line contains two integers n and m (1 ≤ n , m ≤ 200).

The next line contains n integers a1,a2,…,an (0 ≤ a[i] < 2^9).

The next line contains m integers b1,b2,…,bm (0 ≤ b[i] < 2^9).

**Output**

Print one integer: the minimum possible c[1] | c[2] | .... | c[n].


input

4 2

2 6 4 0

2 4

output

2

input

7 6

1 9 1 9 8 1 0

1 1 4 5 1 4

output

0

input

8 5

179 261 432 162 82 43 10 38

379 357 202 184 197

output

147

Note

For the first example, we have c[1] = a[1] & b[2] = 0, c[2] = a[2] & b[1] = 2, c[3] = a[3] & b[1] = 0, c[4] = a[4] & b[1] = 0.Thus c[1] | c[2] | c[3] | c[4] = 2, and this is the minimal answer we can get.

```cpp
int main()
{
    int n,m;
    cin >> n >> m;
    int a[n], b[m];
    for(int i = 0;i < n;++i)
        cin >> a[i];
    for(int i = 0;i < m;++i)
       cin >> b[i];
    for(int i = 0;i < (1 << 9);++i)
    {
        bool valid = 1;
        for(int j = 0;j < n;++j)
        {
            bool tmp = 0;
            for(int k = 0;k < m;++k)
                if((i | (a[j] & b[k])) == i)
                    tmp = 1;
            if(!tmp)    valid = 0;
        }
        if(valid)   return cout << i, 0;
    }
    return 0;
}
```
