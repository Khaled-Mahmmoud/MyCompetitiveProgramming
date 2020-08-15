**Graphs** are mathematical structures that represent pairwise relationships between objects. 
It can be visualized by using the following two basic components:

**Nodes** : These are the most important components in any graph. Nodes are entities whose relationships are expressed using edges.
If a graph comprises 2 nodes A and B and an undirected edge between them, then it expresses a bi-directional relationship between them.

**Edges** : Edges are the components that are used to represent the relationships between various nodes in a graph.
An edge between two nodes expresses a one-way or two-way relationship between the nodes.

  O ==>> vertices , nodes , points
  
____ ==>> edges , arcs , lines


```
  4 ---> 6
  |
  v
  3 <----5
  
  V = {3,4,5,6}   E = { {4,6} , {4,3} , {5,3} }
```

Tree is special form of graph.

A tree is an undirected graph in which any two vertices are connected by only one path.

A tree is an acyclic graph and has N - 1 edges where N is the number of vertices. 

Each node in a graph may have one or multiple parent nodes. However, in a tree, each node (except the root node) comprises exactly one parent node.
A tree cannot contain any cycles or self loops, however.
  
### Types of nodes 

**Root node** : The root node is the ancestor of all other nodes in a graph. It does not have any ancestor.
Each graph consists of exactly one root node. Generally, you must start traversing a graph from the root node.

**Leaf nodes** : In a graph, leaf nodes represent the nodes that do not have any successors. 
These nodes only have ancestor nodes. They can have any number of incoming edges but they will not have any outgoing edges.

 ### Types of graph 


1) **Directed graph**  

A directed graph is a graph in which all the edges are uni-directional i.e. the edges point in a single direction.
A ---> B       E = { (A,B) }

2) **Undirected graph**  

An undirected graph is a graph in which all the edges are bi-directional i.e. the edges do not point in any specific direction.
A ---- B       E = { (A,B) , (B,A) }

3) **Weighted graph** 

In a weighted graph, each edge is assigned a weight or cost. Consider a graph of 4 nodes as in the diagram below.
As you can see each edge has a weight/cost assigned to it. If you want to go from vertex 1 to vertex 3, you can take one of the following 3 paths:
```
       1
   (1)----(2)
   |  \     |
 3 |   \ 1  | 2
   |     \  |
   (4)----(3)
       2
       
1 -> 2 -> 3
1 -> 3
1 -> 4 -> 3
```
Therefore the total cost of each path will be as follows: 

- The total cost of 1 -> 2 -> 3 will be (1 + 2) i.e. 3 units 

- The total cost of 1 -> 3 will be 1 unit - The total cost of 1 -> 4 -> 3 will be (3 + 2) i.e. 5 units

4) **Cyclic graph** 

A graph is cyclic if the graph comprises a path that starts from a vertex and ends at the same vertex. That path is called a cycle.

An acyclic graph is a graph that has no cycle.
```
     A ←-- D
     ↓     ↑
     B --→ C
     ↓
     E ←-- F
```    
A cycle in a directed graph is a path of at least 2 length such that the first vertax on the path is the same as last one
(if the path is simple , then cyclic is a simple cyclic)
```
                  A
                  ↑↓ 
                  B
```
A cycle in a undirected graph is a path of at least 3 length such that the first vertax on the path is the same as last one
```
                 A __ B
                 \   /
                   C
```
Loop at any node not present graph cycle

  
5) **Connected Graph**

( if from any node in graph , we can reach to all nodes)
```
     A ←-- D
     ↓     ↑
     B --→ C
```
6) **Disconnected Graph**

( if above condition is not met )
```
     A --→ D
     ↓     ↑
     B --→ C
     ↓
     E
```
7) **Null Graph**

A graph having no edges is called a Null Graph.

```
          A
     
     
   B             C
   
```
In the above graph, there are three vertices named ‘a’, ‘b’, and ‘c’, but there are no edges among them. Hence it is a Null Graph. 

8) **Trivial Graph**

A graph with only one vertex is called a Trivial Graph.
```
        A
```
In the above shown graph, there is only one vertex ‘a’ with no other edges. Hence it is a Trivial graph.

9) **Simple graph**

if graph doesn't contain any loop or parallel graph it's called Simple graph otherwise it's called not simple graph

**Complete graph** 

( if from any node in graph , we can reach to all nodes but path = 1)
```
                  A
               /  |  \
              B---|---C
               \  |  /
                  D 
```

Adjacent vertices(A) = {B,D} 

Adjacent vertices(C) = {D}

Adjacent edges(A,B)  = { (A,D) , (B,C) , (B,E) }  
```
         Loop                  A
  B ←-- A --→                 ↑↓ Parallel edges
        ↑ ← ↓                  B
```
Adjacent vertices(A) = {A,B}                    
            
```
                   A --→ B
                         ↓
                         C
```             
(A,C) is connected vertices
             
(C,A) is disconnectd vertices

                         
            
            
**A simple path** from v to w is a path from v to w with no repeated vertices, except that the first and last may be the same vertex.
```
                 A
                 ↓
           F ←-- B --→ C
                 ↑     ↓
                 E ←-- D
```
             Path : A , B , F is simple path
             
             Path : A , B , C , D , E , B , F is not simple path (repetition)
             
             Path : B , C , D , E , B is simple path

**indegree**

           indegree(D) = 1 (inEdges)
           
           indegree(B) = 2
           
           indegree(A) = 0

**outdegree**

           outdegree(A) = 1 (outEdges)
           
           outdegree(F) = 0
           
           outdegree(B) = 2
           
**incident edges**

           incident edges(A) = 1 (outEdges)
           
           incident edges(F) = 0
           
           incident edges(B) = 2
           
**degree**

           degree (D) = 2 ( inEdges + outEdges)
           
           degree (B) = 4
           
           degree (F) = 1           
           
```
           B ←-- A --→                 
                 ↑ ← ↓      degree(A) = 3
```        
        
        A --- B ---- C    
        
        number of edges at a undirected graph = 2
        
        number of edges at a directed graph = 4
        
        

         
         number of edges = E
         
         number of nodes = V
         
         E = V^2 the graph is dense
         
         E = V   the graph is sparse
