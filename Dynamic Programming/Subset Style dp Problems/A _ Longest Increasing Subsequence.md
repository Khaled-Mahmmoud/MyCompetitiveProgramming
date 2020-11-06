# Longest Increasing Subsequence

The Longest Increasing Subsequence (LIS) problem is to find the length of the longest subsequence 
of a given sequence such that all elements of the subsequence are sorted in increasing order.
        
For example, the length of LIS for {10, 22, 9, 33, 21, 50, 41, 60, 80} is 6 and LIS is {10, 22, 33, 50, 60, 80}

```cpp
// a[n] = -1e9
// called with LIS(0, n)
int LIS(int i, int prev)
{
	if(i == n)
		return 0;
        int &rt = dp[i][prev];
        if(~rt)
            return rt;
	 rt = LIS(i+1, prev);	// LEAVE
	if(a[prev] <= a[i])
		rt = max(rt,LIS(i+1, i) + 1);
	return rt;
}
```      
Complexity : O(n * n)

```cpp
// called with LIS(0, -1)
int LIS(int i, int item)
{
	if(i == n)
		return 0;
        int &rt = dp[i][item];
        if(~rt)
            return rt;
	 rt = LIS(i+1, item);	// LEAVE
	if(item <= a[i])
		rt = max(rt,LIS(i+1, a[i]) + 1);
	return rt;
}
```      
Complexity : O(n * item) where item is maximum element in array

# Printing longest increasing subsequence

Complexity : O(nlogn)

using segment tree.

[problem1](https://www.spoj.com/problems/LMIS/)

[problem2](https://www.spoj.com/problems/ELIS/)
