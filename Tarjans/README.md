In a graph, a vertex is called an articulation point if removing it and all the edges associated with it results in the increase of the number of connected components in the graph.

We use Tarjans Algorithm to find the articulation points of a graph.
The idea is to use DFS (Depth First Search). In DFS, we follow vertices in tree form called DFS tree. In DFS tree, a vertex u is parent of another vertex v, if v is discovered by u (obviously v is an adjacent of u in graph). In DFS tree, a vertex u is articulation point if one of the following two conditions is true.
1) u is root of DFS tree and it has at least two children.
2) u is not root of DFS tree and it has a child v such that no vertex in subtree rooted with v has a back edge to one of the ancestors (in DFS tree) of u.

isVisted[ ]:
For making sure, if we have visited a node(a vertex) and not running into an
infinite loop .

ap[ ]:
It is an int array to mark if a vertex is Cut-vertex (or Articulation Point)

parent[  ]:
It keeps the record of parent of each vertex

des[  ]:
It answers a simple question, when was a particular vertex " discovered" in the depth- first-search ?, which means it assigns a number to the the vertex in the order it is found in the dfs. 

low[  ]:
It answers yet another simple question, "what is lowest level vertex ,vertex x can climb to, in case its parent is removed from the graph"

How to run?
```
gcc Tarjans.c
./a.exe
```

Sample Input:
```
No. of vertices :4
No. of edges :3
Edge 1 :0 1
Edge 2 :1 2
Edge 3 :2 3
```
Sample Output:
```
Vertex 2
```