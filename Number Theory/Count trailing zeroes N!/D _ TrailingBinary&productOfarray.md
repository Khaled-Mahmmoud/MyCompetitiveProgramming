
# Count number of trailing zeros in Binary representation of a number using Bitset

|Input |Output|
|---|---|
|8| 3|
|6|1|
    
Binary representation of N is 1000 . Therefore,
number of zeroes at the end is 3

```cpp
int CountTrailingZeros(int n) 
{ 
    bitset<64> bit; 
    bit |= n; 
    int cnt = 0; 
    for (int i = 0; i < 64; i++) 
        if (bit[i]) break; else cnt++;
    return cnt; 
} 
```

Given a array size of n, we need to find the total number of trailing zeros in the product of array

A solution is based on the fact that zeros are formed by a combination of 2 and 5 
Hence the number of zeros will depend on the number of pairs of 2’s and 5’s that can be formed
Ex.: 8 * 3 * 5 * 23 * 17 * 25 * 4 * 11
2^3 * 3^1 * 5^1 * 23^1 * 17^1 * 5^2 * 2^2 * 11^1
In this example there are 5 twos and 3 fives. Hence, we shall be able to form only 3 pairs of (2*5).
Hence will be 3 Zeros in the product
*/
int countZeros(int a[], int n) 
{ 
    int count2=0,count5=0; 
    for (int i=0;i<n;i++) 
    { 
        while(!(a[i]&1))
            a[i]>>=1,count2++; 
        while(!(a[i]%5))
            a[i]=a[i]/5,count5++;
    }
    return min(count2,count5); 
}
