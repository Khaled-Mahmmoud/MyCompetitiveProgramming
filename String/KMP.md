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
void kmp(string str,string pat)
{
    int n=str.size(),m=pat.size();
    vector<int>prefix=getprefix(pat);
    for(int i=0,k=0;i<n;i++)
    {
        while(k>0&&str[i]!=pat[k])
            k=prefix[k-1];
        if(str[i]==pat[k])k++;
        if(k==m)
        {
            cout<<i-m+1<<' ';
            k=prefix[k-1];
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
