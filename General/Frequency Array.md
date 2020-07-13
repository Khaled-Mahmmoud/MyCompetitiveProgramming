Frequency Array is an array that used to find the frequency of some elements in a range of elements.

```cpp

   for(int i = 0 ; i < 10 ; ++i)
        frequency[a[i]]++;
    
    for(int i = 0 ; i <= MAX_INTEGER ; ++i)
        if(frequency[i])
            cout << "Number " << i << " frequency is " << frequency[i] << endl;
```

In case we want to make a frequency array code for lowercase and uppercase characters and numbers in strings:

Each character has an ASCII code (ex: ‘a’=97,’A’=65,’0’=48).

So for the frequency array, we create an array with the size of Alphabets or numbers (from 0 to 9)

How can we get the index zero for the letter ‘a’, index one for ‘b’ …. Index 25 for ‘z’?

The answer is just subtracting ‘a’(the ASCII value) from each character we want to get its frequency.

‘a’-‘a’=0 --> 97-97=0

‘b’-‘a’=1 --> 98-97=1

‘z’-‘a’=25 --> 122-97=25

And for uppercase characters, we subtract ‘A’. And for numbers (as characters), we subtract ‘0’
```cpp

    string s ; cin >> s;
    for (int i = 0 ; i < s.size() ; i++)
        freq[s[i]-'a']++;                   //freq[x]=freq[x]+1
    
    for (int i=0;i<25;i++)
        if (freq[i])
            cout <<"The frequency of "<< char(i+'a') << " in the given string = " <<freq[i]<<endl;
    
        
```
