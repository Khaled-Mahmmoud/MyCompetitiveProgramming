/*
Why using Bit Manipulation ?
1) better time order
2) better memory order
3) make code shorter

A ^ B ^ C ^ D = E	For any bit in E with 1, E must have odd number of 1s
X ^ 0 = X	              	X ^ X = 0
(A ^ B ^ C ^ D ^ E) ^ (A ^ B ^ C) = D ^ E


X << 1	 =  100100000000		Equals X*2 but (faster) 
X << 2	 =  1001000000000		Equals X*4 but (faster) 
X >> 1	 = 	1001000000 		Equals X/2 but (faster) 
X >> 2	 = 	100100000 		Equals X/4 but (faster) 
1 << X   =                              Equals 2^X but (faster) 

          X = 26 = 11010 
     1     1    0     1     0
    2^4 + 2^3 + 2^2 + 2^1 + 2^0 
     16 +  8  +  0  +  2  +  0   
     
X = 11010 = 26		// Last Bit shows Parity : Even / Odd
X = 11011 = 27

X % 2 = X & 1 = bit 0
(X & 1) we use it to check if number is even or odd (faster)
if(n&1)cout<<"odd";else cout<<"even";

Generally   :	X % (2^n)  = X & (2^n-1)

Even test
	if( n%2 == 1)		-> Fails of n is negative
	if( n&1 == 1)     	-> Works always

*/

void printNumber(int n)
{
	if(!n)return;
	printNumber(n>>1);	// remove last bit
	cout<<(n&1);           //  print last bit
}

void printNumber(int n, int len)
{
	if(!len)return;
	printNumber(n>>1, len-1);	// remove last bit
	cout<<(n&1);		       //  print last bit
}


// Let's count bits

int countNumBits1(int mask) 
{	
        // O(bits Length) OR O(log2 mask)
	int ret = 0;	//1101001 -> 110100 -> 11010 -> 1101 -> 110 -> 11 -> 1 -> 0
	while (mask) 
	{
		if(mask&1)
			ret++;
		mask >>= 1;
	}
	return ret;
}

/*

X-1 is very important!

X 	= 840 	= 011010010000
X-1     = 839 	= 011010001111		What happened? First bit 16=(2^4) is removed, and 15=2^4-1 is added.

X & (X-1) 	= 011010000000		first bit from right removed

X & ~(X-1) 	= 011010010000 
                & 100101110000 = 000000010000	value of 1<<SmaintestBitIdx
*/
int countNumBits2(int mask) 
{	
         // O(bits Count)	__builtin_popcount(n)
	int ret = 0;
	while (mask) 	
	{
		mask &= (mask-1);
		++ret;	// Simply remove the last bit and so on
	}
	return ret;
}

// len = 3: 000, 001, 010, 011, 100, 101, 110, 111
// Remember we did it recursively! This is much SIMPLER!
void printNumber(int n, int len)
{
	if(!len)return;
	printNumber(n>>1, len-1);	// remove last bit
	cout<<(n&1);		       //  print last bit
}
void printAllSubsets(int len)	
{
	for (int i = 0; i < (1<<len); ++i)
		{printNumber(i,len);cout<<' ';}
}

// For reversed order. Either reverse each item or work from big to small
void printAllSubsets(int len)	
{
	for (int i = (1<<len)-1; i >= 0 ; --i)
  	       {printNumber(i, len);cout<<' ';}
}
