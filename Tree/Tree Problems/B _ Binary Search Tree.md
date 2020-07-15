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

```cpp
struct node
{
    int   item;
    node* left;
    node* right;
};
class BinarySearchTree
{
    node* root;
public:
    BinarySearchTree() // constructor
    {
        root=nullptr;
    }
    ~BinarySearchTree()  // destructor
    {
        clear(root);
    }
    bool is_empty()
    {
        return root == nullptr;
    }
    int tree_height()
    {
        return height(root);
    }
    int tree_node_count()
    {
        return node_count(root);
    }
    int tree_leaves_count()
    {
        return leaves_count(root);
    }
    void clear_tree()
    {
        return clear(root);
    }
    bool tree_search(int n)
    {
        return search(root,n);
    }
    bool search_plus(int n)
    {
        node* cur=root;
        while(cur!=nullptr)
        {
            if(cur->item == n)
                return true;
            else if(cur->item > n)
                cur = cur->left;
            else
                cur = cur->right;
        }
        return false;
    }
    void insert(int n)
    {
        node* cur;
        node* trailcur;
        node* newnode;

        newnode = new node();
        newnode->item = n;
        newnode->left = nullptr;
        newnode->right= nullptr;

        if(root==nullptr)
            root=newnode;
        else
        {
            cur = root;
            while(cur != nullptr)
            {
                trailcur = cur;
                if(cur->item == n)
                {
                    cout<<"The insert item is already in the list -- ";
                    cout<<"duplicates are not allowed"<<endl;
                    return;
                }
                else if(cur->item > n)
                    cur = cur->left;
                else
                    cur = cur->right;
            }
            if(trailcur->item > n)
                trailcur->left = newnode;
            else
                trailcur->right = newnode;
        }
    }
    void remove(int n)
    {
        node* cur = root;
        while(cur!=nullptr)
        {
            if(cur->item == n)
                delete_from_tree(cur);
            else if(cur->item > n)
                cur = cur->left;
            else
                cur = cur->right;
        }
    }

private:
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
    bool search(node* p,int n)
    {
        if(p == nullptr)
            return 0;
        if(p->item == n)
            return true;
        if(p->item > n)
            return search(p->left,n);
        return search(p->right,n);
    }
    void delete_from_tree(node *p)
    {
        node* cur;
        node* trailcur;
        node* temp;
        if(p->left==nullptr&&p->right==nullptr)
            delete p;
        else if(p->left==nullptr)
        {
            temp = p;
            p = p->right;
            delete temp;
        }
        else if(p->right==nullptr)
        {
            temp = p;
            p = p->left;
            delete temp;
        }
        else
        {
            cur = p->left;
            trailcur = nullptr;
            while(cur->right!=nullptr)
            {
                trailcur = cur;
                cur = cur->right;
            }
            p->item = cur->item;

            if(trailcur == nullptr)
                p->left = cur->left;
            else
                trailcur->right = cur->left;

            delete cur;
        }
    }
};
int main()
{
    BinarySearchTree b;
    b.insert(10);
    b.insert(20);
    b.insert(5);
    b.remove(10);
    return 0;
}
```
