## Permutations Cycles

```
For vector {0, 1, 2} -> we have 3! = 6

Idx: 0		0 1 2		-> Sorted	     	{			Block of length 2! = 2 
Idx: 1		0 2 1					}                                      (n-1)!
      
Idx: 2		1 0 2
Idx: 3		1 2 0

Idx: 4		2 0 1
Idx: 5		2 1 0		-> Reversed
```
#### How to iteratively generate Permutations ?
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
    // while(prev_permutation(a,a+n);
}
int main() 
{ 
    int a[] = {0, 1, 2}; 
    int n = sizeof(a)/sizeof(a[0]); 
    Permutation(a, n); 
    return 0; 
} 
```
Complexity : O(n * !n)

#### The next permutation of s after x steps ?
```cpp
void permutation(string str,int x)
{
    for(int i=0;i<x;i++)
        next_permutation(str.begin(),str.end());
    //  prev_permutation(str.begin(),str.end());
    cout<<str;
}
```
Complexity : O(n * x)

**Permutations**

[Problem Link](https://codeforces.com/contest/124/problem/B)
[Solution Link](https://codeforces.com/contest/124/submission/99911452)

#### Given a permutation length, what is the ith permutation ?
```cpp
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
```

#### Given a permutation, what is its index ?
```cpp
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
