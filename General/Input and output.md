# Input and output

1) Input and output is sometimes a bottleneck in the program.
The following lines at the beginning of the code make input and output more efficient
```cpp
ios_base::sync_with_stdio(0);
cin.tie(0);cout.tie(0)
```

2) Note that the newline "\n" works faster than endl, because endl always causes a flush operation

3) Sometimes the program should read a whole line from the input, possibly
containing spaces . This can be accomplished by using the getline function:
```cpp
string s;
while(s.size()==0)
getline(cin, s);
```

4) If the amount of data is unknown, the following loop is useful:
```cpp
while (cin >> x) 
{
    // code
}
```

5) In some contest systems, files are used for input and output. An easy solution
for this is to write the code as usual using standard streams, but add the following
lines to the beginning of the code:
```cpp
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
```
After this, the program reads the input from the file ”input.txt” and writes the
output to the file ”output.txt”
