# Binary Search Tree

Binary Search Tree is a node-based binary tree data structure which has the following properties

1) The left subtree of a node contains only nodes with keys lesser than the node’s key
2) The right subtree of a node contains only nodes with keys greater than the node’s key
3) The left and right subtree each must also be a binary search tree

See This [diagram](https://github.com/Khaled-Mahmmoud/MyCompetitiveProgramming/blob/master/img/Tree/binary%20search%20tree.png)

**Find Successor**

1) node has right subtree 
we find mimimum node at right subtree
successor(3) = 4 , successor(8) = 10

2) node doesn't have a right subtree 
Travel up using the parent pointer until you see a node which is left child of it’s parent.The parent of such a node is the successor
successor(7) = 8 , successor(14) = NULL , successor(1) = 3 , successor(4) = 6

**Find Predecessor**

1) node has left subtree 
we find maximum node at left subtree
predecessor(3) = 1 , predecessor(8) = 7

2) node doesn't have a left subtree
Travel up using the parent pointer until you see a node which is right child of it’s parent.The parent of such a node is the predecessor
predecessor(4) = 3 , predecessor(14) = 10 , predecessor(1) = NULL



# Binary Tree Traversal

**Breadth-first traversal**

level-order  -->> + A B

**Depth-first traversal**

Pre-order traversal  : root left right (VLR) or (XLR) -->> + A B

In-order traversal   : left root right (LVR) or (LXR)-->> A + B

post-order traversal : left right root (LRV) or (LRX) -->> A B +

See This [diagram](https://github.com/Khaled-Mahmmoud/MyCompetitiveProgramming/blob/master/img/Tree/binary%20tree%20traversal.png)


```cpp
#include <bits/stdc++.h>
using namespace std;
struct node
{
    int   item;
    node* left;
    node* right;
};
node* newNode(int k)
{
    node* temp = new node;
    temp->item = k;
    temp->left = temp->right = NULL;
    return temp;
}
node* insert(node* root, int k)
{
    if (root == NULL)
        return newNode(k);

    if (k <= root->item)
        root->left = insert(root->left, k);
    else
        root->right = insert(root->right, k);
    return root;
}
node* remove(node* root,int k)
{
    if (root == NULL)
        return root;

    if (k < root->item)
    {
        root->left = remove(root->left, k);
        return root;
    }
    if (k > root->item)
    {
        root->right = remove(root->right, k);
        return root;
    }
    if (root->left == NULL)
    {
        node* temp = root->right;
        delete root;
        return temp;
    }
    if (root->right == NULL)
    {
        node* temp = root->left;
        delete root;
        return temp;
    }

    else
    {
        node* succParent = root;
        node *succ = root->right;

        while (succ->left != NULL)
        {
            succParent = succ;
            succ = succ->left;
        }
        if (succParent != root)
            succParent->left = succ->right;
        else
            succParent->right = succ->right;

        root->item = succ->item;

        delete succ;
        return root;
    }
}
bool search(node* p,int n)
{
    if(p == nullptr)
        return 0;
    if(n == p->item)
        return true;
    if(n <= p->item)
        return search(p->left,n);
    return search(p->right,n);
}
void clear(node* p)
{
    if(p!=nullptr)
    {
        clear(p->left);
        clear(p->right);
        delete p;
    }
}
int height(node* p)      // O(n)
{
    if(p==nullptr)
        return 0;
    return 1 + max(height(p->left),height(p->right));
}
int node_count(node* p)
{
    if(p==nullptr)
        return 0;
    return 1 + node_count(p->left) + node_count(p->right);
}
int leaves_count(node* p)
{
    if(p==nullptr)
        return 0;
    if(p->left==nullptr&&p->right==nullptr)
        return 1;
    return leaves_count(p->left)+leaves_count(p->right);
}
// return the node with minimum value
node* minNode(node* root)
{
    while (root&&root->left != NULL)
        root = root->left;

    return root;
}
// return the node with maximum value
node* maxNode(node* root)
{
    while (root&&root->right != NULL)
        root = root->right;

    return root;
}
bool is_empty()
{
    return root == nullptr;
}
void preorder(node* p)
{
    if(p)
    {
        cout<<p->item<<' ';
        preorder(p->left);
        preorder(p->right);
    }
}
void inorder(node* p)
{
    if(p)
    {
        inorder(p->left);
        cout<<p->item<<' ';
        inorder(p->right);
    }
}
void postorder(node* p)
{
    if(p)
    {
        postorder(p->left);
        postorder(p->right);
        cout<<p->item<<' ';
    }
}
void levelorder(node* p)
{
    if(p)
    {
        queue<node*>q;
        q.push(p);
        while(!q.empty())
        {
            node* cur=q.front();
            cout<<cur->item<<' ';
            if(cur->left!=nullptr)
                q.push(cur->left);
            if(cur->right!=nullptr)
                q.push(cur->right);
            q.pop();
        }
    }
}
int main()
{
    node* root = nullptr;
    root = insert(root,6);
    inorder(root);
    cout<<'\n';
    root = remove(root,6);
    inorder(root);
    root = insert(root,7);
    root = insert(root,9);
    bool flag = search(6);
    node* x = minNode(root);
    node* y = maxNode(root);
    return 0;
}

```
