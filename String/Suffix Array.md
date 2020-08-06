# Suffix Array

**Prefix and Suffix of a string**

let the string is abbab

| Prefixes | Suffixes|
|---|---|
|#|abbab|
|a|bbab|
|ab|bab|
|abb|ab|
|abba|b|
|abbab|#|

For our purpose, we will consider # is empty string

So, for length n = 5, we generate 6 suffixes

Remember: 6 suffixes of different lengths

Let S = abracadabra (length = 11)

**Generate suffixes and sort**

1) Generate 12 suffixes
2) Sort based on string (alphabetically)
3) The new indices ordering is called **suffix array**

|Suffixes|Suffix Array|
|---|---|
| (0) abracadabra | (11) #|
| (1) bracadabra  | (10) a|
| (2) racadabra | (7) abra|
| (3) acadabra | (0) abracadabra|
| (4) cadabra | (3) acadabra|
| (5) adabra  | (5) adabra|
| (6) dabra  | (8) bra |
| (7) abra | (1) bracadabra  |
| (8) bra | (4) cadabra |
| (9) ra  | (6) dabra  |
| (10) a  | (9) ra  | 
| (11) #  | (2) racadabra |

int suffix_array[] = {11,10, 7, 0, 3, 5, 8, 1, 4, 6, 9, 2}


A **suffix array** is a sorted array of all suffixes
of a string. Given that it considers every position in the
string, it can be used in several string
processing tasks such as queries on all
available substrings or pattern search

**Brute Force Approach**

1) Generate the suffixes
2) Sort them
3) nlogn for sorting algorithm
4) comparing 2 strings is O(n)
5) total O(n^2 logn) = So slow

**Code**

1) Generate N+1 suffixes put in vector
2) Create map from suffix to its original index
3) Sort the vector
4) Now we can use map to know idx of i'th sorted suffix

### O(n^2 logn)

```cpp
void buildSuffixArray(string str) 
{
  map<string, int> suffix_array;
  vector<string> suffixes;

  for (int i = 0; i <= str.size(); i++)
  {
    string suffix = str.substr(i, str.size() - i);
    suffix_array[suffix] = i;
    suffixes.push_back(suffix);
  }
  sort(suffixes.begin(), suffixes.end());
  for (int i = 0; i <= suffixes.size(); i++)
    cout << suffixes[i] << "\t" << suffix_array[suffixes[i]] << "\n";
}
```

### Faster approaches

**Main observation**

They are suffixes of ONE string, not random strings. How to use this fact to build efficient solutions?

**O(N(logn)^2) solution**

**O(Nlogn) solution improvement**

Algorithms based on Suffix tree

