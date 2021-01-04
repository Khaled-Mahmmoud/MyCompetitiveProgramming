```cpp
/*
<Bit Manipulation>
X ^ 0 = X
X ^ X = 0
(A ^ B ^ C ^ D ^ E) ^ (A ^ B ^ C) = D ^ E
A ^ B ^ C ^ D = E , if E has any 1s bit, it must have odd number of 1s
X % 2 = X & 1 = bit 0
Generally : X % (2^n) = X & (2^n - 1)
*/
bool get_bit(int num,int idx){return ((num>>idx)&1);}
int set_bit(int num,int idx){return (num|(1<<idx));}
int clear_bit(int num,int idx){return (num&~(1<<idx));}
int flip_bit(int num,int idx){return num^(1<<idx);}
void get_binary(int n)
{
     if(!n)
        return;
     printNumber(n>>1);	
     cout<<(n&1);           
}
int cnt_bit(int mask)
{
    int ret = 0;
    while (mask)
    {
        if(mask&1)
            ret++;
        mask >>= 1;
    }
    return ret;
}
/*
X= 840 	= 011010010000
X-1  = 839 	= 011010001111		What happened? First bit 16=(2^4) is removed, and 15=2^4-1 is added
X & (X-1) 	= 011010000000		first bit from right removed
X & ~(X-1) 	= 011010010000  & 100101110000 = 000000010000	
*/
int least_bit(int num) {return (num & ~(num-1));}
/*
Get last bit using index & -index
+20 = 00010100
-20 = 11101100
20 & -20 = 00000100
Remove last bit : index - (index & -index)
00010100 - 00000100 = 00010000
Removing bits from mask
X = 10010100
Y = 00010100
X - Y removes all Y 1s from X : 10000000
general way to do so: X & ~Y : 10010100 & 11101011 = 10000000
*/
```

