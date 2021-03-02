```cpp
/*
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
X    = 840 	= 011010010000
X-1  = 839 	= 011010001111	What happened? First bit 16=(2^4) is removed, and 15=2^4-1 is added
X & (X-1) 	= 011010000000	first bit from right removed
X & ~(X-1) 	= 011010010000  & 100101110000 = 000000010000	
*/
int lsb(int num) {return (num & ~(num-1));}
int msb(int n) 
{ 
    if (!n) 
        return 0; 
    int cnt = -1; 
    while(n)
    { 
        n>>=1; 
        cnt++; 
    } 
    return (1<<cnt);
} 
/*
Removing bits from mask
X = 10010100
Y = 00010100
X - Y removes all Y 1s from X : 10000000
general way to do so: X & ~Y : 10010100 & 11101011 = 10000000

Get last bit using index & -index
+20 = 00010100
-20 = 11101100
20 & -20 = 00000100
Remove last bit : index - (index & -index)
00010100 - 00000100 = 00010000
*/
bool is_power_of_two(ll n)
{
    return (x&&!(n&(n-1)));
}
void get_binary_len(int n, int len)
{
    if(!len)
        return;
    get_binary_len(n>>1, len-1);
    cout<<(n&1);
}
// len = 3: 000, 001, 010, 011, 100, 101, 110, 111
void get_subset_binary(int len)	
{
   for (int i = 0; i < (1<<len); ++i)
   {
        get_binary_len(i,len);
        cout<<' ';
   }
}
/*
binary    gray
 0111	0100
in gray code, every bit is Xor of its bit and last one in binary
*/
int gray_code(int i)
{
    return i ^ (i>>1);
}
/*
One’s complement of a binary number is the inverse of the digits, change all 0's to 1's and all 1's to 0's.
Two’s Complement is start to flip after the “last bit”.
-number = 2’s complement of number or Get 1’s complement...then add 1
*/

```
