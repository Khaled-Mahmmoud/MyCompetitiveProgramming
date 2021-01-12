```cpp
// KMP algorithm to find a Pattern in a Text.
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
} // O(n + m)
```cpp
