#### Sorting

```cpp
// a vector as can be sorted as follows:
sort(v.begin(),v.end());   // O(nlogn)

// a reverse order is possible as follows:
sort(v.rbegin(),v.rend());
sort(v.begin(),v.end(),greater<int>())


// An ordinary array a can be sorted as follows:
sort(a,a+n);  

// a reverse order is possible as follows:
sort(a,a+n,greater<int>());

// but if there 
long long a[n];
// we can sort it by:
sort(a,a+n,greater<long long>());


//The following code sorts the string s:
string s = "monkey";
sort(str.begin(), str.end());

// a reverse order is possible as follows:
sort(str.rbegin(),str.rend());          OR 
sort(str.begin(),str.end(),greater<char>())
```
Pairs (pair) are sorted primarily according to their first elements (first).
However, if the first elements of two pairs are equal, they are sorted according to
their second elements (second)
```cpp
vector<pair<int,int>> v;
v.push_back({1,5});
v.push_back({2,3});
v.push_back({1,2});
sort(v.begin(), v.end());
```
After this, the order of the pairs is (1,2), (1,5) and (2,3).

In a similar way, tuples (tuple) are sorted primarily by the first element, secondarily by the second element, etc.
```cpp
vector<tuple<int,int,int>> v;
v.push_back(make_tuple(2,1,4));
v.push_back(make_tuple(1,5,3));
v.push_back(make_tuple(2,1,3));
sort(v.begin(), v.end());
After this, the order of the tuples is (1,5,3), (2,1,3) and (2,1,4)
```
**Comparison functions**

It is also possible to give an external comparison function to the sort function
as a callback function. For example, the following comparison function sorts
strings primarily by length and secondarily by alphabetical order
```cpp
bool pred(string a, string b)
{
    if (a.size() != b.size())
        return a.size() < b.size();
    return a < b;
}
sort(v.begin(), v.end(), pred);
```
#### How to sort a pair increasing based on first element then decreasing based on second element?
```
1 100
1 99
2 101
2 100
3 400
```
```cpp
bool pred(pair<int, int> a, pair<int, int> b)
{
    if (a.first != b.first)
    {
        return a.first < b.first;
    }
    return a.second > b.second;
}
vector<pair<int,int>>v;
sort(v.begin(), v.end(), pred);
```
