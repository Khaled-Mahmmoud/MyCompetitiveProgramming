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
} // O(m)
// Given string P , for each prefix , count its frequency Ex. aabbaaab ==>> 5 3 2 1 1 1 1 1
void frq()
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
}
```
