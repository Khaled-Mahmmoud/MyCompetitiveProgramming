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

### Brute Force Approach

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

Assume suffixes are sorted based on the first 2
letters
◼ Can we sort it efficiently based on 4 letters?
◼ Then, sort it based on 8 letters?
◼ Then sort it based on 16 letters?
◼ And so on?
◼ This O(logn) steps * ordering first h letters