O(N) algorithms (e.g. [SA-IS algorithm](https://sites.google.com/site/indy256/algo_cpp/suffix_array_lcp))

**Incremental Sortings**

Assume suffixes are sorted based on the first 2 letters

◼ Can we sort it efficiently based on 4 letters?

◼ Then, sort it based on 8 letters?

◼ Then sort it based on 16 letters?

◼ And so on?

◼ This O(logn) steps * ordering first **h letters**

**Sorted suffixes on first 2 letters**

|suffix(2)|index|group|
|:---|:---:|---:|
| # | 11 | 0 |
| a | 10 | 1 |
| abracadabra | 0 | 2| 
|abra|7|2|
|acadabra|3|3|
|adabra|5|4|
|bracadabra|1|5|
|bra|8|5|
|cadabra|4|6|
|dabra|6|7|
|racadabra|2|8|
|ra|9|8|

A **group** is a new array that group equal
same prefixes. E.g. index 0 and 7 starts with ab. So both assigned same group = 2

This can be trivially computed. Your group = previous group + 1 if
different prefixes at first h=2 letters. E.g. group(acadabra) = group(abra) + (ac!= ab) = 2 + 1 = 3

**Sorting 4 letters from 2 letters**

**Compare(abra, bra)**

g(abra) = 2, group(bra) = 5. Actually on 2 letters, they are different. So in new ordering abra < bra (4 letters)

**Compare(bracadabra, bra)**

g(bracadabra) = 5, group(bra) = 5. Same group (= first 2 letters)

We need to compare next 2 letters. How to do that fast?
Remember next 2 letters are suffixes

bracadabra

We need to ignore first 2 letters. acadabra, find its group. group(acadabra) = 3

bra

We need to ignore first 2 letters. a, find its group. group(a) = 1

Then Compare(bracadabra, bra), bra < bracadabra 

How to get the acadabra efficiently?

index(bracadabra) = 1

index( racadabra) = 2

index( acadabra) = 3 (1 + h = 2)

index( cadabra) = 4 .. and so on

Then group[idx + h] is h shift from group[idx]

|suffix(2)|index|group|..........|suffix(4)|index|group|..........|suffix(8)|index|group|
|:---|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|---:|
| # | 11 | 0 |..........| # | 11 | 0 |..........| # | 11 | 0 |
| a | 10 | 1 |..........|a|10|1|..........|a|10|1|
| abracadabra | 0 | 2|..........|abracadabra|0|2|..........|abra|7|2|
|abra|7|2|..........|abra|7|2|..........|abracadabra|0|3|
|acadabra|3|3|..........|acadabra|3|3|..........|acadabra|3|4|
|adabra|5|4|..........|adabra|5|4|..........|adabra|5|5|
|bracadabra|1|5|..........|bra|8|5|..........|bra|8|6|
|bra|8|5|..........|bracadabra|1|6|..........|bracadabra|1|7|
|cadabra|4|6|..........|cadabra|4|7|..........|cadabra|4|8|
|dabra|6|7|..........|dabra|6|8|..........|dabra|6|9|
|racadabra|2|8|..........|ra|9|9|..........|ra|9|10|
|ra|9|8|..........|racadabra|2|10|..........|racadabra|2|11|

Observe: Sorted suffix and its group never go upper. Either same position or lower.

Observe: At h = 8, every suffix has a different group. We can stop processing.


**Initialization**

◼ At 1st iteration (h = 1), we need to sort on first letter

◼ Then we should depend on ascii letter

◼ Create length+1 suffixes

◼ Assign group of suffix = ascii of first letter

◼ Sort in O(nlogn)

◼ Process for h = {1, 2, 4, 8, 16…}

◼ Sort 2h letters based on h letters => O(nlogn)

◼ Comparing now is 2 checkings on the group index only

◼ Order: O(logn) * O(nlogn)

### O(n log^2 n)

```cpp
#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> suf, group, tmp;
int getGroup(int a)
{
	return (a < group.size() ? group[a] : 0);
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
		sort(suf.begin(),suf.end(), comp(len));
		for (int i = 1; i < n; i++)
			sorGroup[i] = sorGroup[i - 1] + comp(len)(suf[i - 1], suf[i]);
		for (int i = 0; i < n; i++)
			group[suf[i]] = sorGroup[i];
	}
}
int main()
{
    string str = "abracadabra";
    suffixArray(str);
    for(int i=0;i<n;i++){
        for(int j=suf[i];j<n-1;j++)
        cout<<str[j];cout<<endl;}
    return 0;
}

```

### O(nlogn) 

```cpp
#include <bits/stdc++.h>
using namespace std;
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
int main()
{
    string str = "abracadabra";
    suffixArray(str);
    for(int i=0;i<n;i++){
        for(int j=suf[i];j<n-1;j++)
        cout<<str[j];cout<<endl;}
    return 0;
}
```
### Example
Given a string s, return the last substring of s in lexicographical order.

Input: "abab"

Output: "bab"

Explanation: The substrings are ["a", "ab", "aba", "abab", "b", "ba", "bab"]. The lexicographically maximum substring is "bab".

1 <= s.length <= 4 * 10^5

### Longest Common Prefixes 

LCP[i] = longest common prefixes in suffix array (suffix[i], suffix[i-1])

[Better Solution](https://github.com/Khaled-Mahmmoud/MyCompetitiveProgramming/blob/master/img/String/String_Processing_Suffix_Array_3_LCP-converted.pdf) : Time Complexity : O(n)


```cpp
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
}
```
