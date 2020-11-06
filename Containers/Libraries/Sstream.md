# Sstream

### stringstream


```cpp
string k = "khaled mahmoud fawzy",s1,s2,s3;
stringstream input(k);
input>>s1>>s2>>s3;
cout<<s1<<':'<<s2<<':'<<s3;  // khaled:mahmoud:fawzy
```


```cpp
string k = "23 87 69";int s1,s2,s3;
stringstream input(k);
input>>s1>>s2>>s3;
cout<<s1<<':'<<s2<<':'<<s3;  // 23:87:69
```
