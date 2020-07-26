# Find maximum XOR of given integer in a stream of integers

You are given a number of queries Q and each query will be of the following types:

Query 1 : add(x) This means add x into your data structure.

Query 2 : maxXOR(y) This means print the maximum possible XOR of y with all the elements already stored in the data structure.

1 <= x, y <= 10^9

1 <= 10^5 <= Q

The data structure begins with only a 0 in it.

Input: (1 10), (1 13), (2 10), (1 9), (1 5), (2 6)

Output: 7 15

**Solution**

A good way to solve this problem is to use a Trie.
```cpp
struct TrieNode
{
    TrieNode* Children[2]; 
    bool isLeaf;
};
```
Another thing to handle is that we have to pad the binary equivalent of each input number by a suitable number of zeros to the left before storing them. The maximum possible value of x or y is 10^9 and hence 32 bits will be sufficient.

**So how does this work?**
Assume we have to insert 3 and 7 into Trie. The Trie starts out with 0 and after these three insertions can be visualized like [this](https://github.com/Khaled-Mahmmoud/MyCompetitiveProgramming/blob/master/img/String/trie-maximum-xor-1.png).

For simplification, the padding has been done to store each number using 3 bits. Note that in binary:

3 is 011

7 is 111

Now if we have to insert 1 into our Trie, we can note that 1 is 001 and we already have path for 00. 
So we make a new node for the last set bit and after connecting, we get [this](https://github.com/Khaled-Mahmmoud/MyCompetitiveProgramming/blob/master/img/String/trie-maximum-xor-2.png).

Now if we have to take XOR with 5 which is 101, we note that for the leftmost bit (position 2), we can choose a 0 starting at the root and thus we go to the left. This is the position 2 and we add 2^2 to the answer.
For position 1, we have a 0 in 5 and we see that we can choose a 1 from our current node. Thus we go right and add 2^1 to the answer.
For position 0, we have a 1 in 5 and we see that we cannot choose a 0 from our current node, thus we go right.

The path taken for 5 is shown [diagram](https://github.com/Khaled-Mahmmoud/MyCompetitiveProgramming/blob/master/img/String/trie-maximum-xor-3.png). The answer is thus 2^2 + 2^1 = 6.

```cpp
struct node
{
    node* edge[2]={};
};
class trie
{
    node* root = new node();
public:
    void insert(int x)   // O(log(x))
    {
        node* cur = root;
        for(int i=31;i>=0;i--)
        {
            bool f = x & (1<<i);
            if(!cur->edge[f])
                cur->edge[f] = new node();
            cur = cur->edge[f];
        }
    }
    int getxor(int x)   // O(log(x))
    {
        node* cur = root;int ans = 0;
        for(int i=31;i>=0;i--)
        {
            bool f = x & (1<<i);
            if(cur->edge[f^1])
            {
                ans = ans + (1<<i);
                cur = cur->edge[f^1];
            }
            else
                cur = cur->edge[f];
        }
        return ans;
    }
};
int main()
{
    trie t;
    int n,q,x;cin>>n;
    while(n--)        // O(n*log(x))
    {
        cin>>x;
        t.insert(x);
    }
    cin>>q;
    while(q--)    // O(q*log(x))
    {
        cin>>x;
        cout<<t.getxor(x)<<'\n';
    }
    return 0;
}

```
