# Failure Function

failure function expresses longest proper prefix that is a suffix.

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
