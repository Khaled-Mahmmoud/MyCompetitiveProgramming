# Add and Search Word 

Design a data structure that supports the following two operations:

void addWord(word)

bool search(word)

search(word) can search a literal word or a regular expression string containing only letters a-z or `.`

A `.` means it can represent any one letter.

addWord("bad")

addWord("dad")

addWord("mad")

search("pad") -> false

search("bad") -> true

search(".ad") -> true

search("b..") -> true

```cpp
struct node
{
    node* edge[30]={};
    int cnt=0,en=0;
};
class WordDictionary
{
    node* root;
    int sz=0,d=0;
public:
    WordDictionary() 
    {
        root = new node();
        sz=d=0;
    }
    
    void addWord(string s)
    {
        node* cur = root;
        for(int i=0;s[i];i++)
        {
            cur->cnt++;int c = s[i]-'a';
            if(cur->edge[c]==NULL)
            {
                cur->edge[c]=new node();
                sz++;
            }
            cur = cur->edge[c];
        }
        cur->cnt++;
        d+=(++cur->en==1);
    }

    bool searchHelper(const string& word, int index, node* curV) 
    {
        if (index == word.length()) 
            return curV->en;
        
        char curChar = word[index];

        if (curChar != '.') 
        {
            if (curV->edge[curChar - 'a'])
                return searchHelper(word, index + 1, curV->edge[curChar - 'a']);
            return false;
        }
        
        for (int i = 0; i < 26; i++) 
            if (curV->edge[i]) 
                if (searchHelper(word, index + 1, curV->edge[i]))
                    return true;
        return false;
    }
    
    bool search(string word)
    {
         return searchHelper(word, 0, root);
    }
};
```
