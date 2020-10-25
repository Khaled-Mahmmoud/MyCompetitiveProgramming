### advance 

Advances the iterator it by n element positions
```cpp
  list<int> mylist;
  for (int i=1; i<10; i++) mylist.push_back (i*10); // 10 20 30 40 50 60 70 80 90
  list<int>::iterator it = mylist.begin();
  advance (it,5);
  cout << *it << '\n';   // 60
```
Complexity : Constant for random-access iterators . Otherwise, linear in n

### distance 

Calculates the number of elements between first and last
```cpp
  vector<int> mylist;
  for (int i=1; i<10; i++) mylist.push_back (i*10); // 10 20 30 40 50 60 70 80 90
  auto first = mylist.begin();
  auto last = mylist.end();
  cout << distance(first,last) << '\n';   // 8
  cout<< last - first <<'\n'; // 8
```
Complexity : Constant for random-access iterators . Otherwise, linear in n

