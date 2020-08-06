Given string str and set of patterns, check wether pattern exist or nor

for buildSuffixArray --> O(n logn)

for queries -->  O(m logn)

```cpp
void find_patterns_queries() 
{
  cin >> str;
  buildSuffixArray(str);

  start_again:
  while (cin >> pat) 
  {  
    int m = strlen(pat); 

    int l = 0, r = n - 1;
    while (l <= r) 
    {
      int mid = l + (r - l) / 2;
      int res = strncmp(pat, str + suf[mid], m);

      if (res == 0) {
        cout << "Pattern found"<<'\n';
        goto start_again;
      }
      if (res < 0)
        r = mid - 1;
      else
        l = mid + 1;
    }
    cout << "Pattern not found\n";
  }
  exit(0);
}
```
