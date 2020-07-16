# Diameter of a Binary Tree

The diameter of a tree is the number of nodes on the longest path between two leaves in the tree. 
The [diagram](https://github.com/Khaled-Mahmmoud/MyCompetitiveProgramming/blob/master/img/Tree/Diameter-of-Binary-Tree.png) shows two trees each with diameter nine, the leaves that form the ends of the longest path are colored
(note that there may be more than one path in the tree of the same diameter).

**Input**

First line contains two integers, N and K, number of nodes in the tree and value of the root.

Next  lines contain details of nodes.

Each detail of node contains two lines. First lines contains a string and second line contains an integer, which denotes the path of the node and the value of the node respectively.

String consists of only L or R. L denotes left child and R denotes right child.

**SAMPLE INPUT**

5 1

L 2

R 3

LL 4

LR 5

**SAMPLE OUTPUT**

4

**Solution**

 Diameter of a tree can be calculated by only using the height function, because the diameter of a tree is nothing but maximum value of 
 `(left_height + right_height + 1)` for each node. So we need to calculate this value for each node and update the result. 
 
 Time complexity : O(n)     where N is the number of nodes in the tree.
 
 

```cpp
struct Node
{ 
    int data; 
    Node* left, *right; 
}; 
Node* newNode(int data) 
{ 
    Node* node = new Node; 
    node->data = data; 
    node->left = node->right = NULL;
    return (node); 
} 
node* insert(node* root,int k,string s,int i)
{
    if(root == nullptr)
        return newNode(k);
    if(s[i]=='R')
        root->right = insert(root->right,k,s,++i);
    else
        root->left = insert(root->left,k,s,++i);
    return root;

}
int height(Node* root, int& ans) 
{ 
    if (root == NULL) 
        return 0; 
    int left_height = height(root->left, ans); 
    int right_height = height(root->right, ans); 
    ans = max(ans, 1 + left_height + right_height); 
    return 1 + max(left_height, right_height); 
} 
int diameter(Node* root) 
{ 
    if (root == NULL) 
        return 0; 
    int ans = INT_MIN; 
    int height_of_tree = height(root, ans); 
    return ans; 
} 
int main() 
{ 
    int n,k;
    cin>>n>>k;
    node* root = newNode(k);
    n--;map<string,int>m;
    while(n--)
    {
        string s;
        cin>>s>>k;
        m[s]=k;
    }
    for(auto x:m)
        root = insert(root,x.second,x.first,0);
    // INPUT may be
    // 3 1
    // LLL 4
    // LL 2
    // L 3
    // So , we used map to store it Sorted 
    // m[L] = 3; m[LL] = 2; m[LLL] = 4;
    cout<<diameter(root);
    return 0; 
}
```

# Print Diameter of a Binary Tree

Now for the node which has the maximum value of (left_height + right_height + 1), we find the longest root to leaf path on the left side and similarly on the right side. Finally, we print left side path, root and right side path.

Time Complexity is O(N). N is the number of nodes in the tree.
```cpp
struct Node { 
    int data; 
    Node *left, *right; 
}; 
  
struct Node* newNode(int data) 
{ 
    struct Node* node = new Node; 
    node->data = data; 
    node->left = node->right = NULL; 
  
    return (node); 
} 
  
int height(Node* root, int& ans, Node*(&k), int& lh, int& rh) 
{ 
    if (root == NULL) 
        return 0; 
  
    int left_height = height(root->left, ans, k, lh, rh); 
    int right_height = height(root->right, ans, k, lh, rh); 
    if (ans < 1 + left_height + right_height) 
    { 
  
        ans = 1 + left_height + right_height; 
        k = root; 
        lh = left_height; 
        rh = right_height; 
    } 
  
    return 1 + max(left_height, right_height); 
} 
void printArray(int ints[], int len, int f) 
{ 
    int i; 
    if (f == 0) { 
        for (i = len - 1; i >= 0; i--) { 
            cout<<ints[i]<<' ';
        } 
    } 
    else if (f == 1) { 
        for (i = 0; i < len; i++) { 
            cout<<ints[i]<<' ';
        } 
    } 
} 
void printPathsRecur(Node* node, int path[], int pathLen,int max, int& f) 
{ 
    if (node == NULL) 
        return; 
  
    path[pathLen] = node->data; 
    pathLen++; 
  
    if (node->left == NULL && node->right == NULL) 
    {  
        if (pathLen == max && (f == 0 || f == 1))
        { 
            printArray(path, pathLen, f); 
            f = 2; 
        } 
    } 
  
    else 
    { 
        printPathsRecur(node->left, path, pathLen, max, f); 
        printPathsRecur(node->right, path, pathLen, max, f); 
    } 
} 
void diameter(Node* root) 
{ 
    if (root == NULL) 
        return; 
    int ans = INT_MIN, lh = 0, rh = 0; 
    Node* k; 
    int height_of_tree = height(root, ans, k, lh, rh); 
    int lPath[100], pathlen = 0,f = 0; 
    printPathsRecur(k->left, lPath, pathlen, lh, f); 
    cout<<k->data<<' '; 
    int rPath[100]; 
    f = 1; 
    printPathsRecur(k->right, rPath, pathlen, rh, f); 
} 
int main() 
{ 
    // Enter the binary tree ... 
    //           1 
    //         /   \      
    //        2     3 
    //      /   \    
    //     4     5 
    //      \   / \  
    //       8 6   7 
    //      / 
    //     9 
    struct Node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->left->right->left = newNode(6); 
    root->left->right->right = newNode(7); 
    root->left->left->right = newNode(8); 
    root->left->left->right->left = newNode(9); 
  
    diameter(root); 
  
    return 0; 
} 
```
