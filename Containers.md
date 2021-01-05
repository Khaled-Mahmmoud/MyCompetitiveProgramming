```cpp
    int n=6;
    bitset<32> bit;
    bit = n;
    cout<<bit<<endl;     // 000000000000000000000000000110
    for (int i = 0; i < 32; i++)
        cout<<bit[i];    // 011000000000000000000000000000
    string s = bit.to_string();
    cout<<endl<<s;       // 000000000000000000000000000110
```
