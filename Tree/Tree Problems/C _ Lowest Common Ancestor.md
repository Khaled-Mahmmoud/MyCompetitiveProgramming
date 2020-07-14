# Lowest Common Ancestor

Following is definition of LCA from Wikipedia:
Let T be a rooted tree. The lowest common ancestor between two nodes n1 and n2 is defined as the lowest node in T 
that has both n1 and n2 as descendants (where we allow a node to be a descendant of itself)
The LCA of n1 and n2 in T is the shared ancestor of n1 and n2 that is located farthest from the root
Computation of lowest common ancestors may be useful, for instance, as part of a procedure for determining the distance between 
pairs of nodes in a tree: the distance from n1 to n2 can be computed as the distance from the root to n1, plus the distance from 
the root to n2, minus twice the distance from the root to their lowest common ancestor. (Source Wiki)

See This [diagram](https://github.com/Khaled-Mahmmoud/MyCompetitiveProgramming/blob/master/img/Tree/lowest%20common%20ancestor.png)
       
LCA(4,5) = 2  , LCA(4,6) = 1 , LCA(3,4) = 1 , LCA(2,4) = 2

### LCA of Binary Search Tree 

If we are given a BST where every node has parent pointer
then LCA can be easily determined by traversing up using parent pointer and printing the first intersecting node
We can solve this problem using BST properties. We can recursively traverse the BST from root
The main idea of the solution is, while traversing from top to bottom, the first node n we encounter with value 
between n1 and n2, i.e., n1 < n < n2 or same as one of the n1 or n2, is LCA of n1 and n2 (assuming that n1 < n2)
So just recursively traverse the BST in, if node’s value is greater than both n1 and n2 then our LCA lies in
left side of the node, if it’s is smaller than both n1 and n2, then LCA lies on right side
Otherwise root is LCA (assuming that both n1 and n2 are present in BST).

Time complexity is O(h) where h is height of tree
```cpp
struct node* lca(struct node* root,int n1,int n2)
{
    if(node == nullptr)
        return nullptr;
    if(root->item > n1 && root->item > n2)
        return lca(root->left,n1,n2);
    if(root->item < n1 && root->item < n2)
        return lca(root->right,n1,n2);
    return root;
};
```
### LCA of Binary Tree

By Storing root to n1 and root to n2 paths):
Following is simple O(n) algorithm to find LCA of n1 and n2.
1) Find path from root to n1 and store it in a vector or array.
2) Find path from root to n2 and store it in another vector or array.
3) Traverse both paths till the values in arrays are same. Return the common element just before the mismatch.
Following is the implementation of above algorithm
```cpp
bool findPath(Node *root, vector<int> &path, int k) 
{ 
    if (root == NULL) return false; 
    path.push_back(root->key); 
    
    if (root->key == k) 
        return true; 
  
    if ( (root->left && findPath(root->left, path, k)) || 
         (root->right && findPath(root->right, path, k)) ) 
        return true; 
  
    path.pop_back(); 
    return false; 
} 
int findLCA(Node *root, int n1, int n2) 
{ 
    vector<int> path1, path2;   
    if ( !findPath(root, path1, n1) || !findPath(root, path2, n2)) 
          return -1; 
     int i; 
    for (i = 0; i < path1.size() && i < path2.size() ; i++) 
        if (path1[i] != path2[i]) 
            break; 
    return path1[i-1]; 
} 
```
