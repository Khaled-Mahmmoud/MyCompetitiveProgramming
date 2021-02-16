```cpp
/*
For vector {0, 1, 2} -> we have 3! = 6

Idx: 0		0 1 2		-> Sorted	     	{			Block of length 2! = 2 
Idx: 1		0 2 1					}                                      (n-1)!
      
Idx: 2		1 0 2
Idx: 3		1 2 0

Idx: 4		2 0 1
Idx: 5		2 1 0		-> Reversed
*/
// Given a permutation length, what is the ith permutation ?
vector<int> nthPerm(int len, int nth) 
{
    vector<int> id(len), perm(len);
    for(int i=0;i<len;i++)
    id[i] = i;
    for (int i = len - 1; i >= 0; --i)
    {
        int p = nth / Fact[i];
	perm[len - i - 1] = id[p];
	id.erase(id.begin() + p);
	nth %= Fact[i];
    }
    return perm;
}
// Given a permutation, what is its index ?
int PermToIndex(vector<int> perm)
{
    int idx = 0;
    int n = perm.size();
    for (int i = 0; i < n; ++i)
    {
        // Remove first, and Renumber the remaining elements to remove gaps
        idx += Fact[n-1-i] * perm[i];
        for(int j = i+1; j < n; j++)
           perm[j] -= perm[j] > perm[i];
    }
    return idx;
}
```
