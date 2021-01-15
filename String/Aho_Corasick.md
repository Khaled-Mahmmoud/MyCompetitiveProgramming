```cpp
// https://cutt.us/MH97O
struct aho_corasick
{
    struct trie_node
    {
        map<char, trie_node*> nxt;
        int cnt_patterns = 0;
        trie_node *fail;
        bool is_root;
        trie_node(bool is_root = false) :
            is_root(is_root)
        {
            fail = NULL;
        }
        void insert(const char *str, int patternIdx)
        {
            if (*str == '\0')
            {
                cnt_patterns++;
                return;
            }
            if (nxt.find(*str) == nxt.end())
                nxt[*str] = new trie_node();
            char ch = *str;
            nxt[ch]->insert(++str, patternIdx);
        }
    };
    trie_node *root;
    vector<string> patterns;
    aho_corasick(const vector<string> &_patterns)
    {
        patterns = _patterns;
        root = new trie_node(true);
        for (int i = 0; i < sz(patterns); i++)
            root->insert(patterns[i].c_str(), i);
        buildAhoTree();
    }

    void fail(trie_node *&cur, char ch)
    {
        while (!cur->is_root && !cur->nxt.count(ch))
            cur = cur->fail;
        if (cur->nxt.count(ch))
            cur = cur->nxt[ch];
        else
            cur = root;
    }
    void buildAhoTree()
    {
        queue<trie_node*> q;
        for (auto &child : root->nxt)
        {
            q.push(child.second);
            child.second->fail = root;
        }
        while (!q.empty())
        {
            trie_node *cur = q.front();
            q.pop();
            for (auto &child : cur->nxt)
            {
                trie_node *k = cur->fail;
                fail(k, child.first);
                child.second->fail = k;
                child.second->cnt_patterns += k->cnt_patterns;
                q.push(child.second);
            }
        }
    }
    vector<int> match(const string &str)
    {
        trie_node *k = root;
        vector<int> rt(str.size());
        for (int i = 0; i < sz(str); i++)
        {
            fail(k, str[i]);
            rt[i] += k->cnt_patterns;
        }
        return rt;
    }
};
```
