# Failure Function

failure function expresses longest proper prefix that is a suffix.

Sometimes prefix table is also known as LPS Table. Here LPS stands for **Longest proper Prefix which is also Suffix**

Given String P of length m, define an array F(m).

Let t = P[0..i].

F[i] = length of longest proper prefix of t that is suffix of t.

Other popular name: Prefix Function.

### Prefix function: ababcaba

| prefixes | prefix function|
|---|---|
| i=0 | f[0] = 0 |
| i = 1 , t = ab , PPL = {a} , SL = {ab, b} | f[1] = 0 |
| i = 2	=>	t = aba , PPL = {a, ab} , SL = {aba, ba, a} | f[2] = 1 |
| i = 3	, t = abab , PPL = {a, ab, aba} , SL = {abab, bab, ab, b} | f[3] = 2 |
| i = 4	, t = ababc , PPL = {a, ab, aba, abab} , SL = {ababc, babc, abc, bc, c}| F[4] = 0 |
| i = 5	, t = ababca , PPL = {a, ab, aba, abab, ababc} , SL = {ababca, babca, abca, bca, ca, a}| F[5] = 1 |
| i = 6	, t = ababcab , PPL = {a, ab, aba, abab, ababc, ababca} , SL = {ababcab, babcab, abcab, bcab, cab, ab, b}|F[6] = 2|
| i = 7	, t = ababcaba , PPL = {a, ab, aba, abab, ababc, ababca, ababcab} , SL = {ababcaba, babcaba, abcaba, bcaba, caba, aba, ba, a}|F[7] = 3|

Then F[] = {0, 0, 1, 2, 0, 1, 2, 3}

for example : akaka. then f[] = {0,0,1,2,3}

for example : aaaaa. then f[] = {0,1,2,3,4}

Time Complexity O(m)

```cpp
vector<int>getprefix(string pat)
{
    int m=pat.size();
    vector<int>prefix(m);
    for(int i=1,k=0;i<m;i++)
    {
        while(k>0&&pat[i]!=pat[k])
            k=prefix[k-1];
        if(pat[i]==pat[k])
            prefix[i]=++k;
        else
            prefix[i]=k;
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
```

# Palindrome & Failure Function

Given a string what is the longest prefix that is palindrome ?
Ex. effedcba ==>> effe 
let's assume the char # will not be part of problem 
input + '#' + reverse_input
effedcba#abcdeffe
Now problem , find longest prefix that is suffix .
Failure functiong can answer that easily : F[size-1] is answer.
Time Complexity O(n)

*************************************************************************************************************************

OR reverse the problem
Given a string what is the longest suffix that is palindrome ?
Ex. abcdeffe ==>> effe 
we reverse that string
Now problem , find the longest prefix that is palindrome.
Time Complexity O(n)

*************************************************************************************************************************

Given a string , what is minimum characters to add to convert string to palindrome ?
aaaa ==>> aaaa
abc  ==>> abcba
abcdeffe  ==>> abdcdeffedcba.
let's k = longest suffix that is palidrome
answer = length of string - k.
Time Complexity O(n)

# Repetition & Failure Function

concatenate(abcd,3)=abcdabcdabcd. Given string concatenated, find minimum N

Ex. abcabcabc ==>> 3

Ex. abababab  ==>> 2
   it also can be 4(ab) but 2(abab) is smaller
   
EX. abc  ==>> 1

a b c d a b c d a b c d

0 0 0 0 1 2 3 4 5 6 7 8 (Failure Function)

As we match longest proper prefix NOT longest prefix 

That is if string is 10 times concatenated , the first 9 blocks = the last 9 blocks

here abcdabcd = abcdabcd ( 8 letters)

so we can get the block easily len-f[len-1]=12-8=4

if(len%(len-f[len-1])==0)
then len/(len-f[len-1]) is solution 
else there no solution

**why all blocks are equal ?**

let string s=concatenate(abcd,5) = abcdabcdabcdabcdabcd.
let's divide string for 5 blocks ABCDE

F[len-1]=16 , which means first 16 = last 16 or first 4 blocks = last 4 blocks

ABCD = BCDE Then A = B , B = C , C = D , D = E

a b c d g h k m a b c d

0 0 0 0 0 0 0 0 1 2 3 4

len-F[len-1] = 8   12 % 8 != 0

what does this mean ? first 4 = last 4 , but in between is not like them

# Frequency & Failure Function

Given string P , for each prefix , count its frequency

Ex. aabbaaab ==>> 5 3 2 1 1 1 1

```cpp
vector<int>getprefix(string pat)
{
    int m=pat.size();
    vector<int>prefix(m);
    for(int i=1,k=0;i<m;i++)
    {
        while(k>0&&pat[i]!=pat[k])
            k=prefix[k-1];
        if(pat[i]==pat[k])
            prefix[i]=++k;
        else
            prefix[i]=k;
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
        cout<<freq[i]<<' ';
    return 0;
}
```
