

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

|Binary  | Gray Code | decimal of gray code|
|---|---|---|---|
|0|0000|0000|	0|
|1|0001	|0001|1|
|2|0010	|	0011|	2|
|3|0011	|	0010|	1|
|4|0100	|	0110|	2|
|5|0101	|	0111|	3|
|6|0110	|	0101|	2|
|7|0111	|	0100|	1|
|8|1000	|	1100|	2|


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
