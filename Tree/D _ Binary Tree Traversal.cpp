/*

Breadth-first traversal
level-order  -->> + A B

Depth-first traversal
Pre-order traversal  : root left right (VLR) or (XLR) -->> + A B
In-order traversal   : left root right (LVR) or (LXR)-->> A + B
post-order traversal : left right root (LRV) or (LRX) -->> A B +

                    +
                   / \
                  A   B


               ****************
               
Pre-order traversal   : A B C D E F
In-order traversal    : C B D A E F
post-order traversal  : C D B F E A
level-order traversal : A B E C D F

                   A
                 /   \
                B     E
              /  \     \
             C    D     F
             
*/

void preorder (node* p)
{
    if(p != nullptr)
    {
        cout<<p->item;
        preorder(p->left);
        preorder(p->right);
    }
}

void inorder (node* p)
{
    if(p != nullptr)
    {
        inorder(p->left);
        cout<<p->item;
        inorder(p->right);
    }
}

void postorder (node* p)
{
    if(p != nullptr)
    {
        postorder(p->left);
        postorder(p->right);
        cout<<p->item;
    }
}

void levelorder (node* p)
{
    if(p != nullptr)
    {
        queue<node*>q;
        q.push_back(p);
        while(!q.empty())
        {
            node* cur=q.front();
            cout<<cur->item;
            if(cur->left!=nullptr)
               q.push_back(cur->left);
            if(cur->right!=nullptr)
               q.push_back(cur->right);
            q.pop();
        }
    }
}
