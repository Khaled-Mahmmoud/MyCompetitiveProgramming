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

int n;
vector<int> suf, group, tmp;
int getGroup(int a)
{
	return (a < group.size() ? group[a] : 0);
}
void radix_sort(int k)
{
	vector<int> frq(n);
	for (auto it : suf) frq[getGroup(it + k)]++;
	for (int i = 1; i < n; i++)
		frq[i] += frq[i - 1];
	for (int i = n - 1; i >= 0; i--)
		tmp[--frq[getGroup(suf[i] + k)]] = suf[i];
	suf = tmp;
}
struct comp
{
	int len;
	comp(int len) :len(len) {}
	bool operator ()(int a,int b)
	{
		if (group[a] != group[b])
			return group[a] < group[b];
		return getGroup(a + len) < getGroup(b + len);
	}
};
void suffixArray(string s)
{
	n = s.size() + 1;
	vector<int> sorGroup(n);
	for (int i = 0; i < n; i++)
	{
		suf.push_back(i);
		tmp.push_back(s[i]);
	}
	sort(tmp.begin(),tmp.end());
	for (int i = 0; i < n; i++)
		group.push_back(lower_bound(tmp.begin(),tmp.end(), s[i]) - tmp.begin());
	for (int len = 1; sorGroup.back() != n - 1; len <<= 1)
	{
		radix_sort(len);
		radix_sort(0);
		for (int i = 1; i < n; i++)
			sorGroup[i] = sorGroup[i - 1] + comp(len)(suf[i - 1], suf[i]);
		for (int i = 0; i < n; i++)
			group[suf[i]] = sorGroup[i];
	}
}
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
