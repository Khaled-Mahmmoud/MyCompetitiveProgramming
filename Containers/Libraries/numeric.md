# numeric

### partial_sum

Assigns to every element in the range starting at result the partial sum of the corresponding elements in the range [first,last]

```cpp
    int val[] = {1,2,3,4,5};
    int result[5];
    partial_sum(val, val+5, result);
    cout<<"using default partial_sum: ";
    for(int i=0; i<5; i++) 
        cout<< result[i] << ' ';  // 1 3 6 10 15
    cout<< '\n';
```

Complexity : Linear in the distance between first and last
