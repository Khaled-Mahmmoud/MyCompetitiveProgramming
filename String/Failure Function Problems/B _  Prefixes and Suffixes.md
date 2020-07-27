# Prefixes and Suffixes

You have a string s. Your task is, for any prefix of string s which matches a suffix of string s, print the number of times it occurs in string s as a substring.

Input : string s (1 ≤ |s| ≤ 10^5). The string only consists of uppercase English letters.

Output : In the first line, print integer k (0 ≤ k ≤ |s|) — the number of prefixes that match a suffix of string s. 
Next print k lines, in each line print two integers li ci. Numbers li ci mean that the prefix of the length li matches the suffix of length li and 
occurs in string s as a substring ci times. Print pairs li ci in the order of increasing li.

input : ABACABA

output : 3

1 4

3 2

7 1

input : AAA

output : 3

1 3

2 2

3 1

**Solution**

create prefix function p of string s and create a tree where vertices —> integers from 0 to |s|, edges —> from p[i] to i for every i (1<=i<=|s|).
The root of the tree is 0. For every vertex v calc the number of values p[i] = v — that is cnt[v]. 

Then for every v calc the sum all values cnt[u] for every u in to subtree of v.

The general answer to the problem is:

Find all lenghts of the prefixes which matches the suffixes, these values are |s|, p[|s|], p[p[|s|]], p[p[p[|s|]]]... 
For every such length L the answer to the problem is cnt[L] + 1.

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

