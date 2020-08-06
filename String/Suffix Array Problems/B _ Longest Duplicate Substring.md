# Longest Duplicate Substring

Given a string S, consider all duplicated substrings: (contiguous) substrings of S that occur 2 or more times.  (The occurrences may overlap.)

Return any duplicated substring that has the longest possible length.  (If S does not have a duplicated substring, the answer is "".)


Input: "banana"

Output: "ana"

Input: "abcd"

Output: ""
 

2 <= S.length <= 10^5

S consists of lowercase English letters.

```cpp
vector<int> LCP(string s)
{
	//suffixArray(s);
	vector<int> rank(n), lcp(n);
	for (int i = 0; i < n; i++)
		rank[suf[i]] = i;
	int c = 0;
	for (int i = 0; i < n; i++)
	{
		if (rank[i])
		{
			int j = suf[rank[i] - 1];
			while (s[i + c] == s[j + c])c++;
		}
		lcp[rank[i]] = c;
		if(c)c--;
	}
	return lcp;
}
class Solution
{
public:
    string longestDupSubstring(string s)
    {
        suffixArray(s);
        vector<int>lcp = LCP(s);

        int max = 0, idx = 0;

        for(int i=0; i<n; i++)
            if(lcp[i]>max)
            {
                max = lcp[i];
                idx = suf[i];
            }
        string ans;

        for(int i=idx; i<idx+max; i++)
            ans+=s[i];

        suf.clear();
        group.clear();
        tmp.clear();

        return ans;
    }
};
```
