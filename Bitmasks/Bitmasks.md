
**32-bit Integers**

4 Bytes ( 1 Byte = 8 bits )

bit 31 for sign 

we can use first 31 bits (bit 0 to bit 30) to avoid issues with 2's complement 

31 xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 0

**64-bit Integers**

8 Bytes

bit 63 for sign 

we can use first 63 bits (bit 0 to bit 62) to avoid issues with 2's complement 

63 xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 0


bitmask is any integer

set : bit with value 1

clear : bit with value 0

### basic bitwise operations

**AND operator (&)**

Ex. a=5 , b=4, int c = a & b; // 101 & 100 = 100

**OR operator (|)**

Ex. a=5 , b=4, int c= a | b; // 101 & 100 = 101
 
**XOR operator (^)**

Ex. a=5 , b=4

int c= a ^ b; // 101 & 100 = 001

**NOT operator (~)**

flip each bit

int a=10 ; // 1010

int b=~a=~(1010)=0101

**Shift Left**

operator : <<

Form : x << y

Shift number x in binary times y to the left

Ex. int x=10; // 1010

int y=x<<2; // 101000

**Shift Right**

operator : >>

Form : x >> y

Shift number x in binary times y to the right

Ex. int x=10; // 1010

int y=x>>2; // 0010

**get bit**

check if bit i is set in the bitmask m. 
find the result of m & 1 shift left i times
if the result is zero then the bit is clear otherwise the bit is set

Ex. int m = 5; // 101

check set bit 2 
int r = m & (1<<2) // 101 & 100 = 100 so is set

**set bit**

how to set bit with index i in a bitmask m ?

we can shit 1 to the left times i and OR it with m

m = m | (1<<i)

Ex. int m = 11 // 1011

set bit 2

m = m | (1<<2) = 1011 | 100 = 1111

**clear bit**

how to clear bit with index i in a bitmask m ?

we can shit 1 to the left times i and not it and AND it with m

m = m & ~(1<<i)

EX. int m = 11 // 1011

clear bit 3

m = m & ~(1<<3) = 1011 & 0111 =0011

**flip bit**

how to flip bit with index i in a bitmask m ?

we can shit 1 to the left times i and XOR it with m

 m ^ (1<<i);
 
EX. int m = 11  // 1011

flib bit 2

m = m ^ (1<<2) = 1011 ^ 100 = 1111

flib bit 1

m = m ^ (1<<1) = 1011 ^ 10 = 1001

# Bit Manipulation

**Why using Bit Manipulation?**

1) better time order
2) better memory order
3) make code shorter

A ^ B ^ C ^ D = E , if E has any 1s bit , it must have odd number of 1s

X ^ 0 = X	          

X ^ X = 0

(A ^ B ^ C ^ D ^ E) ^ (A ^ B ^ C) = D ^ E

X << 1		Equals X*2 

X << 2		Equals X*4 

X >> 1		Equals X/2 

X >> 2		Equals X/4 

1 << X  Equals 2^X 
         
X = 26 = 11010 

2^4 * 1 + 2^3 * 1 + 2^2 * 0 + 2^1 * 1 + 2^0 * 0

16 +  8  +  0  +  2  +  0   = 26
     
X = 11010 = 26	, Last Bit shows Parity : Even / Odd

X = 11011 = 27

X % 2 = X & 1 = bit 0

Generally   :	X % (2^n)  = X & (2^n-1)

if( n%2 == 1)		-> Fails of n is negative

if( n&1 == 1)     	-> Works always

```cpp
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
```


X-1 is very important!

X 	= 840 	= 011010010000

X-1     = 839 	= 011010001111		What happened? First bit 16=(2^4) is removed, and 15=2^4-1 is added

X & (X-1) 	= 011010000000		first bit from right removed

X & ~(X-1) 	= 011010010000 
                & 100101110000 = 000000010000	value of 1<<SmaintestBitIdx

```cpp
// to count number of sets in mask
int countNumBits2(int mask) 
{	
         // O(bits Count)	
         // __builtin_popcount(n)
	 int ret = 0;
	 while (mask) 	
	 {
	 	mask &= (mask-1);
	 	++ret;	// Simply remove the last bit and so on
	 }
	 return ret;
}
```

// to get [least significant bit](https://github.com/Khaled-Mahmmoud/MyCompetitiveProgramming/blob/master/img/Bitmask/most%20significant%20bit.jpg) that is set
```cpp
template<class Int>	
Int leastBit(Int num) { return (num & ~(num-1)); }	
```
len = 3: 000, 001, 010, 011, 100, 101, 110, 111

Remember we did it recursively! This is much SIMPLER!

```cpp
void printNumber(int n, int len)
{
	if(!len)return;
	printNumber(n>>1, len-1);	// remove last bit
	cout<<(n&1);		       //  print last bit
}
void printAllSubsets(int len)	
{
	for (int i = 0; i < (1<<len); ++i)
		{
     printNumber(i,len);
     cout<<' ';
  }
}
````

For reversed order. Either reverse each item or work from big to small

```cpp
void printAllSubsets(int len)	
{
	 for (int i = (1<<len)-1; i >= 0 ; --i)
  {
      printNumber(i, len);
      cout<<' ';
  }
}
```
Be careful with operators precedence problems

X & 7 == 1 		is interpreted as 	X & (7 == 1)	        --> (X & 7) == 1

1<<10 - 1 		is interpreted as	= 1<<9			--> (1<<10) - 1

1 << 60 Fails , 1 is 32 bitInteger (overflow)          	  	--> 1LL << 60



Gray Code:  is a binary numeral system where two successive values differ in only one bit

Build it incrementally, Let's see for len = 1

0

1

(valid)

For length 2, we know we need to add prefix 0 and 1 so doubling list

00

01

10

11

(valid)


For length 3, we know we need to add prefix 0 and 1 so doubling list

000

001

010

011

100

101

110

111

(valid)

For length 4, we know we need to add prefix 0 and 1 so doubling list

0000

0001		

0010		

0011		

0100		

0101		

0110		

0111		

1000		

1001		

1010		

1011		

1100		

1101		

1110		

1111

(not valid)

So all what we need. To generate N. use 0N + 1N' where N' is reverse list

0000

0001	

0010	

0011	

0100	

0101	

0110	

0111

1111

1110

1101

1100

1011

1010

1001

1000

(valid)

If we built the list incrementally including from N=2 we got

Binary        Gray Code decimal

0000		0000	0

0001		0001	1

0010		0011	2

0011		0010	3

0100		0110	4

0101		0111	5

0110		0101	6




By observation, in gray code, every bit is Xor of its bit and last one

```cpp 
int grayCode(int i) 
{
	return i ^ (i>>1);
}

void printAllSubsetsGray(int len)
{
	for (int i = 0; i < (1<<len)-1; ++i)
	{
		printNumber(i, len );
		cout<<"\t\t";

		printNumber( grayCode(i), len );

		cout<<"\t"<<__builtin_popcount(grayCode(i));
		cout<<"\n";
	}
}
```
