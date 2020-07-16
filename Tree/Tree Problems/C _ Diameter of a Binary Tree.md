# Diameter of a Binary Tree

The diameter of a tree is the number of nodes on the longest path between two leaves in the tree. 
The [diagram](https://github.com/Khaled-Mahmmoud/MyCompetitiveProgramming/blob/master/img/Tree/Diameter-of-Binary-Tree.png) shows two trees each with diameter nine, the leaves that form the ends of the longest path are colored
(note that there may be more than one path in the tree of the same diameter).

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
    Node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    cout<<diameter(root)); 
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
  
int height(Node* root, int& ans, Node*(&k), int& lh, int& rh, int& f) 
{ 
    if (root == NULL) 
        return 0; 
  
    int left_height = height(root->left, ans, k, lh, rh, f); 
    int right_height = height(root->right, ans, k, lh, rh, f); 
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
            printf("%d ", ints[i]); 
        } 
    } 
    else if (f == 1) { 
        for (i = 0; i < len; i++) { 
            printf("%d ", ints[i]); 
        } 
    } 
} 
void printPathsRecur(Node* node, int path[], int pathLen,int max, int& f) 
{ 
    if (node == NULL) 
        return; 
  
    path[pathLen] = node->data; 
    pathLen++; 
  
    if (node->left == NULL && node->right == NULL) {  
        if (pathLen == max && (f == 0 || f == 1)) { 
            printArray(path, pathLen, f); 
            f = 2; 
        } 
    } 
  
    else { 
        printPathsRecur(node->left, path, pathLen, max, f); 
        printPathsRecur(node->right, path, pathLen, max, f); 
    } 
} 
void diameter(Node* root) 
{ 
    if (root == NULL) 
        return; 
    int ans = INT_MIN, lh = 0, rh = 0; 
    int f = 0; 
    Node* k; 
    int height_of_tree = height(root, ans, k, lh, rh, f); 
    int lPath[100], pathlen = 0; 
    printPathsRecur(k->left, lPath, pathlen, lh, f); 
    printf("%d ", k->data); 
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
