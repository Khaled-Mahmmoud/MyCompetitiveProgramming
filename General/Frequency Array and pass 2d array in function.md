# Frequency Array

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
        freq[s[i]-'a']++;                  
    
    for (int i=0;i<26;i++)
        if (freq[i])
            cout <<"The frequency of "<< char(i+'a') << " in the given string = " <<freq[i]<<endl;
            
      // OR
      
      for (char i='a';i<='z';i++)
          if (freq[i-'a'])
            cout <<"The frequency of "<< i << " in the given string = " <<freq[i-'a']<<endl;
        
```

## How to pass a 2D array as a parameter in function?

1-) When both dimensions are available globally (either as a macro or as a global constant).

```cpp
const int M = 3; 
const int N = 3; 
void print(int arr[M][N]) 
{ 
    int i, j; 
    for (i = 0; i < M; i++) 
      for (j = 0; j < N; j++) 
        printf("%d ", arr[i][j]); 
} 
  
int main() 
{ 
    int arr[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}; 
    print(arr); 
    return 0; 
} 
```

2-) When only second dimension is available globally (either as a macro or as a global constant).

```cpp
const int N = 3; 
  
void print(int arr[][N], int m) 
{ 
    int i, j; 
    for (i = 0; i < m; i++) 
      for (j = 0; j < N; j++) 
        printf("%d ", arr[i][j]); 
} 
  
int main() 
{ 
    int arr[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}; 
    print(arr, 3); 
    return 0; 
} 
```

3-) Using a single pointer

```cpp
void print(int *arr, int m, int n) 
{ 
    int i, j; 
    for (i = 0; i < m; i++) 
      for (j = 0; j < n; j++) 
        printf("%d ", *((arr+i*n) + j)); 
} 
  
int main() 
{ 
    int arr[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}; 
    int m = 3, n = 3; 
    print((int *)arr, m, n); 
    return 0; 
} 
```
