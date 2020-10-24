# KMP 

KMP Algorithm is one of the most popular **patterns matching** algorithms and it stands for **Knuth Morris Pratt**

KMP algorithm was the first linear time complexity algorithm for string matching.

KMP algorithm is one of the string matching algorithms used to find a Pattern in a Text.

This algorithm compares character by character from left to right, But whenever a mismatch occurs, it uses a preprocessed table called **Prefix Table** to skip characters comparison while matching.

Given a string S, pattern P, find all P in S , S = abababcabaddd, P = aba

2 matches: ab**aba**bc**aba**ddd

**Brute Force**

Let: n = length(S) and m = length(P)

Try every location in S, and check of it matches P For i = 0   to   n-m

Let t  = S[i, …i+m-1]	=> Substring from S. If equal(P, t) Display, we found a match

Time Complexity  O(nm)

**Better Solution**

Time Complexity O(n+m)
```cpp
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
void kmp(string str,string pat)
{
    int n=str.size(),m=pat.size();
    vector<int>prefix=getprefix(pat);
    for(int i=0,len=0;i<n;i++)
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
}

```
