# Messenger

Given string is represented as a concatenation of n blocks, each block containing only equal characters.
One block may be described as a pair (li, ci), where li is the length of the i-th block and ci is the corresponding letter. 
Thus, the string s may be written as the sequence of pairs .

Your task is to write the program, that given two compressed string t and s finds all occurrences of s in t. Developers know that there may be many such occurrences, so they only ask you to find the number of them. 

Note that the way to represent the string in compressed form may not be unique. For example string "aaaa" may be given as [(4,a)] , [(3,a),(1,a)] , [(2,a),(2,a)]

Input

The first line of the input contains two integers n and m (1 ≤ n, m ≤ 200 000) — the number of blocks in the strings t and s, respectively.

The second line contains the descriptions of n parts of string t in the format " li- ci" (1 ≤ li ≤ 1 000 000) — the length of the i-th part and the corresponding lowercase English letter.

The second line contains the descriptions of m parts of string s in the format " li- ci" (1 ≤ li ≤ 1 000 000) — the length of the i-th part and the corresponding lowercase English letter.

Output : Print a single integer — the number of occurrences of s in t.

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
    string str;
    cin>>str;
    vector<int>prefix = getprefix(str);
    prefix.push_back(0);
    for(int i=prefix.size()-1;i>0;i--)
        prefix[i] = prefix[i-1];
 
    int cnt[str.size()+1]={};
    for(int i=str.size();i>=0;i--)
        cnt[prefix[i]]+= cnt[i]+1;
 
   vector<pair<int,int>>ans;
   int n = str.size();
   while(prefix[n])
   {
       ans.push_back({prefix[n],cnt[prefix[n]]+1});
       n = prefix[n];
   }
   ans.push_back({str.size(),1});
   sort(ans.begin(),ans.end());
   cout<<ans.size()<<'\n';
   for(int i=0;i<ans.size();i++)
    cout<<ans[i].first<<' '<<ans[i].second<<'\n';
   return 0;
}
```
