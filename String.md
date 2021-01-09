```cpp
/*
Failure Function (Prefix Function) expresses longest proper prefix that is a suffix (LPS Table)
Given String P of length m, define an array F(m).
F[i] = length of longest proper prefix of P that is suffix of P.
for example : akaka. then f[] = {0,0,1,2,3}
for example : aaaaa. then f[] = {0,1,2,3,4}
*/
vector<int>getprefix(string pat)
{
    int m=pat.size();
    vector<int>prefix(m);
    for(int i=1,len=0;i<m;i++)
    {
        while(len>0&&pat[i]!=pat[len])
            len=prefix[len-1];
        if(pat[i]==pat[len])
            ++len;
        prefix[i] = len;  // OR prefix[i] = 0;
    }
    return prefix;
}
int main()
{
    string pat;cin>>pat;
    vector<int>prefix=getprefix(pat);
    for(int i=0;i<prefix.size();i++)
        cout<<prefix[i]<<' ';
    return 0;
}
// Time Complexity O(m)
/*
Given a string what is the longest prefix that is palindrome ? Ex. effedcba ==>> effe
input + '#' + reverse_input ==>> effedcba#abcdeffe
Now problem , find longest prefix that is suffix.

Given a string , what is minimum characters to add to convert string to palindrome ? abcdeffe ==>> abdcdeffedcba.
let's k = longest suffix that is palidrome: answer = length of string - k.

concatenate(abcd,3)=abcdabcdabcd. Given string concatenated, find minimum N ? Ex. abcabcabc ==>> 3
Ex. abababab ==>> 2 it also can be 4(ab) but 2(abab) is smaller
a b c d a b c d a b c d
0 0 0 0 1 2 3 4 5 6 7 8 (Failure Function)
As we match longest proper prefix NOT longest prefix
That is if string is 10 times concatenated , the first 9 blocks = the last 9 blocks
Now for abcdabcdabcd. here abcdabcd (first 2 blocks) = abcdabcd (last 2 blocks)
F[size - 1] = 8. So we can get the block easily len - f[len-1] = 12 - 8 = 4
if(len%(len-f[len-1])==0) then len/(len-f[len-1]) is solution else there no solution

why all blocks are equal ? let string s=concatenate(abcd,5). let's divide string for 5 blocks ABCDE
F[len-1]=16 , which means first 16 = last 16 or first 4 blocks = last 4 blocks
ABCD = BCDE Then A = B , B = C , C = D , D = E

Ex. abcdghkmabcd ==>> 1
a b c d g h k m a b c d
0 0 0 0 0 0 0 0 1 2 3 4
len-F[len-1] = 8 12 % 8 != 0
what does this mean ? first 4 = last 4 , but in between is not like them

Given string P , for each prefix , count its frequency
Ex. aabbaaab ==>> 5 3 2 1 1 1 1 1
*/
vector<int>getprefix(string pat)
{
    int m=pat.size();
    vector<int>prefix(m);
    for(int i=1,len=0;i<m;i++)
    {
        while(len>0&&pat[i]!=pat[len])
            len=prefix[len-1];
        if(pat[i]==pat[len])
            prefix[i]=++len;
        else
            prefix[i]=len;
    }
    return prefix;
}
int main()
{
    string pat;cin>>pat;
    vector<int>prefix=getprefix(pat);
    int n=pat.size();
    vector<int>freq(n+1);
    for(int i=0;i<n;i++)
        freq[prefix[i]]++;
    for(int i=n-1;i>0;i--)
        freq[prefix[i-1]]+=freq[i];
    freq.erase(freq.begin());
    for(int i=0;i<freq.size();i++)
        cout<<freq[i] + 1<<' ';
    return 0;
}
/*
Count number of distinct substring
abc => has a, b, c, ab, bc, abc, aaa => has a, aa, aaa
For each prefix P, Count += CountUniquePrefixes( reverse(P) ) // O(n^2)
*/

// KMP algorithm to find a Pattern in a Text.
vector<int>getprefix(string pat)
{
    int m=pat.size();
    vector<int>prefix(m);
    for(int i=1,len=0;i<m;i++)
    {
        while(len>0&&pat[i]!=pat[len])
            len=prefix[len-1];
        if(pat[i]==pat[len])
            ++len;
         prefix[i] = len;
    }
    return prefix;
}
void kmp(string str,string pat)
{
    int n=str.size(),m=pat.size();
    vector<int>prefix=getprefix(pat);
    for(int i=0,len=0;i<n;i++)  // Notic here i = 0 but above i = 1
    {
        while(len>0&&str[i]!=pat[len])
            len=prefix[len-1];
        if(str[i]==pat[len])len++;
        if(len==m)
        {
            cout<<i-m+1<<' ';
            len=prefix[len-1]; // for override
            /*
            len = 0    for not override
            Example : str = ababakaba      pat = aba
            len = prefix[len-1]  --> 0 2 6
            len = 0  --> 0 6
            */
        }
    }
}
int main()
{
    string str,pat;
    cin>>str>>pat;
    kmp(str,pat);
    return 0;
} // O(n+m)

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


// Rolling Hash
#define mod 2123456789ll
#define base 53ll
ll power(ll a,ll b)
{
    ll ans = 1;
    a %= mod;
    while(b)
    {
        if(b&1)
            ans = (ans * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }
    return ans;
} 
ll remove(ll code,ll idx,ll val)
{
    return (code - (val * power(base,idx))%mod + mod) % mod;
}
ll insert(ll code,ll idx,ll val)
{
    return (code + (val * power(base,idx))%mod + mod) % mod;
}
ll shiftleft(ll code)
{
    return (base * code) % mod;
}
ll shiftright(ll code)
{
    return (code * power(base,mod-2)) % mod;
}
ll rolling_hash(string pat)
{
    ll patcode = 0;
    for(int i=0;i<pat.size();i++)
    {
        patcode = shiftleft(patcode);
        patcode = insert(patcode,0,pat[i]);
    }
    return patcode;
}
void pattern_search(string str,string pat)
{
    int n = pat.size();
    ll patcode = rolling_hash(pat);
    
    ll subcode = 0;
    
    for(int i=0;i<str.size();i++)
    {
        if(i-n>=0)
            subcode = remove(subcode,n-1,str[i-n]);
            
        subcode = shiftleft(subcode);
        subcode = insert(subcode,0,str[i]);
        
        if(patcode == subcode)
            cout<< (i+1) - pat.size() + 1 <<'\n';
    }
}
// Time Complexity : O(n log m) where n is length of string str, m is length of string pat
```
