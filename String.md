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
// O(m)
/*
Given a string what is the longest prefix that is palindrome ? Ex. effedcba ==>> effe
input + '#' + reverse_input ==>> effedcba#abcdeffe
Now problem , find longest prefix that is suffix.

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

Ex. abcdghkmabcd ==>> 1
a b c d g h k m a b c d
0 0 0 0 0 0 0 0 1 2 3 4
len-F[len-1] = 8 12 % 8 != 0
what does this mean ? first 4 = last 4 , but in between is not like them

Given string P , for each prefix , count its frequency
Ex. aabbaaab ==>> 5 3 2 1 1 1 1 1
*/
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
/*
Count number of distinct substring
abc => has a, b, c, ab, bc, abc, aaa => has a, aa, aaa
For each prefix P, Count += CountUniquePrefixes( reverse(P) ) // O(n^2)
*/

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
}
// O(n + m)

/*
Lyndon Factorization
A string is called simple (or a Lyndon word), if it is strictly smaller than any of its own proper suffixes. 
Examples of simple strings are: a, b, ab, aab, abb, ababb, abcd. It can be shown that a string is simple,
if and only if it is strictly smaller than all its proper cyclic shifts.
Next, let there be a given string s. The Lyndon factorization of the string s is a factorization s = w1 w2 … wk,
where all strings wi are simple, and they are in non-increasing order w1 ≥ w2 ≥ ⋯ ≥ wk
Example of Lyndon factorization :: ZAA --> Z, A, A ; ZAB --> Z, AB ; CBA --> C, B, A ; ABCABCABC --> ABC, ABC, ABC
*/
vector<string> duval(string s) 
{
    int n = s.size();
    int i = 0;
    vector<string> factorization;
    while (i < n) 
    {
        int j = i + 1, k = i;
        while (j < n && s[k] <= s[j]) 
        {
            if (s[k] < s[j])
                k = i;
            else
                k++;
            j++;
        }
        while (i <= k)
        {
            factorization.push_back(s.substr(i, j - k));
            i += j - k;
        }
    }
    return factorization;
}
/*
Finding the smallest cyclic shift
Given a string S[1..n] . A rotation on S is that we move the first character to the right-most of the string.
More specific, after a rotation, S becomes T = S[2..n] + S[1].
For example: S = abcaa, then after a rotation we have S = bcaaa.
Find the minimum number of rotations to make S become the smallest lexicographical order string.
Input : A single line contains a string S. S contains only small letters of English alphabet (‘a’ .. ‘z’),
and the length of S is not more than 100000.
Output : A tow lines contains an integer which represents the minimum number of rotations.
and next line while represents the smallest cyclic shift
Input : mississippi, Output : 10
*/
void min_cyclic_string(string s)
{
    s += s;
    int n = s.size();
    int i = 0, ans = 0;
    while (i < n / 2)
    {
        ans = i;
        int j = i + 1, k = i;
        while (j < n && s[k] <= s[j]) 
        {
            if (s[k] < s[j])
                k = i;
            else
                k++;
            j++;
        }
        while (i <= k)
            i += j - k;
    }
    cout<<ans<<'\n';
    cout<<s.substr(ans, n / 2);
}

// Rabin-Karp Algorithm
// count number of k-length substrings of given string that is palindrome
const int mod = 1e9 + 7;
const int base = 128;
int mul(int x,int y)
{
    return 1ll * x * y % mod;
}
int power(int a,int b)
{
    int ans = 1;
    while(b)
    {
        if(b&1)
            ans = mul(ans,a);
        b >>= 1;
        a = mul(a,a);
    }
    return ans;
}
const int inv = power(base,mod-2);
int add(int x,int y)
{
    return (x+y)%mod;
}
int sub(int x,int y)
{
    return add(x,mod-y);
}
int rabin(string s,int k)
{
    int h1 = 0,h2 = 0, p = 1;
    for(int i=0,j=k-1;i<k;i++,j--)
    {
        if(i)
            p = mul(p,base);
        h1 = mul(h1,base);
        h1 = add(h1,s[i]);

        h2 = mul(h2,base);
        h2 = add(h2,s[j]);
    }
    int res = 0;
    for(int i=k,j=0;;i++,j++)
    {
        res += h1 == h2;
        if(!s[i])
            break;
        h1 = sub(h1,mul(s[j],p));
        h1 = mul(h1,base);
        h1 = add(h1,s[i]);

        h2 = sub(h2,s[j]);
        h2 = mul(h2,inv);
        h2 = add(h2,mul(s[i],p));
    }
    return res;
}
int main()
{
    string s;
    int k;
    cin>>k>>s;
    cout<<rabin(s,k);
    return 0;
}


