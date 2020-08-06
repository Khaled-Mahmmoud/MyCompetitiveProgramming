# Last Substring in Lexicographical Order

Given a string s, return the last substring of s in lexicographical order.

Input: "abab"

Output: "bab"

Explanation: The substrings are ["a", "ab", "aba", "abab", "b", "ba", "bab"]. The lexicographically maximum substring is "bab".

Input: "leetcode"

Output: "tcode"

1 <= s.length <= 4 * 10^5

s contains only lowercase English letters.

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
	for (auto& it : suf) frq[getGroup(it + k)]++;
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
	bool operator ()(const int& a, const int& b) const
	{
		if (group[a] != group[b])
			return group[a] < group[b];
		return getGroup(a + len) < getGroup(b + len);
	}
};
class Solution {
public:
    string lastSubstring(string s) 
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
	for (int len = 1; sorGroup[n-1] != n - 1; len <<= 1)
	{
	    radix_sort(len);
		  radix_sort(0);
		for (int i = 1; i < n; i++)
			sorGroup[i] = sorGroup[i - 1] + comp(len)(suf[i - 1], suf[i]);
		for (int i = 0; i < n; i++)
			group[suf[i]] = sorGroup[i];
	}
        string ans;
        for(int i=suf[n-1];i<n-1;i++)
            ans+=s[i];
        
        suf.clear();
        tmp.clear();
        group.clear();
        return ans;
    }
};
```
