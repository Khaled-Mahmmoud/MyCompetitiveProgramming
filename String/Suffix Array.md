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
same length prefixes. E.g. index 0 and 7 starts with ab. So both assigned same group = 2

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


```cpp
const int MAXLENGTH = 5000;

char str[MAXLENGTH + 1];      //the string we are building its suffix array
int suf[MAXLENGTH + 1];//the sorted array of suffix indices
int group[MAXLENGTH + 1];//In ith iteration: what is the group of the suffix index
int sorGroup[MAXLENGTH + 1];//temp array to build grouping of ith iteration

struct comp//compare to suffixes on the first 2h chars
{
  int h;
  comp(int h): h(h) {}

  bool operator()(int i, int j) 
  {
    if (group[i] != group[j])     // previous h-groups are different
    return group[i] < group[j];
    return group[i + h] < group[j + h];
  }
};

void print_suffix(int suf_pos, int n)
{
  for (int j = suf_pos; j < n - 1; ++j)  // n-1 is string length NOT n
    cout << str[j];
}

void buildSuffixArray() 
{
  int n;  //number of suffixes = 1+strlen(str)
  //Initially assume that the group index is the ASCII
  for (n = 0; n - 1 < 0 || str[n - 1]; n++)
  suf[n] = n, group[n] = str[n];//code of the first char in the suffix

  sort(suf, suf + n, comp(0));//sort the array the suf on the first char only
  sorGroup[0] = sorGroup[n - 1] = 0;

  //loop until the number of groups=number of suffixes
  for (int h = 1; sorGroup[n - 1] != n - 1; h <<= 1)
  {
    sort(suf, suf + n, comp(h));  //sort the array using the first 2h chars

    for (int i = 1; i < n; i++)//compute the 2h group data given h group data
    sorGroup[i] = sorGroup[i - 1] + comp(h)(suf[i - 1], suf[i]);

    for (int i = 0; i < n; i++)//copy the computed groups to the group array
    group[suf[i]] = sorGroup[i];


    if (true)
    {  
      for (int i = 0; i < n; i++) 
      {
        print_suffix(suf[i], n);
        cout << "\t" << suf[i] << "\n";
      }
      cout << "\n";
    }
  }
}
```
