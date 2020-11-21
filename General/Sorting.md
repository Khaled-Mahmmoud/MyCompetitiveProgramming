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

Sorting a string means that the characters of the string are sorted. For example, the string ”monkey” becomes ”ekmnoy”

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

### How to sort a pair increasing based on first element then decreasing based on second element?
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

## Counting Sort

Counting sort is a sorting technique based on keys between a specific range. It works by counting the number of objects having distinct key values.
Then doing some arithmetic to calculate the position of each object in the output sequence.

For simplicity, consider the data in the range 0 to 9. 

Input data: 1, 4, 1, 2, 7, 5, 2.

  1) Take a count array to store the count of each unique object.
  
  Index:     0  1  2  3  4  5  6  7  8  9
  
  Count:     0  2  2  0   1  1  0  1  0  0

  2) Modify the count array such that each element at each index 
  stores the sum of previous counts. 
  
  Index:     0  1  2  3  4  5  6  7  8  9
  
  Count:     0  2  4  4  5  6  6  7  7  7

  The modified count array indicates the position of each object in the output sequence.
 
  3) Output each object from the input sequence followed by 
  decreasing its count by 1.
  Process the input data: 1, 4, 1, 2, 7, 5, 2. Position of 1 is 2.
  Put data 1 at index 2 in output. Decrease count by 1 to place 
  next data 1 at an index 1 smaller than this index.
  
```cpp
void countSort(vector<int>& arr) 
{ 
    int max = *max_element(arr.begin(), arr.end()); 
    int min = *min_element(arr.begin(), arr.end()); 
    int range = max - min + 1; 
      
    vector<int> count(range), output(arr.size()); 
    for(int i = 0; i < arr.size(); i++) 
        count[arr[i]-min]++; 
          
    for(int i = 1; i < count.size(); i++) 
           count[i] += count[i-1]; 
    
    for(int i = arr.size()-1; i >= 0; i--) 
         output[--count[arr[i]-min]] = arr[i];  
      
    for(int i=0; i < arr.size(); i++) 
            arr[i] = output[i]; 
} 
int main() 
{ 
    vector<int> arr = {-5, -10, 0, -3, 8, 5, -1, 10}; 
    countSort (arr); 
    for (int i=0; i < arr.size(); i++)  
        cout << arr[i] << " "; 
    return 0; 
} 
```
Time Complexity : O(n)
