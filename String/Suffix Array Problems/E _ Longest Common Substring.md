# Longest Common Substring

Given two strings X and Y. The task is to find the length of the longest common substring.

Input:
First line of the input contains number of test cases T. Each test case consist of three lines, first of which contains 2 space separated integers N and M denoting the size of string X and Y strings respectively. The next two lines contains the string X and Y.

Output:
For each test case print the length of longest  common substring of the two strings .

Constraints:

1 <= T <= 200

1 <= N, M <= 100

Input:

2

6 6

ABCDGH

ACDGHR

3 2

ABC

AC

Output:

4

1

Testcase 1: CDGH is the longest substring present in both of the strings.


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
		// sort(suf.begin(),suf.end(), comp(len));
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
int main()
{
    int t;cin>>t;while(t--)
    {
        int n1,m;
        cin>>n1>>m;
        string s1,s2,str;
        cin>>s1>>s2;
        str = s1 + "#" + s2;
        suffixArray(str);
       vector<int>lcp = LCP(str);

        int mx = 0;
        for(int i=0;i<n;i++)
        if(mx<lcp[i]&&((suf[i]<n1&&suf[i-1]>n1)||(suf[i]>n1&&suf[i-1]<n1)))
        mx = lcp[i];

        cout<<mx<<'\n';

        suf.clear();
        group.clear();
        tmp.clear();
    }
    return 0;
}

```