/*
Trie
insert OR search OR erase O(L) Where L length of a word
implementation O(N * L) Where n is number of words and L is average length of strings
*/
// Trie static
#define N 100009
int sz,d;
vector<int>en(N);vector<int>prefix(N);
vector<vector<int>>node(N,vector<int>(27));
//                                     ^ OR 255 for all characters and digits and symbols
void insert(string s)
{
    int cur=0;
    for(int i=0;s[i];i++)
    {
        prefix[cur]++;
        int c=s[i]-'a';
        if(!node[cur][c]) // if 255 we put node[cur][s[i]]
            node[cur][c]=++sz;
        cur=node[cur][c];
    }
    prefix[cur]++;
    d+=(++en[cur]==1);
}
bool search(string s)
{
    int cur=0;
    for(int i=0;s[i];i++)
    {
        int c=s[i]-'a';
        if(!node[cur][c])
            return false;
        cur=node[cur][c];
    }
    return en[cur];
}
void remove(string s)
{
    int cur=0;
    for(int i=0;i<s[i];i++)
    {
        prefix[cur]--;
        int c=s[i]-'a';
        int nx=node[cur][c];
        if(prefix[nx]==1)
        {
            node[cur][c]=0;
        }
        cur=nx;
    }
    prefix[cur]--;
    d-=(--en[cur]==0);
}
int main()
{
    int n,m;
    cin>>n>>m;
    string x;
    while(n--)
    {
        cin>>x;
        insert(x);
    }
    remove(x);
    while(m--)
    {
        cin>>x;
        cout<<(search(x)?"YES":"NO")<<'\n';
    }
    return 0;
}
// Trie dynamic
#define N 27
struct node
{
    node* edge[N]={};
    int prefix=0,en=0;
};
class trie
{
    node* root = new node();
    int sz=0,d=0;

public:
    void insert(string str)
    {
        node* cur = root;
        for(int i=0;str[i];i++)
        {
            cur->prefix++;
            int c=str[i]-'a';
            if(cur->edge[c]==nullptr)
            {
                cur->edge[c]=new node();
                sz++;
            }
            cur=cur->edge[c];
        }
        cur->prefix++;
        d+=(++cur->en==1);
    }
    void remove(string str)
    {
        node* cur = root;
        for(int i=0;str[i];i++)
        {
            cur->prefix--;
            int c=str[i]-'a';
            node* nx = cur->edge[c];
            if(nx->prefix==1)
            {
                destroy(nx);
                d--;
                cur->edge[c]=nullptr;
                return;
            }
            cur = nx;
        }
        cur->prefix--;
        cur->en--;
    }
    int search(string str)
    {
        node* cur = reach(str);
        return cur != nullptr ? cur->en: 0;
    }
    int getprefix(string str)
    {
        node* cur = reach(str);
        return cur != nullptr ? cur->prefix: 0;
    }
    int getdistinct() const
    {
        return d;
    }
    void clear()
    {
        destroy(root);
        root = new node();
        sz=d=0;
    }
private:
    node* reach(string str)
    {
        node* cur = root;
        for(int i=0;str[i];i++)
        {
            int c=str[i]-'a';
            node* nx = cur->edge[c];
            if(nx==nullptr)
                return nullptr;
            cur = nx;
        }
        return cur;
    }
    void destroy(node* root)
    {
        if(root==nullptr)
            return ;
        for(int i=0;i<N;i++)
            destroy(root->edge[i]);
        delete root;
    }
};
int main()
{
    trie t;
    t.insert("abc");
    t.insert("adc");
    if(t.search("abc"))cout<<"k";       // k
    t.remove("abc");
    t.clear();
    if(t.search("adc"))cout<<"h";      // m
    else cout<<"m";                 
    cout<<t.getdistinct();             // 0
    return 0;
}
```
