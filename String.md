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

Given a string what is the longest suffix that is palindrome ? Ex. abcdeffe ==>> effe
we reverse that string: Now problem , find the longest prefix that is palindrome.

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
```
