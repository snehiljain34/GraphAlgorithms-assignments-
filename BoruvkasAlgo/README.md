Boruvka's Algorithm is a minimum spanning tree algorithm.

What's a spanning tree?
In a graph, the path which covers all the nodes is called the spanning tree. 
If a graph contains n nodes, a spanning tree contains n-1 nodes which is a property of a tree.

What's a minimum spanning tree? 
A graph might contain lot of spanning trees, but the one which takes the minimum total weight to travel is called the minimum spanning tree

Boruvka's works in the following manner :

1) Input is a connected, weighted and un-directed graph.
2) All vertices are initialised as individual components (or sets).
3) Initialising MST as empty.
4) While there are more than one components, do following for each component.
      a)  Find the closest weight edge that connects this component to any other component.
      b)  Add this closest edge to MST if not already added.Add weight of edge to MST Weight.

How to run?
```
gcc BoruvkasAlgo.c
./a.exe
```
Sample Input:
```
Number of vertices: 5
Number of edges: 5
Graph with 5 Edges 5 Vertices
Enter vertex pairs with edge in between : Eg. (0 1 w) -> Edge between V0 and V1 with weight w
Edge 1  :0 3 6
Edge 2  :0 2 9
Edge 3  :2 3 4
Edge 4  :3 1 26
Edge 5  :3 4 20
```
Sample output:
```
MST construction
Edge 0-3 included in MST
Edge 3-1 included in MST
Edge 2-3 included in MST
Edge 3-4 included in MST
Number of components after iteration: 1
Weight of MST is 56
```