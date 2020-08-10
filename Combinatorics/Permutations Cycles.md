# Permutations Cycles

```
For vector {0, 1, 2} -> we have 3! = 6

Idx: 0		0 1 2		-> Sorted	     	{			Block of length 2! = 2
Idx: 1		0 2 1					    	}

Idx: 2		1 0 2
Idx: 3		1 2 0

Idx: 4		2 0 1
Idx: 5		2 1 0		-> Reversed

For vector {0, 1, 2, 3} -> we have 4! = 24

Idx: 0		0 1 2 3 					{
Idx: 1		0 1 3 2 					.
Idx: 2		0 2 1 3 					.			Block Start with Zeros. Its Length 3! = 6
Idx: 3		0 2 3 1 					.
Idx: 4		0 3 1 2 					.
Idx: 5		0 3 2 1 					}

Idx: 6		1 0 2 3
Idx: 7		1 0 3 2
Idx: 8		1 2 0 3
Idx: 9		1 2 3 0
Idx: 10		1 3 0 2
Idx: 11		1 3 2 0

Idx: 12		2 0 1 3
Idx: 13		2 0 3 1
Idx: 14		2 1 0 3
Idx: 15		2 1 3 0
Idx: 16		2 3 0 1
Idx: 17		2 3 1 0

Idx: 18		3 0 1 2
Idx: 19		3 0 2 1
Idx: 20		3 1 0 2
Idx: 21		3 1 2 0
Idx: 22		3 2 0 1
Idx: 23		3 2 1 0
```
How to iteratively generat Permutations ?

```cpp
void Permutation(int a[],int n)
{
    do
    {
        for(int i=0;i<n;i++)
            cout<<a[i]<<' ';
        cout<<'\n';
    }
    while(next_permutation(a,a+n));
}
int main() 
{ 
    int a[] = {0, 1, 2}; 
    int n = sizeof(a)/sizeof(a[0]); 
    Permutation(a, n); 
    return 0; 
} 
```
Complexity : O(!n)

number of purmutaions = !n / !(n-r) where r = n , it's !n / !0 = !n
