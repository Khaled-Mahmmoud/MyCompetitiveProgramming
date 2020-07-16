# Diameter of a Binary Tree

The diameter of a tree is the number of nodes on the longest path between two leaves in the tree. 
The [diagram](https://github.com/Khaled-Mahmmoud/MyCompetitiveProgramming/blob/master/img/Tree/Diameter-of-Binary-Tree.png) shows two trees each with diameter nine, the leaves that form the ends of the longest path are colored
(note that there may be more than one path in the tree of the same diameter).

**Solution**

 Diameter of a tree can be calculated by only using the height function, because the diameter of a tree is nothing but maximum value of 
 `(left_height + right_height + 1)` for each node. So we need to calculate this value for each node and update the result. 
 
 Time complexity : O(n)

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
    struct Node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
  
    printf("Diameter is %d\n", diameter(root)); 
  
    return 0; 
}
```
