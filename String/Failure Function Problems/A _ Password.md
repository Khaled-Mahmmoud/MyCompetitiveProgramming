# Password

Asterix, Obelix and their temporary buddies Suffix and Prefix has finally found the Harmony temple. However, its doors were firmly locked and even Obelix had no luck opening them.

A little later they found a string s, carved on a rock below the temple's gates. Asterix supposed that that's the password that opens the temple and read the string aloud. However, nothing happened. Then Asterix supposed that a password is some substring t of the string s.

Prefix supposed that the substring t is the beginning of the string s; Suffix supposed that the substring t should be the end of the string s; and Obelix supposed that t should be located somewhere inside the string s, that is, t is neither its beginning, nor its end.

Asterix chose the substring t so as to please all his companions. Besides, from all acceptable variants Asterix chose the longest one (as Asterix loves long strings). When Asterix read the substring t aloud, the temple doors opened.

You know the string s. Find the substring t or determine that such substring does not exist and all that's been written above is just a nice legend.

Input :
You are given the string s whose length can vary from 1 to 10^6 (inclusive), consisting of small Latin letters.

Output :
Print the string t. If a suitable t string does not exist, then print "Just a legend" without the quotes.

```cpp
vector<int> getprefix(string pat)
{
    int m = pat.size();
    vector<int>prefix(m);
    for(int i=1,len=0;i<m;i++)
    {
        while(len>0&&pat[i]!=pat[len])
            len = prefix[len-1];
        if(pat[i]==pat[len])
            prefix[i] = ++len;
        else
            prefix[i] = len;
    }
    return prefix;
}
int main()
{
    string str,str1;cin>>str;
    vector<int> prefix = getprefix(str);
    int n = str.size();
    if(!prefix[n-1])return cout<<"Just a legend",0;
    for(int i=0;i<n-1;i++)
        if(prefix[i]==prefix[n-1])
           return cout<<str.substr(0,prefix[i]),0;
    if(prefix[prefix[n-1]-1])
        return cout<<str.substr(0,prefix[prefix[n-1]-1]),0;
    return cout<<"Just a legend",0;
    return 0;
}
```
