```cpp
bool getbit(int num,int idx){return ((num>>idx)&1);}
int setbit(int num,int idx){return (num|(1<<idx));}
int clearbit(int num,int idx){return (num&~(1<<idx));}
int flipbit(int num,int idx){return num^(1<<idx);}
void printNumber(int n)
{
     if(!n)
        return;
     printNumber(n>>1);	// remove last bit
     cout<<(n&1);           //  print last bit
}

void printNumber(int n, int len)
{
     if(!len)
	return;
     printNumber(n>>1, len-1);	
     cout<<(n&1);		       
}
int countNumBits(int mask) 
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
Int leastBit(Int num) { return (num & ~(num-1)); }

```

