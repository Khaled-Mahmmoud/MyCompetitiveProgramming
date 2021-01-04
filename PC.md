```cpp
bool get_bit(int num,int idx){return ((num>>idx)&1);}
int set_bit(int num,int idx){return (num|(1<<idx));}
int clear_bit(int num,int idx){return (num&~(1<<idx));}
int flip_bit(int num,int idx){return num^(1<<idx);}
void get_binary(int n)
{
     if(!n)
        return;
     printNumber(n>>1);	// remove last bit
     cout<<(n&1);           //  print last bit
}
int cnt_bits(int mask)
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
X 	= 840 	= 011010010000
X-1     = 839 	= 011010001111		What happened? First bit 16=(2^4) is removed, and 15=2^4-1 is added
X & (X-1) 	= 011010000000		first bit from right removed
X & ~(X-1) 	= 011010010000  & 100101110000 = 000000010000	value of 1<<SmaintestBitIdx
*/
template<class Int>	
Int least_bit(Int num) { return (num & ~(num-1)); }

```

