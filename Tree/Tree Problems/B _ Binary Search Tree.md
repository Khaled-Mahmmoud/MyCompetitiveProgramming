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
                else if(n <= cur->item)
                    cur = cur->left;
                else
                    cur = cur->right;
            }
            if(n <= trailcur->item)
                trailcur->left = newnode;
            else
                trailcur->right = newnode;
        }
    }
    void remove(int n)
    {
        node* cur = root;
        node* trailcur = root;
        if(n == root->item&&root->left==nullptr&&root->right==nullptr)
        {
            root = nullptr;
            return;
        }
        while(cur!=nullptr)
        {
            if(cur->item == n)
            {
                if(cur->left==nullptr&&cur->right==nullptr)
                {
                    if(trailcur->left == cur)
                         trailcur->left = nullptr;
                    else 
                         trailcur->right = nullptr;
                    delete cur;
                }
                else
                    delete_from_tree(cur);
                return;
            }
            trailcur = cur;
            if(n <= cur->item)
                cur = cur->left;
            else
                cur = cur->right;
        }
    }
    void print()
    {
        pre_order(root);
    }

private:

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
    void clear(node* p)
    {
        if(p!=nullptr)
        {
            clear(p->left);
            clear(p->right);
            delete p;
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
    void delete_from_tree(node *p)
    {
        node* cur;
        node* trailcur;

        if(p->left==nullptr)
        {
            cur = p;
            cur = cur->right;
            p->item = cur->item;
            p->right = cur->right;
            p->left = cur->left;
            delete cur;
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
    void pre_order(node *p)
    {
        if(p == nullptr)
            return;
        cout<<p->item<<' ';
        pre_order(p->left);
        pre_order(p->right);
    }
};
int main()
{
    BinarySearchTree b;
    b.insert(10);
    b.insert(20);
    b.insert(5);
    b.print();
    b.remove(10);
    b.tree_search(20);
    return 0;
}
```
