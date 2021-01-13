```cpp
int n,curlen;
vector<int> suf, group, tmp;
int getGroup(int a)
{
    return (a < group.size() ? group[a] : 0);
}
void radix_sort(int k)
{
    vector<int> frq(n);
    for (int i = 0; i<n ; i++)
        frq[getGroup(suf[i] + k)]++;
    for (int i = 1; i < n; i++)
        frq[i] += frq[i - 1];
    for (int i = n - 1; i >= 0; i--)
        tmp[--frq[getGroup(suf[i] + k)]] = suf[i];
    suf = tmp;
}
bool comp(int a,int b)
{
    if (group[a] != group[b])
        return group[a] < group[b];
    return getGroup(a + curlen) < getGroup(b + curlen);
}
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
        curlen = len;
        // sort(suf.begin(),suf.end(), comp(len));
        radix_sort(len);
        radix_sort(0);
        for (int i = 1; i < n; i++)
            sorGroup[i] = sorGroup[i - 1] + comp(suf[i - 1], suf[i]);
        for (int i = 0; i < n; i++)
            group[suf[i]] = sorGroup[i];
    }
} // O(nlogn) 

// LCP[i] = longest common prefixes in suffix array (suffix[i], suffix[i-1])
vector<int> LCP(string s) 	
{	
	// suffixArray(s);	
	vector<int> rank(n), lcp(n);	// where n = s.size() + 1;
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
} // O(n)
```
