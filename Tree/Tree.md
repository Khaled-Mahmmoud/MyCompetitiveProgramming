# Tree Data Structure 

Search - Remove - Add ==>>{ O(log n) - Best Case } , { O(n) - Worst Case }

Tree types 

1) Binary Tree ( Binary Search Tree , AVL tree or Height Balanced Binary Tree , Red-black tree )
2) B Tree
3) Heaps
4) Trees
5) Multiway tree
6) Application Specific tree
7) Huffman Coding Tree

```
                A           Level : 0
             /  |  \ brunch or edge
            B   E   F       Level : 1
          /  \    / | \ brunch
         C    D  G  H  I    Level : 2
```
     (this tree has 8 brunch(edges) and 9 nodes)

root      -->> A

parent    -->> A , B , F

child  -->> B,E,F  C,D  G,H,I

leaves    -->> C,D  E  G,H,I

Siblings  -->> {B,E,F}  {C,D}   {G,H,I}

Ancestor  -->> C{A,B}  E{A}    I{A,F}

Depth(C) = 2 (path from root to C) , Depth(E) = 1 , Depth(A) = 0

Height(B) = 1 (path from B to the farthest leave node) , Height(A) = 2

Height of tree is path from root to the farthest leave node

Height of tree that has only one node is zero

Height of empty tree is -1

`Edges = number of nodes - 1` 

outdegree(A) = 3 (number of nodes branched from A) , outdegree(B) = 2 , outdegree(H) = 0

indegree(F) = 1 (number of nodes that F is branched from) , indegree(A) = 0

total degree(B) = outdegree(B) + indegree(B) = 2 + 1 = 3

Parenthetical notation = A(B(CD)EF(GHI))

            B   
          /  \     is subtree of above tree
         C    D

```
     I         root (root is also an internal node, unless it is leaf)
   /   \
  I     I      internal nodes
 /     / \
o     o   o    external nodes (or leaves)
```

# Binary Tree

A binary tree is a structure comprising nodes, where each node has the following 3 components:

1) Data element : Stores any kind of data in the node
2) Left pointer : Points to the tree on the left side of node
3) Right pointer : Points to the tree on the right side of the node

If a tree is empty, it is represented by a null pointer.
```
                            (left,item,right)
                           /                \
                          /                  \
                 (left,item,right)     (left,item,right)
                 /               \                     \
                /                 \                     \
        (left,item,right)    (left,item,right)    (left,item,right)
        
```
```cpp
struct node
{
     Type item;
     node* left;
     node* right;
};
```

## Types of Binary Tree

**Full(strictly) Binary Tree**

if Every node has zero or two children
```
           O
         /   \
        O     O
      /   \
     O     O
         /   \
        O     O
```

**Complete Binary Tree**

1) all levels is completely filled except the last level
2) all Nodes as left as possible in the last level
```
           O
         /   \
        O     O
      /   \
     O     O
```
This below binary trees is not complete binary tree
```
           O            
         /   \
        O     O
      /   \     \
     O     O     O
     
           O            
         /   \
        O     O
            /   \
           O     O
```

**Perfect Binary tree**

1) every node has two children except leaves
2) all leaves are at the same level
```
            O            
         /     \
        O       O
      /   \   /   \
     O     O O     O
```
**Balanced Binary Tree**

1) the height of tree = O(log2(n))
2) | height(left subtree) - height(right subtree) | <= 1   //   {1,0,-1}
```
          3 - 2 = (1)--> Balance Factor
           3O2          
         /     \
       2O1     2O1
      /   \   /   \
     O     O O     O
    /         \
   O           O
```
**A degenerate (or Pathological) tree**

1) every parent node has only one child eigher left or right
2) such trees are performance-wise same as linked-list
```
         O
          \
           O
            \
             O
              \
               O
                \
                 O
```

         Max no. of nodes at level L = 2^L
         
         Max no. of nodes in binary tree = 2^(h+1) - 1 (where h is height of tree)   //  as perfect tree
```
            O           Max no. of nodes at level 0 = 1 = 2^0
         /     \
        O       O       Max no. of nodes at level 1 = 2 = 2^1
      /   \   /   \
     O     O O     O    Max no. of nodes at level 2 = 4 = 2^2
```
