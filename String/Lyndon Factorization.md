```cpp
/*
Lyndon Factorization
A string is called simple (or a Lyndon word), if it is strictly smaller than any of its own proper suffixes. 
Examples of simple strings are: a, b, ab, aab, abb, ababb, abcd. It can be shown that a string is simple,
if and only if it is strictly smaller than all its proper cyclic shifts.
Next, let there be a given string s. The Lyndon factorization of the string s is a factorization s = w1 w2 … wk,
where all strings wi are simple, and they are in non-increasing order w1 ≥ w2 ≥ ⋯ ≥ wk
Example of Lyndon factorization :: ZAA --> Z, A, A ; ZAB --> Z, AB ; CBA --> C, B, A ; ABCABCABC --> ABC, ABC, ABC
*/
vector<string> duval(string s) 
{
    int n = s.size();
    int i = 0;
    vector<string> factorization;
    while (i < n) 
    {
        int j = i + 1, k = i;
        while (j < n && s[k] <= s[j]) 
        {
            if (s[k] < s[j])
                k = i;
            else
                k++;
            j++;
        }
        while (i <= k)
        {
            factorization.push_back(s.substr(i, j - k));
            i += j - k;
        }
    }
    return factorization;
}
/*
Finding the smallest cyclic shift
Given a string S[1..n] . A rotation on S is that we move the first character to the right-most of the string.
More specific, after a rotation, S becomes T = S[2..n] + S[1].
For example: S = abcaa, then after a rotation we have S = bcaaa.
Find the minimum number of rotations to make S become the smallest lexicographical order string.
Input : A single line contains a string S. S contains only small letters of English alphabet (‘a’ .. ‘z’),
and the length of S is not more than 100000.
Output : A tow lines contains an integer which represents the minimum number of rotations.
and next line while represents the smallest cyclic shift
Input : mississippi, Output : 10
*/
void min_cyclic_string(string s)
{
    s += s;
    int n = s.size();
    int i = 0, ans = 0;
    while (i < n / 2)
    {
        ans = i;
        int j = i + 1, k = i;
        while (j < n && s[k] <= s[j]) 
        {
            if (s[k] < s[j])
                k = i;
            else
                k++;
            j++;
        }
        while (i <= k)
            i += j - k;
    }
    cout<<ans<<'\n';
    cout<<s.substr(ans, n / 2);
}
```
