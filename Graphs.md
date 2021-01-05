```cpp
/*
Directed graph : is a graph in which all the edges are uni-directional
Undirected graph: is a graph in which all the edges are bi-directional 
Weighted graph: In which each edge is assigned a weight or cost
Cyclic graph: if the graph comprises a path that starts from a vertex and ends at the same vertex
Connected graph: if from any node in graph , we can reach to all nodes
Disconnected graph: if above condition is not met
Null Graph: A graph having no edges
Trivial Graph: a graph with only one vertex
Simple graph: if graph doesn't contain any loop or parallel edges
Not simple graph: if above condition is not met
K-regular Graph: if all its vertices have the same degree k.
Complete graph: if from any node in graph , we can reach to all nodes but path = 1
Bipartite Graph: vertices can be divided into two disjoint sets, every edge connects a vertex in V1 to one in V2.  
Complete Bipartite Graph: if every vertex in V1 is connected to every vertex of V2.
Star Graph: a grapth that n – 1 vertices are connected to a single central vertex
Complement of a Graph: if both graph I and graph II are combined together to form a complete graph,
then graph I and graph II are called complements of each other
Simple path: is a path from v to w with no repeated vertices, except that the first and last may be the same vertex.
Tree is a connected graph that doesn't contain any cycles in which any two vertices are connected by only one path.
Tree is an acyclic graph and has N - 1 edges where N is the number of vertices. Each node in a graph may have one 
or multiple parent nodes. However, in a tree, each node (except the root node) comprises exactly one parent node.

                A           Level : 0
             /  |  \ brunch or edge
            B   E   F       Level : 1
          /  \    / | \ brunch
         C    D  G  H  I    Level : 2
         
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
outdegree(A) = 3 (number of nodes branched from A) 
indegree(F) = 1 (number of nodes that F is branched from) 
degree(B) = outdegree(B) + indegree(B) = 2 + 1 = 3

Parenthetical notation = A(B(CD)EF(GHI))

            B   
          /  \     is subtree of above tree
         C    D

     I         root (root is also an internal node, unless it is leaf)
   /   \
  I     I      internal nodes
 /     / \
o     o   o    external nodes (or leaves)


Full(strictly) Binary Tree : if Every node has zero or two children
           O
         /   \
        O     O
      /   \
     O     O
         /   \
        O     O
Complete Binary Tree
1) all levels is completely filled except the last level
2) all Nodes as left as possible in the last level
           O
         /   \
        O     O
      /   \
     O     O
This below binary trees is not complete binary tree
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

Perfect Binary tree
1) every node has two children except leaves
2) all leaves are at the same level

            O            
         /     \
        O       O
      /   \   /   \
     O     O O     O

Balanced Binary Tree
1) the height of tree = O(log2(n))
2) | height(left subtree) - height(right subtree) | <= 1   //   {1,0,-1}
          3 - 2 = (1)--> Balance Factor
           3O2          
         /     \
       2O1     2O1
      /   \   /   \
     O     O O     O
    /         \
   O           O
   
A degenerate (or Pathological) tree : every parent node has only one child eigher left or right
         O
          \
           O
            \
             O
              \
               O
               
            O           Max no. of nodes at level 0 = 1 = 2^0
         /     \
        O       O       Max no. of nodes at level 1 = 2 = 2^1
      /   \   /   \
     O     O O     O    Max no. of nodes at level 2 = 4 = 2^2
Max no. of nodes at level L = 2^L
Max no. of nodes in binary tree = 2^(h+1) - 1 (where h is height of tree)   //  as perfect tree

The number of paths or simple paths in the tree = n * (n-1) / 2
   O
 /   \
O     O 
       \
        O
```
