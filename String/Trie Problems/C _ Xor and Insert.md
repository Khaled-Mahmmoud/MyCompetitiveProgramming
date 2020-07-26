# Xor and Insert

At the first, you have a set  (it contains a zero). There are three types of query:

1 x : Add x to the set.

2 x : For each element like y set y = y xor x.

3 : Print the minimum of the set.

Input : The first line contains an integer q (q<= 500 000). In the next q lines, queries are given where x <= 10^9.

Output : For each query of the third type, print the answer.
 

SAMPLE INPUT 

6

3

1 7

3

2 4

1 5

3

SAMPLE OUTPUT 

0

0

3

**Solution**

Suppose we insert A1, A2, A3 and then ask to xor everything with X1, X2, X3. 
Then it is the same as Xor-ing with X = XOR(x1, x2, x3). We have already noted how to do this with a trie.

Let X = XOR(X1, X2, ... , Xn), where X1, X2, ... , Xn are all asked in the second query.

Get the minimum 
We were supposed to have XOR-ed the entire array so far with X. 
So now we will just calculate the minimum value of XOR(X, Y) with the help of the trie.

Insert A, We must not insert A into the trie, but XOR(A, X). This is a very important step. Why ? 

Suppose we do this, Insert A1, A2, XOR with X1, Insert A3, XOR with X2. When we are asked the minimum now, we will find out the minimum value in 
{XOR(A1, X1, X2), XOR(A2, X1, X2), XOR(A3, X1, X2)}. But A3 has only been XOR-ed with X2 and not X1. 


So it is critical that at every moment in time that we insert an element A into the trie, we insert XOR(A, X). 
This ensures that when we caluclate the minimum, it will cancel out the previous XORs. 

So in this example, our trie will contain {A1, A2, XOR(A3, X1)}

When we query the minimum value of XOR(X), we will be finding the minimum of 
{XOR(A1, X1, X2), XOR(A2, X1, X2), XOR(A3, X2)}

```cpp
#include <bits/stdc++.h>
using namespace std;
int Xor;
struct node
{
    node* edge[2]={};
};
class trie
{
    node* root = new node();
public:
    void insert(int x)
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
    int getminimum(int x)
    {
        node* cur = root;
        int ans = 0;
        for(int i=31;i>=0;i--)
        {
            bool f = x & (1<<i);
            if(cur->edge[f])
                cur = cur->edge[f];
            else
            {
                ans = ans + (1<<i);
                cur = cur->edge[f^1];
            }
        }
        return ans;
    }
};
int main()
{
    trie t;
    t.insert(0);
    int q;cin>>q;
    while(q--)
    {
        int n,x;
        cin>>n;
        if(n==1)
        {
            cin>>x;
            x = x ^ Xor;
            t.insert(x);
        }
        else if(n==2)
        {
            cin>>x;
            Xor = Xor ^ x;
        }
        else
            cout<<t.getminimum(Xor)<<'\n';
    }
    return 0;
}
```
