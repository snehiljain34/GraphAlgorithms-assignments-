Reverse Delete Algorithm is a minimum spanning tree algorithm.

What's a spanning tree?
In a graph, the path which covers all the nodes is called the spanning tree. 
If a graph contains n nodes, a spanning tree contains n-1 nodes which is a property of a tree.

What's a minimum spanning tree? 
A graph might contain lot of spanning trees, but the one which takes the minimum total weight to travel is called the minimum spanning tree

Reverse Delete Algorithm:
1) The edges are arranged in decreasing order of weight.
2) One by one , a check is performed to see if removal of highest weight edge among remaining edges causes graph to get disconnected.
This is done using DFS traversal of the graph.A visited array is maintained to keep a check on what vertices were trafersed by dfs.
3) If removal of edge causes vertices to be left unvisted on dfs traversal it means edge must be part of MST. In such a case edge is added back to MST.

How to run?
```
gcc ReverseDelete.c
./a.exe
```

Sample Input:
```
Number of vertices: 5
Number of edges: 7
Graph with 7 Edges 5 Vertices
Enter vertex pairs with edge in between : Eg. (0 1 w) -> Edge between V0 and V1 with weight w
Edge 1  :0 1 8
Edge 2  :0 2 5
Edge 3  :1 2 9
Edge 4  :1 3 11
Edge 5  :2 3 15
Edge 6  :2 4 10
Edge 7  :3 4 7
```
Sample output:
```
Edge (2 , 4) included in MST
Edge (0 , 1) included in MST
Edge (3 , 4) included in MST
Edge (0 , 2) included in MST
Weight of MST is 30
```